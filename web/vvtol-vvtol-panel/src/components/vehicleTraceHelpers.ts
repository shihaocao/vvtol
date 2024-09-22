import * as THREE from 'three';

// Use array for flexible coordinate handling
type Coordinate = number[];  // [0]: x, [1]: y, [2]: z or quaternion

type DataPoint = {
    time: number;
    values: (number | null)[];
};

function interpolateMissingValues(processedData: DataPoint[]): void {
    processedData.forEach((point, index) => {
        if (index === 0) return;  // Skip the first point
        const prevPoint = processedData[index - 1];
        point.values.forEach((value, coordIndex) => {
            if (value === null) {
                point.values[coordIndex] = prevPoint.values[coordIndex];
            }
        });
    });
}

type ComplexDataPoint = {
    time: number;
    values: (number | null)[];  // Values array for [posX, posY, posZ, roll, pitch, yaw]
};

type ComplexCoordinate = {
    values: (number | null)[];  // Values array for [posX, posY, posZ, roll, pitch, yaw]
};

export function generateCoordinatesFromData(data: any[], numSamplePoints: number): ComplexDataPoint[] {
    console.error('Received data:', data);
    
    if (data.length < 6) {
        throw new Error('Expected six data series: three for position and three for orientation');
    }

    const processedPositionData: DataPoint[] = [];
    const processedOrientationData: DataPoint[] = [];

    // Process orientation series (assumed to be quaternions or angles)
    processSeries(data[0], processedOrientationData, 3); // rollx
    processSeries(data[1], processedOrientationData, 3); // pitchy
    processSeries(data[2], processedOrientationData, 3); // yawz

    // Process position series (x, y, z)
    processSeries(data[3], processedPositionData, 3); // posx
    processSeries(data[4], processedPositionData, 3); // posy
    processSeries(data[5], processedPositionData, 3); // posz
    
    // Sort both data lists by time
    processedPositionData.sort((a, b) => a.time - b.time);
    processedOrientationData.sort((a, b) => a.time - b.time);
    
    // Interpolate missing values
    interpolateMissingValues(processedPositionData);
    interpolateMissingValues(processedOrientationData);
    
    // Merge position and orientation data into ComplexDataPoints
    const complexDataPoints: ComplexDataPoint[] = mergePositionAndOrientation(processedPositionData, processedOrientationData);
    
    // Downsample
    const complexCoordinates = createComplexCoordinatesFromDataPoints(complexDataPoints, numSamplePoints);
    
    console.log('Generated complex coordinates:', complexCoordinates);
    return complexCoordinates;
}

function processSeries(series: any, dataPointsList: DataPoint[], expectedLength: number): void {
    const timeField = series.fields.find((f: any) => f.name === 'Time');
    
    if (!timeField) {
        console.warn('Time field not found in series. Available fields:', series.fields.map((f: any) => f.name));
        return;
    }

    const valueField = series.fields.find((f: any) => ['x', 'y', 'z'].includes(f.name));
    
    if (!valueField) {
        console.warn('No x, y, or z field found in series.');
        return;
    }

    valueField.values.forEach((value: number, idx: number) => {
        const time = new Date(timeField.values[idx]).getTime();
        let dataPoint = dataPointsList.find(p => p.time === time);
        
        if (!dataPoint) {
            dataPoint = { time, values: new Array(expectedLength).fill(null) };
            dataPointsList.push(dataPoint);
        }

        const coordIndex = valueField.name === 'x' ? 0 : valueField.name === 'y' ? 1 : 2;
        dataPoint.values[coordIndex] = value;
    });
}

function mergePositionAndOrientation(positionData: DataPoint[], orientationData: DataPoint[]): ComplexDataPoint[] {
    const complexDataPoints: ComplexDataPoint[] = [];
    
    positionData.forEach((positionPoint, idx) => {
        const orientationPoint = orientationData[idx];
        
        complexDataPoints.push({
            time: positionPoint.time,
            values: [
                ...(positionPoint.values as number[]),    // Position [x, y, z]
                ...(orientationPoint.values as number[])  // Orientation [roll, pitch, yaw] or quaternion
            ]
        });
    });
    
    return complexDataPoints;
}

function createComplexCoordinatesFromDataPoints(complexDataPoints: ComplexDataPoint[], numSamplePoints: number): ComplexCoordinate[] {
    const complexCoordinates: ComplexCoordinate[] = [];
    const step = Math.max(1, Math.floor(complexDataPoints.length / numSamplePoints));
    
    for (let i = 0; i < complexDataPoints.length && complexCoordinates.length < numSamplePoints; i += step) {
        const point = complexDataPoints[i];
        if (point.values.every(value => value !== null)) {
            complexCoordinates.push({
                values: point.values as number[]
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
    const hDim = 1.0;
    const topHeight = hDim;
    const baseHeight = -hDim;
    const baseRadius = hDim / 3;

    // Extract position and orientation values from the array
    const x = coord.values[0];
    const y = coord.values[1];
    const z = coord.values[2];
    const roll = coord.values[3];
    const pitch = coord.values[4];
    const yaw = coord.values[5];

    // Local vertices in the object’s local space (no translation applied yet)
    let v0 = new THREE.Vector3(0, topHeight, 0);
    let v1 = new THREE.Vector3(baseRadius * Math.cos(0), baseHeight, baseRadius * Math.sin(0));
    let v2 = new THREE.Vector3(baseRadius * Math.cos((2 * Math.PI) / 3), baseHeight, baseRadius * Math.sin((2 * Math.PI) / 3));
    let v3 = new THREE.Vector3(baseRadius * Math.cos((4 * Math.PI) / 3), baseHeight, baseRadius * Math.sin((4 * Math.PI) / 3));

    // Convert roll, pitch, yaw from degrees to radians
    const rollInRadians = roll * (Math.PI / 180);
    const pitchInRadians = pitch * (Math.PI / 180);
    const yawInRadians = yaw * (Math.PI / 180);

    // Create quaternion from Euler angles (rotation first)
    const quaternion = new THREE.Quaternion();
    quaternion.setFromEuler(new THREE.Euler(pitchInRadians, yawInRadians, rollInRadians, 'XYZ'));

    // Apply the rotation to the local vertices
    v0.applyQuaternion(quaternion);
    v1.applyQuaternion(quaternion);
    v2.applyQuaternion(quaternion);
    v3.applyQuaternion(quaternion);

    // After rotation, apply the translation (x, y, z) to each vertex
    v0.add(new THREE.Vector3(x, y, z));
    v1.add(new THREE.Vector3(x, y, z));
    v2.add(new THREE.Vector3(x, y, z));
    v3.add(new THREE.Vector3(x, y, z));

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