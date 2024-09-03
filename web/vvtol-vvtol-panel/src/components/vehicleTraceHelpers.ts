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

export function generateCoordinatesFromData(data: any[], numSamplePoints: number): Coordinate[] {
    console.log('Received data:', data);
    
    const processedData: DataPoint[] = [];
    
    data.forEach((series, index) => {
        console.log(`Processing series ${index}:`, series);
        
        const timeField = series.fields.find((f: any) => f.name === 'Time');
        const valueField = series.fields.find((f: any) => f.name === 'x' || f.name === 'y' || f.name === 'z');
        
        if (!timeField || !valueField) {
            console.warn(`Required fields not found in series ${index}. Available fields:`, series.fields.map((f: any) => f.name));
            return;
        }
        
        const fieldName = valueField.name;
        console.log(`Processing field: ${fieldName}`);
        
        valueField.values.forEach((value: number, idx: number) => {
            const time = new Date(timeField.values[idx]).getTime();
            
            let existingPoint = processedData.find(p => p.time === time);
            if (!existingPoint) {
                existingPoint = { time, x: null, y: null, z: null };
                processedData.push(existingPoint);
            }
            
            existingPoint[fieldName as keyof Coordinate] = value;
        });
    });
    
    processedData.sort((a, b) => a.time - b.time);
    
    // Interpolate missing values
    processedData.forEach((point, index) => {
        if (index === 0) return;
        const prevPoint = processedData[index - 1];
        ['x', 'y', 'z'].forEach(coord => {
            if (point[coord as keyof Coordinate] === null) {
                point[coord as keyof Coordinate] = prevPoint[coord as keyof Coordinate];
            }
        });
    });
    
    const coordinates: Coordinate[] = [];
    const step = Math.max(1, Math.floor(processedData.length / numSamplePoints));
    
    for (let i = 0; i < processedData.length && coordinates.length < numSamplePoints; i += step) {
        const point = processedData[i];
        if (point.x !== null && point.y !== null && point.z !== null) {
            coordinates.push({ x: point.x, y: point.y, z: point.z });
        }
    }
    
    console.log('Generated coordinates:', coordinates);
    return coordinates;
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

function generateTetrahedronGeometry(coord: Coordinate): number[] {
    const topHeight = 0.5;
    const baseHeight = -0.5;
    const baseRadius = 0.3;

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

export function createVehicleTraceObjects(coordinates: Coordinate[]): THREE.Object3D[] {
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