# Documentation

Requirements for the project in the procedural programming
course.

## Non-technical Requirements

The program should take an image, representing a maze, and
should output a new image.
This new image should be the same maze, but with a red
path, solving the maze.

## Technical Requirements

- The image should be passed into the program via command line arguments.

- The image should be converted into a two dimensional array.

- The array should be processed and the solution should be found with a recursive algorithm.

- The array should be converted back into image binaries, and a new image should be saved.

## Specific Requirements

### ``int main(int argc, char const *argv[])``

The main function parses the command line arguments for
the path to the image and calls all other required methods
to produce desired result.

If the program ran correctly, it should return a 1.

### ``void read_file()``

This function reads an image file from the comand line
argument and stores the data in an array.

### ``void validate_file()``

Checks if the file is within the required constraints.
