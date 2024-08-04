import numpy as np
import threading
import time
from vispy import app, scene
from vispy.scene import visuals
from scipy.spatial.transform import Rotation as R

# Define the vertices of a tetrahedron
initial_vertices = np.array([
    [0, 0, 1],  # Tip vertex
    [np.sqrt(2 / 3), 0, -1 / 3],  # Base vertex 1
    [-0.5 * np.sqrt(2 / 3), np.sqrt(3) / 2 * np.sqrt(2 / 3), -1 / 3],  # Base vertex 2
    [-0.5 * np.sqrt(2 / 3), -np.sqrt(3) / 2 * np.sqrt(2 / 3), -1 / 3]  # Base vertex 3
], dtype='float32')

# Define the edges of a tetrahedron
edges = np.array([
    [0, 1], [0, 2], [0, 3],
    [1, 2], [1, 3], [2, 3]
], dtype='int32')

# Create a canvas with a 3D viewport
canvas = scene.SceneCanvas(keys='interactive', show=True)
view = canvas.central_widget.add_view()
view.camera = 'arcball'  # or try 'turntable'

# Add the tetrahedron to the scene
tetrahedron = visuals.Line(pos=initial_vertices, connect=edges, color='white', method='gl', parent=view.scene)

# Add coordinate axes
axis_length = 2.0
x_axis = visuals.Arrow(pos=np.array([[0, 0, 0], [axis_length, 0, 0]]), color='red', arrow_size=0.1, parent=view.scene)
y_axis = visuals.Arrow(pos=np.array([[0, 0, 0], [0, axis_length, 0]]), color='green', arrow_size=0.1, parent=view.scene)
z_axis = visuals.Arrow(pos=np.array([[0, 0, 0], [0, 0, axis_length]]), color='blue', arrow_size=0.1, parent=view.scene)

# Global variable to hold the current vertices
vertices = initial_vertices.copy()

# Function to rotate the tetrahedron
def rotate_tetrahedron(event):
    global vertices
    angle = np.deg2rad(1)
    axis = np.array([0, 1, 0])
    delta_rot = R.from_rotvec(axis * angle)
    rotation_matrix = delta_rot.as_matrix()

    # Rotate vertices
    vertices = (rotation_matrix @ initial_vertices.T).T

    # Update tetrahedron vertices
    tetrahedron.set_data(pos=vertices)

# Create a timer to update the rotation
timer = app.Timer(interval=0.05, connect=rotate_tetrahedron, start=True)

# Run the application
if __name__ == '__main__':
    app.run()
