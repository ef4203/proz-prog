#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Parse command line arguments. */
    if (argc > 1)
    {
        /* Debugging */
        printf("Looking for file at: %s\n", argv[argc - 1]);
    }
    else
    {
        printf("Usage: %s [INPUT] [OUTPUT]\n", argv[0]);
        printf("Solves a maze FILE to OUTPUT.\n\n");
        printf("Example:\n\t%s input.bmp output.bmp\tSolves the maze in "
               "input.bmp and saves the result in output.bmp\n",
               argv[0]);
    }

    /* Look for the file. */
    /* Load the file. */
    /* Solve the maze. */
    /* Write new file. */
    return 1;
}

