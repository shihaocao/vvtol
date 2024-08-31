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
    // Step 1: Process the raw data
    const processedData: DataPoint[] = [];
    const timeSet = new Set<number>();

    data.forEach(series => {
        const field = series.fields.find((f: any) => f.name === '_value');
        const timeField = series.fields.find((f: any) => f.name === '_time');
        const valueType = series.fields.find((f: any) => f.name === '_field').values.toArray()[0];

        field.values.toArray().forEach((value: number, index: number) => {
        const time = new Date(timeField.values.toArray()[index]).getTime();
        timeSet.add(time);

        let existingPoint = processedData.find(p => p.time === time);
        if (!existingPoint) {
            existingPoint = { time, x: null, y: null, z: null };
            processedData.push(existingPoint);
        }

        existingPoint[valueType as keyof Coordinate] = value;
        });
    });

    // Step 2: Sort the processed data by time
    processedData.sort((a, b) => a.time - b.time);

    // Step 3: Interpolate missing values
    processedData.forEach((point, index) => {
        if (index === 0) {return;}
        const prevPoint = processedData[index - 1];
        ['x', 'y', 'z'].forEach(coord => {
        if (point[coord as keyof Coordinate] === null) {
            point[coord as keyof Coordinate] = prevPoint[coord as keyof Coordinate];
        }
        });
    });

    // Step 4: Sample the data
    const coordinates: Coordinate[] = [];
    const step = Math.max(1, Math.floor(processedData.length / numSamplePoints));

    for (let i = 0; i < processedData.length && coordinates.length < numSamplePoints; i += step) {
        const point = processedData[i];
        if (point.x !== null && point.y !== null && point.z !== null) {
        coordinates.push({ x: point.x, y: point.y, z: point.z });
        }
    }

    return coordinates;
}
  

// Function to draw vehicle trace with pastel colors
export function drawVehicleTrace(scene: THREE.Scene, coordinates: Coordinate[]): void {
  // Start with a pastel red and end with a pastel purple
  const startColor = new THREE.Color(0xFFB3B3); // Pastel Red
  const endColor = new THREE.Color(0xD1B3FF);   // Pastel Purple

  coordinates.forEach((coord, index) => {
    // Calculate the interpolation factor
    const t = index / (coordinates.length - 1);

    // Convert start and end colors to HSL
    const startHSL = { h: 0, s: 0, l: 0 };
    const endHSL = { h: 0, s: 0, l: 0 };
    startColor.getHSL(startHSL);
    endColor.getHSL(endHSL);

    // Interpolate across HSL
    const interpolatedHue = startHSL.h + t * (endHSL.h - startHSL.h);
    const interpolatedSaturation = startHSL.s + t * (endHSL.s - startHSL.s);
    const interpolatedLightness = startHSL.l + t * (endHSL.l - startHSL.l);

    // Convert interpolated HSL back to RGB
    const color = new THREE.Color();
    color.setHSL(interpolatedHue, interpolatedSaturation, interpolatedLightness);

    // Create Tetrahedron
    const tetraGeometry = new THREE.TetrahedronGeometry(1);
    const tetraMaterial = new THREE.MeshPhongMaterial({
      color: color,
      emissive: color.clone().multiplyScalar(0.3), // Adding a slight emissive effect
      shininess: 100,  // Higher shininess for more reflection
      specular: new THREE.Color(0xFFFFFF) // Specular highlights
    });
    const tetrahedron = new THREE.Mesh(tetraGeometry, tetraMaterial);

    // Position Tetrahedron
    tetrahedron.position.set(coord.x, coord.y, coord.z);

    // Add to scene
    scene.add(tetrahedron);
  });
}

// Function to generate coordinates between two points
export function generateCoordinates(start: Coordinate, end: Coordinate, n_points: number): Coordinate[] {
  const coordinates: Coordinate[] = [];

  for (let i = 0; i < n_points; i++) {
    const t = i / (n_points - 1); // Interpolation factor

    // Interpolate x, y, z coordinates
    const x = start.x + t * (end.x - start.x);
    const y = start.y + t * (end.y - start.y);
    const z = start.z + t * (end.z - start.z);

    // Add the interpolated coordinate to the list
    coordinates.push({ x: x, y: y, z: z });
  }

  return coordinates;
}
