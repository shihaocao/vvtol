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

export function generateCoordinatesFromData(data: any[], numSamplePoints: number): ComplexCoordinate[] {
    console.error('Received data:', data);
    
    if (data.length < 7) {
        throw new Error('Expected six data series: three for position and three for orientation');
    }

    const processedPositionData: DataPoint[] = [];
    const processedOrientationData: DataPoint[] = [];

    // Process orientation series (assumed to be quaternions or angles)
    process4Series(data[0], processedOrientationData); // w
    process4Series(data[1], processedOrientationData); // x
    process4Series(data[2], processedOrientationData); // y
    process4Series(data[3], processedOrientationData); // z

    // Process position series (x, y, z)
    process3Series(data[4], processedPositionData); // posx
    process3Series(data[5], processedPositionData); // posy
    process3Series(data[6], processedPositionData); // posz
    
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
    
    console.error('Generated complex coordinates:', complexCoordinates);
    return complexCoordinates;
}

function process3Series(series: any, dataPointsList: DataPoint[]): void {
    const timeField = series.fields.find((f: any) => f.name === 'Time');
    
    if (!timeField) {
        console.warn('Time field not found in series. Available fields:', series.fields.map((f: any) => f.name));
        return;
    }

    // Define a mapping for 3-component vectors (position)
    const fieldIndexMap: { [key: string]: number } = {
        'x': 0,
        'y': 1,
        'z': 2
    };

    series.fields.forEach((field: any) => {
        if (!['x', 'y', 'z'].includes(field.name)) return;

        field.values.forEach((value: number, idx: number) => {
            const time = new Date(timeField.values[idx]).getTime();
            let dataPoint = dataPointsList.find(p => p.time === time);
            
            if (!dataPoint) {
                dataPoint = { time, values: new Array(3).fill(null) };
                dataPointsList.push(dataPoint);
            }

            // Use the dictionary to get the correct index for the field name
            const coordIndex = fieldIndexMap[field.name];
            dataPoint.values[coordIndex] = value;
        });
    });
}

function process4Series(series: any, dataPointsList: DataPoint[]): void {
    const timeField = series.fields.find((f: any) => f.name === 'Time');
    
    if (!timeField) {
        console.warn('Time field not found in series. Available fields:', series.fields.map((f: any) => f.name));
        return;
    }

    // Define a mapping for 4-component quaternions (orientation)
    const fieldIndexMap: { [key: string]: number } = {
        'w': 0,
        'x': 1,
        'y': 2,
        'z': 3
    };

    series.fields.forEach((field: any) => {
        if (!['w', 'x', 'y', 'z'].includes(field.name)) return;

        field.values.forEach((value: number, idx: number) => {
            const time = new Date(timeField.values[idx]).getTime();
            let dataPoint = dataPointsList.find(p => p.time === time);
            
            if (!dataPoint) {
                dataPoint = { time, values: new Array(4).fill(null) };
                dataPointsList.push(dataPoint);
            }

            // Use the dictionary to get the correct index for the quaternion field
            const coordIndex = fieldIndexMap[field.name];
            dataPoint.values[coordIndex] = value;
        });
    });
}

function mergePositionAndOrientation(positionData: DataPoint[], orientationData: DataPoint[]): ComplexDataPoint[] {
    const complexDataPoints: ComplexDataPoint[] = [];
    console.error('pos data:', positionData);
    console.error('orien data:', orientationData);

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
    console.error('Generated merged post and orientation:', complexDataPoints);

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

    console.error('Gemerated complex coords from data points', complexCoordinates);

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

    // Extract position and quaternion orientation values from the array
    const x = coord.values[0]; // position x
    const y = coord.values[1]; // position y
    const z = coord.values[2]; // position z

    const w = coord.values[3]; // quaternion w
    const qx = coord.values[4]; // quaternion x
    const qy = coord.values[5]; // quaternion y
    const qz = coord.values[6]; // quaternion z

    // Local vertices in the object’s local space (no translation applied yet)
    let v0 = new THREE.Vector3(0, topHeight, 0);
    let v1 = new THREE.Vector3(baseRadius * Math.cos(0), baseHeight, baseRadius * Math.sin(0));
    let v2 = new THREE.Vector3(baseRadius * Math.cos((2 * Math.PI) / 3), baseHeight, baseRadius * Math.sin((2 * Math.PI) / 3));
    let v3 = new THREE.Vector3(baseRadius * Math.cos((4 * Math.PI) / 3), baseHeight, baseRadius * Math.sin((4 * Math.PI) / 3));

    // Create quaternion from the given w, x, y, z (rotation first)
    const quaternion = new THREE.Quaternion(qx, qy, qz, w);
    quaternion.normalize();

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