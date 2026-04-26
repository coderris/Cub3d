*This project has been created as part of the 42 curriculum by [mamarin-](https://profile-v3.intra.42.fr/users/mamarin-), [lanton-m](https://profile-v3.intra.42.fr/users/lanton-m).*

# Cub3D

## Description

**Cub3D** is a project from the 42 curriculum inspired by the world-famous 90s game Wolfenstein 3D. The goal of this project is to create a dynamic view inside a maze, exploring the concepts of ray-casting. It serves as an introduction to basic computer graphics, mathematics (trigonometry, vectors), and practical use of the miniLibX (42's basic graphical library). 

The player navigates through a 3D environment generated from a 2D map, encountering textures, ceiling/floor colors, and a first-person perspective.

## Features

- **Raycasting Engine**: Implemented from scratch to render a 3D perspective from a 2D map.
- **Graphics Library**: Built using the minimal graphic library provided by 42, `miniLibX`.
- **Parsing**: Strict map parsing to ensure the map is fully enclosed by walls, with valid configuration for textures and colors.
- **Movement**: Player movement (W, A, S, D) and camera rotation (Left/Right arrows) with basic collision detection against walls.

## Instructions

### Compilation

To compile the project, ensure you have the required dependencies for `miniLibX` installed. The provided `Makefile` supports the following rules:

- `make` or `make all`: Compiles the source files and generates the `cub3D` executable.
- `make clean`: Removes the compiled object (`.o`) files.
- `make fclean`: Removes the object files and the `cub3D` executable.
- `make re`: Performs a `make fclean` followed by a `make`, completely recompiling the project.

### Execution

Run the game by providing a valid `.cub` map file as an argument:

```bash
./cub3D maps/map.cub
```

#### Valid Maps

The map file (always with a `.cub` extension) is composed of two main parts: the configuration (textures and colors) and the map itself.

Rules for a valid map:
1. The map must be completely surrounded by walls (`1`).
2. Empty spaces are represented by `0`.
3. The player's start position and orientation is defined by exactly one of the following characters: `N`, `S`, `E`, `W`.
4. Empty spaces (` `) are allowed but must be managed correctly for enclosures depending on your parsing logic.
5. The configuration elements (textures: `NO`, `SO`, `WE`, `EA`; colors: `F` for floor, `C` for ceiling) must appear before the map content.

**Example of a valid `.cub` file:**
```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

1111111
1000001
1011101
100N001
1111111
```

### Controls

- **W, A, S, D**: Move the character (Forward, Left, Backward, Right)
- **Left / Right Arrows**: Rotate the camera view
- **ESC** or **Red Cross (Window)**: Exit the game safely and free all resources

## Resources

- **Lode's Computer Graphics Tutorial (Raycasting)**: An essential guide that provides the mathematical foundation and implementation details for raycasting. [Link](https://lodev.org/cgtutor/raycasting.html)
- **miniLibX Documentation**: Community resources on how to handle the 42 library.
- **AI Usage Description**: AI tools were used during this project as an interactive assistant. Specifically, AI was utilized to help clarify complex trigonometric formulas for ray-casting calculations, troubleshoot memory leaks (`valgrind`/`leaks`), and scaffold standard boilerplate code (e.g., standard Makefile structures, parsing logic overviews). *Note: Please update this specific text to reflect your exact AI tool usage in the project.*

## Current Progress

Currently, the project is in the **early development and parsing phase**. The main focus has been establishing the core data structures and reading the `.cub` configuration files.

### Implemented Features & Functions

- **Data Structures (`cub3d.h`)**:
  - `t_map_sett`: Handles map settings, storing paths for wall textures (North, South, East, West) and RGB values for Floor (`F`) and Ceiling (`C`).
  - `t_game_inf`: Stores the player's spatial data, including position (`X`, `Y`), direction (`dir_X`, `dir_Y`), camera plane (`plane_X`, `plane_Y`), and frame timings.

- **Parsing (`parse.c` & `parse_utils.c`)**:
  - `ft_parse_map`: The main entry point for processing the map file.
  - `ft_fill_textures` & `ft_add_text`: Responsible for extracting the paths of the XPM textures and the color formats from the file header, validating that they are proper descriptors.
  - `ft_check_line`: Utility to clean and validate strings read from the file.

- **Error Handling & Memory Management (`error_message.c` & `cleaners.c`)**:
  - `ft_print_error`: Customized error handling structure to provide descriptive error messages when map parsing fails.
  - `clean_exit`: Basic garbage collection system to safely free structures (`t_map_sett`) and exit cleanly when errors are encountered or at the end of execution.

*(Note: Raycasting algorithms and `miniLibX` window manipulation are yet to be integrated).*