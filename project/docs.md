---
title: Documentation for a Maze Solving Program
---

# Non-technical Requirements

The program should take an image, representing a maze, and
should output a new image.
This new image should be the same maze, but with a red
path, solving the maze.

# Technical Requirements

- The image should be passed into the program via command line arguments.

- The image should be converted into a two dimensional array.

- The array should be processed and the solution should be found with a recursive algorithm.

- The array should be converted back into image binaries, and a new image should be saved.

# Infrastructure Requirements

## ``int main(int argc, char const *argv[])``

The main function parses the command line arguments for
the path to the image and calls all other required methods
to produce desired result.

If the program ran correctly, it should return a 1.

## ``void read_file()``

This function reads an image file from the command line
argument and stores the data in an array.

## ``void validate_file()``

Checks if the file is within the required constraints.

## ``void solve_board()``

This is a wrapper function which calls ``check_field``
multiple times, until the board is solved.

## ``void check_field(int x, int y)``

Check if the field has free fields next to it.

If it has only one, choose the next field.

If it has more than one, choose one field, and save
this field.

If it has none, go back one field, with one unexplored
empty field.

# Basic algorithm

Let's assume the file is valid.

The program should look for a start point. A start point is a pixel at the very
top row of the image. From that point the algorithm starts.

- Check each adjacent (Down, Up, Left, Right) pixel. If one pixel is free
(non-black) then that pixel is the next pixel and you start at over.

- If there's more than one pixel free, save the position of the origin pixel
and go down each path, starting with procedure as above.

- Should a path be a "dead path" return to the last saved position.
- Should all paths be explored, and the last saved position be the starting point,
the maze is deemed unsolvable.
