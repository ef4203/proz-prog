#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define SEPERATOR "  +-------+-------+-------+\n"

/* Clears the screen. */
void clearScreen()
{
    /* "@cls" clears the screen on windows systems.
     * "clear" clears the screen on unix-like systems.*/
    system("@cls||clear");
}

/* Prints a single row of the playing board. */
void makeRow(int row[9], int rowNumber)
{
    printf("%d | ", rowNumber + 1);
    for (int j = 0; j < 9; j++)
    {
        if (j == 3 || j == 6)
            printf("| ");
        printf("%d ", row[j]);
    }
    printf("|\n");
}

/* Prints the entire playing board. */
void makeBoard(int board[9][9])
{
    clearScreen();

    printf("    1 2 3   4 5 6   7 8 9\n");
    printf(SEPERATOR);
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            printf(SEPERATOR);
        makeRow(board[i], i);
    }
    printf(SEPERATOR);
}

int main()
{

    int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    while (1)
    {
        makeBoard(board);

        /* Something about this is really broken.
         * There's no exception handeling whatsoever. */
        int row[1];
        int column[1];
        int number[1];

        printf("ENTER A ROW (1-9): ");
        scanf("%d", row);
        printf("ENTER A COLUMN (1-9): ");
        scanf("%d", column);
        printf("ENTER A NUMBER (1-9): ");
        scanf("%d", number);

        board[row[0] - 1][column[0] - 1] = number[0];
    }
    return 0;
}
