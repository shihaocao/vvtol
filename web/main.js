// Import Three.js and OrbitControls
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';

// Initialize Scene, Camera, and Renderer
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x000000); // Black background

const camera = new THREE.PerspectiveCamera(
  75, // Field of view
  window.innerWidth / window.innerHeight, // Aspect ratio
  0.1, // Near clipping plane
  1000 // Far clipping plane
);
camera.position.set(10, 10, 10);

const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Add OrbitControls
const controls = new OrbitControls(camera, renderer.domElement);
controls.enableDamping = true; // Smooth controls
controls.dampingFactor = 0.05;

// Add Ambient Light
const ambientLight = new THREE.AmbientLight(0x777777); // Soft white light
scene.add(ambientLight);

// Add Point Light
const pointLight = new THREE.PointLight(0xffffff, 1.5);
pointLight.position.set(5, 5, 5);
scene.add(pointLight);

// Function to draw vehicle trace with pastel colors
function drawVehicleTrace(coordinates) {
    // Start with a pastel red and end with a pastel purple
    const startColor = new THREE.Color(0xFFB3B3); // Pastel Red
    const endColor = new THREE.Color(0xD1B3FF);   // Pastel Purple
  
    coordinates.forEach((coord, index) => {
      // Calculate the interpolation factor
      const t = index / (coordinates.length - 1);
  
      // Convert start and end colors to HSV
      const startHSV = startColor.getHSL({});
      const endHSV = endColor.getHSL({});
  
      // Interpolate across HSV
      const interpolatedHue = startHSV.h + t * (endHSV.h - startHSV.h);
      const interpolatedSaturation = startHSV.s + t * (endHSV.s - startHSV.s);
      const interpolatedLightness = startHSV.l + t * (endHSV.l - startHSV.l);
  
      // Convert interpolated HSV back to RGB
      const color = new THREE.Color();
      color.setHSL(interpolatedHue, interpolatedSaturation, interpolatedLightness);
  
      // Create Tetrahedron
      const tetraGeometry = new THREE.TetrahedronGeometry(1);
      // Adjusted material properties
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

  function generateCoordinates(start, end, n_points) {
    const coordinates = [];
  
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
  
// Example usage: Generate 10 coordinates from (0, 0, 0) to (18, 9, 9)
const startCoord = { x: 0, y: 0, z: 0 };
const endCoord = { x: 1, y: 9, z: 9 };
const n_points = 10;
  
const coordinates = generateCoordinates(startCoord, endCoord, n_points);
  
drawVehicleTrace(coordinates);
  

// Define Color Palette
const ColorPalette = {
  LightRed: 0xFFB6C1,
  LightGreen: 0x90EE90,
  LightBlue: 0x87CEFA,
  White: 0xFFFFFF
};

// Function to create axes with graduations and labels
function createAxes(options) {
  const { length, graduationStep} = options;

  // Helper function to create a single axis
  function createAxis(axis, color) {
    const axisGroup = new THREE.Group();

    // Main Axis Line
    const mainAxisGeometry = new THREE.BufferGeometry().setFromPoints([
      new THREE.Vector3(-length, 0, 0),
      new THREE.Vector3(length, 0, 0)
    ]);
    const mainAxisMaterial = new THREE.LineBasicMaterial({ color, linewidth: 2 });
    const mainAxis = new THREE.Line(mainAxisGeometry, mainAxisMaterial);
    if (axis === 'y') mainAxis.rotation.z = Math.PI / 2;
    if (axis === 'z') mainAxis.rotation.y = -Math.PI / 2;
    axisGroup.add(mainAxis);

    // Graduations and Labels
    for (let i = -length; i <= length; i += graduationStep) {
      if (i === 0) continue; // Skip origin

      // Tick Marks
      const tickSize = 0.2;
      const tickGeometry = new THREE.BufferGeometry().setFromPoints([
        new THREE.Vector3(i, -tickSize, 0),
        new THREE.Vector3(i, tickSize, 0)
      ]);
      const tickMaterial = new THREE.LineBasicMaterial({ color });
      const tick = new THREE.Line(tickGeometry, tickMaterial);
      if (axis === 'y') tick.rotation.z = Math.PI / 2;
      if (axis === 'z') tick.rotation.y = -Math.PI / 2;
      axisGroup.add(tick);
    }
    return axisGroup;
  }

  // Helper function to create text labels
  function createTextLabel(text, color) {
    const loader = new THREE.FontLoader();
    const fontSize = 0.5;
    const fontHeight = 0.05;
    const labelGroup = new THREE.Group();

    loader.load('https://threejs.org/examples/fonts/helvetiker_regular.typeface.json', function (font) {
      const textGeometry = new THREE.TextGeometry(text, {
        font: font,
        size: fontSize,
        height: fontHeight,
        curveSegments: 12
      });
      const textMaterial = new THREE.MeshBasicMaterial({ color });
      const mesh = new THREE.Mesh(textGeometry, textMaterial);
      mesh.geometry.computeBoundingBox();
      const boundingBox = mesh.geometry.boundingBox;
      const textWidth = boundingBox.max.x - boundingBox.min.x;
      mesh.position.x = -textWidth / 2; // Center align
      labelGroup.add(mesh);
    });
    return labelGroup;
  }

  // Create and add all axes
  const axesGroup = new THREE.Group();
  const xAxis = createAxis('x', ColorPalette.LightRed);
  const yAxis = createAxis('y', ColorPalette.LightGreen);
  const zAxis = createAxis('z', ColorPalette.LightBlue);

  axesGroup.add(xAxis);
  axesGroup.add(yAxis);
  axesGroup.add(zAxis);

  scene.add(axesGroup);
}

// Create Axes with specified options
createAxes({
  length: 20,
  graduationStep: 2,
  labelInterval: 5
});

// Handle Window Resize
window.addEventListener('resize', function () {
  const width = window.innerWidth;
  const height = window.innerHeight;
  renderer.setSize(width, height);
  camera.aspect = width / height;
  camera.updateProjectionMatrix();
});

// Animation Loop
function animate() {
  requestAnimationFrame(animate);
  controls.update();
  renderer.render(scene, camera);
}
animate();
