import * as THREE from 'three';

interface Coordinate {
  x: number;
  y: number;
  z: number;
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
    const startHSL = startColor.getHSL({});
    const endHSL = endColor.getHSL({});

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
