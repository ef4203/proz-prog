#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m\n"
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

        if (row[j] == 0)
            printf("  ");
        else
            printf("%d ", row[j]);
    }
    printf("|\n");
}

/* Prints the entire playing board. */
void makeBoard(int dataArray[9][9])
{
    clearScreen();

    printf("    1 2 3   4 5 6   7 8 9\n");
    printf(SEPERATOR);
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            printf(SEPERATOR);
        makeRow(dataArray[i], i);
    }
    printf(SEPERATOR);
}

/* Checks if a board is valid */
int validateBoard(int board[9][9])
{
    int frow[9][9] = {0}, fcol[9][9] = {0}, fbox[3][3][9] = {0};
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != 0)
            {
                int val = board[i][j] - 1;
                if (frow[i][val] || fcol[j][val] || fbox[i / 3][j / 3][val])
                    return 0;
                frow[i][val] = fcol[j][val] = fbox[i / 3][j / 3][val] = 1;
            }
        }
    }
    return 1;
}

/* Checks if the input variables are valid */
int validateInput(int row, int column, int number)
{
    if (row < 1 || row > 9)
    {
        return 0;
    }
    else if (column < 1 || column > 9)
    {
        return 0;
    }
    else if (number < 1 || number > 9)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int gameIsWon(int board[9][9])
{
    if (board[0][0] == 0)
        return 0;
    else
        return 0;
}

int main()
{
    /*--------YOU CAN EDIT THE BOARD HERE--------*/
    int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    /*--------------------------------------------*/

    /* I don't know why I can't just copy board into
       input without doing this first. Urgh. */
    int input[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    /* Copy board state into input for validation */
    memcpy(input, board, sizeof(board));

    /* No input was made, so it's legal. */
    int legalInput = 1;

    do
    {
        /* copy the input on the board, only if its valid. */
        if (validateBoard(input))
        {
            memcpy(board, input, sizeof(board));
            makeBoard(board);
        }
        else
        {
            makeBoard(board);
            printf(ANSI_COLOR_RED "INVALID MOVE, TRY AGAIN" ANSI_COLOR_RESET);
        }

        if (!legalInput)
            printf(ANSI_COLOR_RED "INPUT INVALID, TRY AGAIN" ANSI_COLOR_RESET);

        int row, column, number;

        printf("ENTER A ROW (1-9): ");
        scanf("%d", &row);
        printf("ENTER A COLUMN (1-9): ");
        scanf("%d", &column);
        printf("ENTER A NUMBER (1-9): ");
        scanf("%d", &number);

        if (validateInput(row, column, number))
        {
            legalInput = 1;
            input[row - 1][column - 1] = number;
        }
        else
            legalInput = 0;

    } while (!gameIsWon(board));

    return 0;
}
