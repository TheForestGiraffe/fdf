# FdF — 3D Wireframe Renderer

**FdF** is a graphical project from the 42 curriculum.  
It consists of rendering a 3D wireframe representation of a height map (`.fdf` file) using **MiniLibX**.

This implementation focuses on smooth interaction, multiple viewing modes, and real-time transformations.

## Preview

<p align="center">
<img width="480" alt="fdf screenshot" src="https://github.com/user-attachments/assets/79d3e81d-4091-4b67-8ad7-b8f1b8275188" />
</p>

## Features

### Mandatory
- Parse `.fdf` height maps
- Build a grid of 3D points `(x, y, z)`
- Project 3D coordinates into 2D space
- Custom line rasterization (Bresenham-style)
- Display in a window with MiniLibX
- Handle window close and ESC key

### Bonus (Implemented)
- ✅ Mouse-based translation (middle click + drag)
- ✅ Mouse-based rotation (right click + drag)
- ✅ Continuous automatic rotation
- ✅ Keyboard and mouse interaction
- ✅ Multiple camera views
- ✅ Isometric projection
- ✅ Perspective projection
- ✅ Orthographic views (top / side / front)
- ✅ Real-time zoom
- ✅ Smooth image rendering

## Controls

### Keyboard

| Key          | Action                          |
|--------------|---------------------------------|
| `ESC`        | Exit program                     |
| `X` (window button) | Close window                     |
| `R`          | Start / toggle automatic rotation |
| `I`          | Switch to isometric view         |
| `P`          | Switch to perspective view       |
| `Z`          | Top view                         |
| `X`          | Side view                        |
| `Y`          | Front view                       |
| `+`          | Zoom in                         |
| `-`          | Zoom out                         |
| `← ↑ ↓ →`    | Translate (move map)             |

### Mouse

| Action                     | Result        |
|----------------------------|---------------|
| Middle Click + Drag        | Translate map |
| Right Click + Drag         | Rotate view   |
| Mouse Wheel Scroll         | Zoom  |

## How to Build

### Requirements
- C compiler (`cc`)
- `make`
- MiniLibX (42 version)
- Linux

### Compile

```bash
make
```

### Clean
```bash
make clean
make fclean
make re
```

### Usage
```bash
./fdf maps/<map>.fdf
```

### Example:

```bash
./fdf maps/42.fdf
```

## .fdf File Format

An .fdf file contains a grid of heights:
- Each number represents a Z value
- Position in the grid defines X and Y

Optional hexadecimal color may be present. This version will ignore it.

Example:

0  0  0  0  
0  1  2  0  
0  2  4  0  
0  0  0  0

