# fun-C-Code

This repository contains a fun C program that generates an animated ASCII art donut (torus) rotating in 3D space. The program, `donut_deobfuscated.c`, creates a mesmerizing visual effect in the terminal using only ASCII characters.

## Description

The donut code is a classic example of creative ASCII art animation. It uses mathematical calculations to project a 3D torus onto a 2D plane and represents different luminance levels with ASCII characters. The result is a continuously rotating donut-shaped figure in your terminal.

Key features:
- 3D to 2D projection of a torus
- Dynamic shading using ASCII characters
- Continuous rotation animation


## Running the Code on macOS

To run this code on macOS, follow these steps:

1. Open Terminal.

2. Navigate to the directory containing the `donut_deobfuscated.c` file:
   ```
   cd path/to/fun-C-Code
   ```

3. Compile the C code using gcc:
   ```
   gcc -o donut donut_deobfuscated.c -lm
   ```
   Note: The `-lm` flag is necessary to link the math library.

4. Run the compiled program:
   ```
   ./donut
   ```

5. To stop the animation, press `Ctrl+C`.

Enjoy the mesmerizing ASCII donut animation!

Note: Make sure you have Xcode Command Line Tools installed on your macOS to use gcc. If you don't have it installed, you can install it by running `xcode-select --install` in the Terminal.
