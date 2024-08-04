import pygame
from pygame.locals import *
import numpy as np
from OpenGL.GL import *
from OpenGL.GLU import *
from scipy.spatial.transform import Rotation as R
import threading
import time

# Height of the tetrahedron tip from the base plane
tip_height = 1.0

# Distance from the z-axis to the base vertices
base_radius = np.sqrt(2 / 3)

# Define the vertices of a tetrahedron
vertices = np.array([
    [0, 0, tip_height],  # Tip vertex
    [base_radius, 0, -1 / 3],  # Base vertex 1
    [-0.5 * base_radius, np.sqrt(3) / 2 * base_radius, -1 / 3],  # Base vertex 2
    [-0.5 * base_radius, -np.sqrt(3) / 2 * base_radius, -1 / 3]  # Base vertex 3
], dtype='float32')

# Function to derive the edges of a tetrahedron from its vertices
def derive_edges(vertices):
    num_vertices = len(vertices)
    edges = []
    for i in range(num_vertices):
        for j in range(i + 1, num_vertices):
            edges.append((i, j))
    return edges

# Derive edges from vertices
edges = derive_edges(vertices)

# Quaternion that will change over time
quaternion = np.array([1, 0, 0, 0], dtype='float32')

# # Function to update the quaternion in a background thread
# def update_quaternion():
#     global quaternion
#     while True:
#         angle = np.deg2rad(1)
#         axis = np.array([0, 1, 0])
#         delta_q = R.from_rotvec(axis * angle).as_quat()
#         current_rotation = R.from_quat(quaternion)
#         delta_rotation = R.from_quat(delta_q)
#         quaternion = (current_rotation * delta_rotation).as_quat()
#         time.sleep(0.05)

# # Start the quaternion update thread
# threading.Thread(target=update_quaternion, daemon=True).start()

# Initialize Pygame and set up the display
pygame.init()
display = (800, 600)
pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
gluPerspective(45, (display[0] / display[1]), 0.1, 50.0)
glTranslatef(0.0, 0.0, -5)

def draw_tetrahedron():
    glColor3f(1.0, 1.0, 1.0)  # Set the color to white
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()

def draw_coordinate_lines():
    glBegin(GL_LINES)
    # X axis in red
    glColor3f(1.0, 0.0, 0.0)
    glVertex3f(-10.0, 0.0, 0.0)
    glVertex3f(10.0, 0.0, 0.0)
    # Y axis in green
    glColor3f(0.0, 1.0, 0.0)
    glVertex3f(0.0, -10.0, 0.0)
    glVertex3f(0.0, 10.0, 0.0)
    # Z axis in blue
    glColor3f(0.0, 0.0, 1.0)
    glVertex3f(0.0, 0.0, -10.0)
    glVertex3f(0.0, 0.0, 10.0)
    glEnd()

# Main loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    
    # Apply the quaternion rotation
    rot = R.from_quat(quaternion).as_matrix()
    
    # Convert 3x3 rotation matrix to 4x4 matrix
    rot_4x4 = np.eye(4, dtype='float32')
    rot_4x4[:3, :3] = rot
    
    glPushMatrix()
    glMultMatrixf(rot_4x4.T)
    
    draw_tetrahedron()
    
    glPopMatrix()

    draw_coordinate_lines()
    
    pygame.display.flip()
    pygame.time.wait(10)

pygame.quit()
