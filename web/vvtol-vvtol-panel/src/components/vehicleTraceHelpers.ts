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

export function createVehicleTraceObjects(coordinates: Coordinate[]): THREE.Object3D[] {
    if (!Array.isArray(coordinates)) {
        console.error('Invalid coordinates:', coordinates);
        return [];
    }
    
    const startColor = new THREE.Color(0xFFB3B3);
    const endColor = new THREE.Color(0xD1B3FF);
    
    return coordinates.map((coord, index) => {
        const t = index / (coordinates.length - 1);
        
        const startHSL = { h: 0, s: 0, l: 0 };
        const endHSL = { h: 0, s: 0, l: 0 };
        startColor.getHSL(startHSL);
        endColor.getHSL(endHSL);
        
        const interpolatedHue = startHSL.h + t * (endHSL.h - startHSL.h);
        const interpolatedSaturation = startHSL.s + t * (endHSL.s - startHSL.s);
        const interpolatedLightness = startHSL.l + t * (endHSL.l - startHSL.l);
        
        const color = new THREE.Color().setHSL(interpolatedHue, interpolatedSaturation, interpolatedLightness);
        
        const tetraGeometry = new THREE.TetrahedronGeometry(1);
        const tetraMaterial = new THREE.MeshPhongMaterial({
            color: color,
            emissive: color.clone().multiplyScalar(0.3),
            shininess: 100,
            specular: new THREE.Color(0xFFFFFF)
        });
        const tetrahedron = new THREE.Mesh(tetraGeometry, tetraMaterial);
        
        tetrahedron.position.set(coord.x, coord.y, coord.z);
        
        return tetrahedron;
    });
}