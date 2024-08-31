import * as THREE from 'three';

// Define a type for the options used in the createAxes function
interface AxesOptions {
  length: number;
  graduationStep: number;
}

// Define a color palette
const ColorPalette = {
  LightRed: 0xffb6c1,
  LightGreen: 0x90ee90,
  LightBlue: 0x87cefa,
  White: 0xffffff,
};

// Function to create axes with graduations and labels
export function createAxes(scene: THREE.Scene, options: AxesOptions): void {
  const { length, graduationStep } = options;

  // Helper function to create a single axis
  function createAxis(axis: 'x' | 'y' | 'z', color: number): THREE.Group {
    const axisGroup = new THREE.Group();

    // Main Axis Line
    const mainAxisGeometry = new THREE.BufferGeometry().setFromPoints([
      new THREE.Vector3(-length, 0, 0),
      new THREE.Vector3(length, 0, 0),
    ]);
    const mainAxisMaterial = new THREE.LineBasicMaterial({ color, linewidth: 2 });
    const mainAxis = new THREE.Line(mainAxisGeometry, mainAxisMaterial);

    if (axis === 'y') {
      mainAxis.rotation.z = Math.PI / 2;
    }
    if (axis === 'z') {
      mainAxis.rotation.y = -Math.PI / 2;
    }

    axisGroup.add(mainAxis);

    // Graduations and Labels
    for (let i = -length; i <= length; i += graduationStep) {
      if (i === 0) {
        continue; // Skip origin
      }

      // Tick Marks
      const tickSize = 0.2;
      const tickGeometry = new THREE.BufferGeometry().setFromPoints([
        new THREE.Vector3(i, -tickSize, 0),
        new THREE.Vector3(i, tickSize, 0),
      ]);
      const tickMaterial = new THREE.LineBasicMaterial({ color });
      const tick = new THREE.Line(tickGeometry, tickMaterial);

      if (axis === 'y') {
        tick.rotation.z = Math.PI / 2;
      }
      if (axis === 'z') {
        tick.rotation.y = -Math.PI / 2;
      }

      axisGroup.add(tick);
    }
    return axisGroup;
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
