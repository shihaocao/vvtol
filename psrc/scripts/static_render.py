import pygame
import numpy as np
import threading
import time
from scipy.spatial.transform import Rotation as R

# Initialize Pygame
pygame.init()

# Set up display
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('3D Quaternion Tetrahedron')

# Define the vertices of a tetrahedron
vertices = np.array([
    [1, 1, 1],
    [-1, -1, 1],
    [-1, 1, -1],
    [1, -1, -1]
])

# Define the edges of a tetrahedron
edges = [
    (0, 1), (0, 2), (0, 3),
    (1, 2), (1, 3), (2, 3)
]

# Quaternion that will change over time
quaternion = np.array([1, 0, 0, 0])

# Function to update the quaternion in a background thread
def update_quaternion():
    global quaternion
    while True:
        # Simulate quaternion change (for example purposes, this is random)
        angle = np.deg2rad(1)
        axis = np.array([0, 1, 0])
        delta_q = R.from_rotvec(axis * angle).as_quat()
        current_rotation = R.from_quat(quaternion)
        delta_rotation = R.from_quat(delta_q)
        quaternion = (current_rotation * delta_rotation).as_quat()
        time.sleep(0.05)

# Start the quaternion update thread
threading.Thread(target=update_quaternion, daemon=True).start()

def project(vertices, quaternion):
    # Apply the quaternion rotation to the vertices
    rot = R.from_quat(quaternion)
    rotated_vertices = rot.apply(vertices)
    
    # Project the 3D points to 2D points
    projected_vertices = []
    for vertex in rotated_vertices:
        x, y, z = vertex
        f = 200 / (z + 5)
        x, y = x * f, y * f
        projected_vertices.append((width // 2 + int(x), height // 2 - int(y)))
    return projected_vertices

# Main loop
running = True
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))

    # Project vertices to 2D
    projected_vertices = project(vertices, quaternion)

    # Draw edges
    for edge in edges:
        points = [projected_vertices[edge[0]], projected_vertices[edge[1]]]
        pygame.draw.line(screen, (255, 255, 255), points[0], points[1], 1)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
