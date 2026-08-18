*This project has been created as part of the 42 curriculum by [najlghar](https://profile-v3.intra.42.fr/users/najlghar), [lanton-m](https://profile-v3.intra.42.fr/users/lanton-m).*

# Cub3D

## Description

**Cub3D** is a project from the 42 curriculum inspired by the world-famous 90s game Wolfenstein 3D. The goal of this project is to create a dynamic 3D maze view using raycasting, exploring the fundamentals of computer graphics, geometry, and real-time rendering.

The player moves inside a 2D map projected into a first-person perspective, with textured walls, floor and ceiling colors, and camera rotation.

## Features

- **Raycasting Engine**: 3D perspective rendering from a 2D map.
- **Texture Loading**: Wall textures loaded from XPM files for the four directions.
- **Map Parsing**: Validation of the configuration header and map layout.
- **Color Parsing**: Floor and ceiling colors parsed from RGB values.
- **Movement and Rotation**: Player movement with W, A, S, D and camera rotation with left/right arrows.
- **Window Handling**: Event processing and safe exit using ESC or the window close button.
- **Memory Cleanup**: Basic cleanup of allocated resources and images.

## Instructions

### Compilation

To compile the project, use the provided Makefile:

- `make` or `make all`: compiles the project and creates the executable.
- `make clean`: removes object files.
- `make fclean`: removes objects and the executable.
- `make re`: rebuilds the project from scratch.

### Execution

Run the game with a valid `.cub` map as an argument:

```bash
./cub3d rscs/maps/valids/map_pruebas.cub
```

#### Valid Maps

The map file must always have the `.cub` extension and contain two main sections:

1. The configuration header:
   - `NO`, `SO`, `WE`, `EA` for wall textures
   - `F` and `C` for floor and ceiling colors
2. The map grid:
   - `1` = wall
   - `0` = empty space
   - `N`, `S`, `E`, `W` = player start position and facing direction

Rules:
- The map must be fully enclosed by walls.
- There must be exactly one player start position.
- Invalid characters are rejected.
- Texture paths and RGB values must be valid.

Example:

```text
F 120,102,71
C 255,255,255
NO ./rscs/textures/Nay_no.xpm
SO ./rscs/textures/Empty_so.xpm
WE ./rscs/textures/Luis_we.xpm
EA ./rscs/textures/together_ea.xpm

11111111111111111
10100000000000000111111111
10000000000000000111111111
10111000011111111
101 100001
1011100001
1000000001
10000000W1
1111111111
```

### Controls

- **W / A / S / D**: move forward, left, backward, and right
- **Left / Right Arrows**: rotate the camera
- **ESC**: exit the game
- **Window close button**: exit safely and clean resources

## Resources

- **Lode's Computer Graphics Tutorial (Raycasting)**: detailed explanations of mathematical raycasting concepts. [Link](https://lodev.org/cgtutor/raycasting.html)
- **MiniLibX documentation**: reference for window and image management.
- **AI-assisted support**: AI tools were used to clarify raycasting math, help with parsing logic, and support debugging and code review during development.



