# 3D Interactive Robot — OpenGL/GLUT

A 3rd-year university project for a **Computer Graphics (Draw & Computer)** course.
Built in C++ using OpenGL and GLUT, featuring a fully articulated 3D robot in an interactive indoor environment.

---

## Preview

> Interactive 3D robot with individual joint control, pre-programmed animations, and a furnished room environment.

---

## Features

- **Articulated robot** with independently controllable joints:
  - Shoulders (Z and Y axis), elbows, fingers (2 per hand), neck
  - Shock absorber leg system
- **Indoor environment:** walls, 3 front windows, 3 back windows, 5 tables, 5 closets, a door, and a ceiling spotlight
- **4 pre-programmed animations** including arm dances and a teapot pick-up sequence
- **Real-time keyboard control** for manual joint manipulation and robot movement
- Spotlight lighting, material properties, and alpha-blended transparency (windows, floor)

---

## Controls

### Movement
| Key | Action |
|-----|--------|
| `2` / `8` or Arrow Keys | Move robot forward/backward |
| `4` / `6` or Arrow Keys | Rotate robot left/right |
| `p` / `P` | Rotate entire scene view |

### Joints
| Key | Action |
|-----|--------|
| `s` / `S` | Right shoulder (Z-axis) |
| `x` / `X` | Right shoulder (Y-axis) |
| `w` / `W` | Right elbow |
| `d` / `D` | Left shoulder (Z-axis) |
| `c` / `C` | Left shoulder (Y-axis) |
| `e` / `E` | Left elbow |
| `g` / `G` | Right first finger |
| `h` / `H` | Right second finger |
| `t` / `T` | Left first finger |
| `y` / `Y` | Left second finger |
| `n` / `N` | Neck rotation |
| `u` | Toggle shock absorber |

### Animations
| Key | Action |
|-----|--------|
| `l` | Animation 1 — arm swing dance |
| `k` | Animation 2 — shoulder rotation dance |
| `j` | Animation 3 — pick up teapot (position-dependent) |
| `;` | Animation 4 — left elbow movement |
| `L` | Reset to initial pose |

---

## Tech Stack

| | |
|---|---|
| Language | C++ |
| Graphics | OpenGL + GLUT (glut32) |
| IDE | Code::Blocks (MinGW/GCC) |
| Platform | Windows |

---

## Build & Run

### Prerequisites
- Windows with MinGW or MSVC
- GLUT32 libraries (`glut32.dll`, `glut32.lib`, `glut/glut.h`)

### With Code::Blocks
1. Open `robot_project.cbp`
2. Build & Run (`F9`)

### Manual (GCC/MinGW)
```bash
g++ main.cpp -o robot_project -lglut32 -lopengl32 -lglu32 -lwinmm -lgdi32
```

A pre-compiled `robot_project.exe` is included in `bin/Debug/`.

---

## Project Structure

```
robot_project/
├── main.cpp              # All source code (~1100 lines)
├── robot_project.cbp     # Code::Blocks project file
├── bin/Debug/
│   └── robot_project.exe # Pre-compiled executable
└── obj/Debug/
    └── main.o
```

---

## Course Context

- **Course:** Draw & Computer (Computer Graphics)
- **Year:** 3rd year — Bachelor's degree
- **Topics covered:** 3D transformations, hierarchical joint modeling, OpenGL lighting & materials, keyframe animation, user interaction
