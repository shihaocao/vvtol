import * as THREE from 'three';

interface Coordinate {
    x: number;
    y: number;
    z: number;
}

interface DataPoint {
    time: number;
    x: number | null;
    y: number | null;
    z: number | null;
}

function interpolateMissingValues(processedData: DataPoint[]): void {
    processedData.forEach((point, index) => {
        if (index === 0) return;  // Skip the first point
        const prevPoint = processedData[index - 1];
        ['x', 'y', 'z'].forEach(coord => {
            if (point[coord as keyof Coordinate] === null) {
                point[coord as keyof Coordinate] = prevPoint[coord as keyof Coordinate];
            }
        });
    });
}

interface ComplexDataPoint {
    time: number;
    x: number | null;
    y: number | null;
    z: number | null;
    roll: number | null;
    pitch: number | null;
    yaw: number | null;
}

interface ComplexCoordinate {
    x: number;
    y: number;
    z: number;
    roll: number;
    pitch: number;
    yaw: number;
}
export function generateCoordinatesFromData(data: any[], numSamplePoints: number): ComplexCoordinate[] {
    console.error('Received data:', data);
    
    if (data.length < 6) {
        throw new Error('Expected six data series: three for position and three for orientation');
    }

    // Initialize empty lists for position and orientation DataPoints
    const processedPositionData: DataPoint[] = [];
    const processedOrientationData: DataPoint[] = [];

    // Process position series (x, y, z)
    processSeries(data[0], processedPositionData); // posx
    processSeries(data[1], processedPositionData); // posy
    processSeries(data[2], processedPositionData); // posz

    // Process orientation series (roll, pitch, yaw)
    processSeries(data[3], processedOrientationData); // rollx
    processSeries(data[4], processedOrientationData); // pitchy
    processSeries(data[5], processedOrientationData); // yawz
    
    // Sort both data lists by time
    processedPositionData.sort((a, b) => a.time - b.time);
    processedOrientationData.sort((a, b) => a.time - b.time);
    
    // Interpolate missing values
    interpolateMissingValues(processedPositionData);
    interpolateMissingValues(processedOrientationData);
    
    // Merge position and orientation data into ComplexDataPoints
    const complexDataPoints: ComplexDataPoint[] = mergePositionAndOrientation(processedPositionData, processedOrientationData);
    
    // Downsample and convert to ComplexCoordinates
    const complexCoordinates = createComplexCoordinatesFromDataPoints(complexDataPoints, numSamplePoints);
    
    console.log('Generated complex coordinates:', complexCoordinates);
    return complexCoordinates;
}

// Updated processSeries function to add data to the provided DataPoint list
function processSeries(series: any, dataPointsList: DataPoint[]): void {
    const timeField = series.fields.find((f: any) => f.name === 'Time');
    
    if (!timeField) {
        console.warn('Time field not found in series. Available fields:', series.fields.map((f: any) => f.name));
        return;
    }

    const valueField = series.fields.find((f: any) => f.name === 'x' || f.name === 'y' || f.name === 'z');
    
    if (!valueField) {
        console.warn('No x, y, or z field found in series.');
        return;
    }

    valueField.values.forEach((value: number, idx: number) => {
        const time = new Date(timeField.values[idx]).getTime();
        let dataPoint = dataPointsList.find(p => p.time === time);
        
        if (!dataPoint) {
            dataPoint = { time, x: null, y: null, z: null };
            dataPointsList.push(dataPoint);
        }

        // Assign the correct field (x, y, or z) based on the valueField name
        dataPoint[valueField.name as keyof Coordinate] = value;
    });
}

function mergePositionAndOrientation(positionData: DataPoint[], orientationData: DataPoint[]): ComplexDataPoint[] {
    const complexDataPoints: ComplexDataPoint[] = [];
    
    positionData.forEach((positionPoint, idx) => {
        const orientationPoint = orientationData[idx];
        
        complexDataPoints.push({
            time: positionPoint.time,
            x: positionPoint.x,
            y: positionPoint.y,
            z: positionPoint.z,
            roll: orientationPoint.x,  // roll packed into x
            pitch: orientationPoint.y, // pitch packed into y
            yaw: orientationPoint.z    // yaw packed into z
        });
    });
    
    return complexDataPoints;
}

