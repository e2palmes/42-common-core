*This project has been created as part of the 42 curriculum by ediba-de.*

# so_long

## Description

`so_long` is a graphical 2D game project from the 42 Common Core that introduces the basics of computer graphics programming using the MiniLibX library.

The goal of the project is to create a small game where the player must collect all collectibles present on the map before reaching the exit. The project focuses on:

- window management
- texture rendering
- event handling
- map parsing and validation
- path validation using flood fill
- memory management
- clean program termination

The game is rendered using MiniLibX and runs on a tile-based map loaded from a `.ber` file.

---

## Features

- Parsing and validation of `.ber` maps
- Graphical rendering with MiniLibX
- WASD player movement
- Collectible management
- Exit condition handling
- Flood fill path checking
- Move counter display
- Clean window closing
- Memory leak free

---

## Instructions

### Requirements

Linux dependencies:

```bash
sudo apt install libx11-dev libxext-dev zlib1g-dev libbsd-dev
```

### Compilation

```bash
make
```

---

### Launch

```bash
./so_long maps/map.ber
```

---

## Controls

| Key | Action         |
| --- | -------------- |
| W   | Move up        |
| A   | Move left      |
| S   | Move down      |
| D   | Move right     |
| ESC | Close the game |

---

## Map Format

The map must:

* be rectangular
* be surrounded by walls (`1`)
* contain exactly:

  * 1 player (`P`)
  * 1 exit (`E`)
  * at least 1 collectible (`C`)
* only contain:

  * `0` empty floor
  * `1` wall
  * `P` player
  * `E` exit
  * `C` collectible

The project also validates that every collectible and the exit are reachable using a flood fill algorithm.

---

## Example Map

```txt
111111
1P0C01
100001
1C00E1
111111
```

---

## Project Structure

```txt
so_long/
├── includes/
├── maps/
├── src/
│   ├── parsing/
│   ├── mlx/
│   ├── textures/
│   └── utils/
├── textures/
├── Makefile
└── README.md
```

---

## Technical Choices

### Flood Fill

The project uses a recursive flood fill algorithm on a copy of the map to ensure that:

* all collectibles are reachable
* the exit is reachable

This prevents invalid or impossible maps.

### Rendering

The game uses:

* `mlx_init`
* `mlx_new_window`
* `mlx_put_image_to_window`
* XPM textures

for graphical rendering.

### Memory Management

The project frees:

* allocated maps
* textures
* MLX window
* MLX display

before exiting.

---

## Resources

### Documentation

* MiniLibX documentation:

  * [https://harm-smits.github.io/42docs/libs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
* MiniLibX Linux:

  * [https://github.com/42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
* XPM format:

  * [https://en.wikipedia.org/wiki/X_PixMap](https://en.wikipedia.org/wiki/X_PixMap)
* Flood fill algorithm:

  * [https://en.wikipedia.org/wiki/Flood_fill](https://en.wikipedia.org/wiki/Flood_fill)
* Valgrind documentation:

  * [https://valgrind.org/docs/manual/manual.html](https://valgrind.org/docs/manual/manual.html)

---

### AI Usage

AI tools were used during the development of this project for:

* debugging assistance
* understanding MiniLibX and xpm concepts
* flood fill implementation guidance
* Makefile troubleshooting
* test case generation
* README writing assistance

All code was reviewed, integrated, tested, and adapted manually.

```
```
