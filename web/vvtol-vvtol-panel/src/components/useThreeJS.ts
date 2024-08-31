import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { createAxes } from './axesHelpers'; // Import the createAxes function

export const setupThreeJS = (
  canvas: HTMLCanvasElement,
  width: number,
  height: number,
  primaryColor: string
): THREE.Scene => {
  const scene = new THREE.Scene();
  scene.background = new THREE.Color(0x000000); // Black background

  const camera = new THREE.PerspectiveCamera(75, width / height, 0.1, 1000);
  camera.position.z = 5;

  const renderer = new THREE.WebGLRenderer({ canvas, antialias: true });
  renderer.setSize(width, height);

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

  // Create a sphere
  const geometry = new THREE.SphereGeometry(1, 32, 32);
  const material = new THREE.MeshPhongMaterial({ color: primaryColor }); // Use MeshPhongMaterial to respond to lighting
  const sphere = new THREE.Mesh(geometry, material);
  scene.add(sphere);

  // Create Axes with specified options
  createAxes(scene, {
    length: 20,
    graduationStep: 2,
  });

  // Animation loop
  const animate = (): void => {
    requestAnimationFrame(animate);
    sphere.rotation.x += 0.01;
    sphere.rotation.y += 0.01;
    controls.update(); // Update controls
    renderer.render(scene, camera);
  };
  animate();

  return scene;
};