function createComplexCoordinatesFromDataPoints(complexDataPoints: ComplexDataPoint[], numSamplePoints: number): ComplexCoordinate[] {
    const complexCoordinates: ComplexCoordinate[] = [];
    const step = Math.max(1, Math.floor(complexDataPoints.length / numSamplePoints));
    
    for (let i = 0; i < complexDataPoints.length && complexCoordinates.length < numSamplePoints; i += step) {
        const point = complexDataPoints[i];
        if (point.x !== null && point.y !== null && point.z !== null && point.roll !== null && point.pitch !== null && point.yaw !== null) {
            complexCoordinates.push({
                x: point.x,
                y: point.y,
                z: point.z,
                roll: point.roll,
                pitch: point.pitch,
                yaw: point.yaw
            });
        }
    }

    return complexCoordinates;
}


function generateColor(index: number, totalPoints: number): THREE.Color {
    const startColor = new THREE.Color(0xFFB3B3);
    const endColor = new THREE.Color(0xD1B3FF);
    
    const startHSL = { h: 0, s: 0, l: 0 };
    const endHSL = { h: 0, s: 0, l: 0 };
    startColor.getHSL(startHSL);
    endColor.getHSL(endHSL);

    const t = index / (totalPoints - 1);
    
    const interpolatedHue = startHSL.h + t * (endHSL.h - startHSL.h);
    const interpolatedSaturation = startHSL.s + t * (endHSL.s - startHSL.s);
    const interpolatedLightness = startHSL.l + t * (endHSL.l - startHSL.l);
    
    return new THREE.Color().setHSL(interpolatedHue, interpolatedSaturation, interpolatedLightness);
}

function generateTetrahedronGeometry(coord: ComplexCoordinate): number[] {
    const hDim = 1.0
    const topHeight = hDim;
    const baseHeight = -hDim;
    const baseRadius = hDim / 3;

    // Top vertex
    const v0 = new THREE.Vector3(coord.x, coord.y + topHeight, coord.z);

    // Base vertices
    const v1 = new THREE.Vector3(
        coord.x + baseRadius * Math.cos(0),
        coord.y + baseHeight,
        coord.z + baseRadius * Math.sin(0)
    );
    const v2 = new THREE.Vector3(
        coord.x + baseRadius * Math.cos(2 * Math.PI / 3),
        coord.y + baseHeight,
        coord.z + baseRadius * Math.sin(2 * Math.PI / 3)
    );
    const v3 = new THREE.Vector3(
        coord.x + baseRadius * Math.cos(4 * Math.PI / 3),
        coord.y + baseHeight,
        coord.z + baseRadius * Math.sin(4 * Math.PI / 3)
    );

    return [
        // Edges from top to base
        v0.x, v0.y, v0.z, v1.x, v1.y, v1.z,
        v0.x, v0.y, v0.z, v2.x, v2.y, v2.z,
        v0.x, v0.y, v0.z, v3.x, v3.y, v3.z,
        // Base edges
        v1.x, v1.y, v1.z, v2.x, v2.y, v2.z,
        v2.x, v2.y, v2.z, v3.x, v3.y, v3.z,
        v3.x, v3.y, v3.z, v1.x, v1.y, v1.z
    ];
}

export function createVehicleTraceObjects(coordinates: ComplexCoordinate[]): THREE.Object3D[] {
    if (!Array.isArray(coordinates)) {
        console.error('Invalid coordinates:', coordinates);
        return [];
    }
    
    const geometry = new THREE.BufferGeometry();
    const vertices: number[] = [];
    const colors: number[] = [];

    coordinates.forEach((coord, index) => {
        const color = generateColor(index, coordinates.length);
        const tetrahedronVertices = generateTetrahedronGeometry(coord);
        
        vertices.push(...tetrahedronVertices);

        // Add colors for each vertex (2 vertices per edge, 6 edges)
        for (let i = 0; i < 12; i++) {
            colors.push(color.r, color.g, color.b);
        }
    });

    geometry.setAttribute('position', new THREE.Float32BufferAttribute(vertices, 3));
    geometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 3));

    const material = new THREE.LineBasicMaterial({
        vertexColors: true,
        linewidth: 1
    });

    const lineSegments = new THREE.LineSegments(geometry, material);

    return [lineSegments];
}