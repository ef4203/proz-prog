#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m\n"
#define SEPERATOR "  +-------+-------+-------+\n"

/* Define the board. */
int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};

/* Prints the entire playing board. */
void print_board()
{
    printf("    1 2 3   4 5 6   7 8 9\n");
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            printf(SEPERATOR);

        printf("%d | ", i + 1);
        for (int j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6)
                printf("| ");

            if (board[i][j] == 0)
                printf("  ");
            else
                printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf(SEPERATOR);
}

/* Checks if a board is valid. */
int validate_board(int __board[9][9])
{
    int row[9][9] = {0}, col[9][9] = {0}, box[3][3][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (__board[i][j] != 0)
            {
                int val = __board[i][j] - 1;
                if (row[i][val] || col[j][val] || box[i / 3][j / 3][val])
                    return 0;
                row[i][val] = col[j][val] = box[i / 3][j / 3][val] = 1;
            }
        }
    }

    return 1;
}

void random_board()
{
    int __board[9][9] = {0};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int chance = rand() % 10;
            if (chance == 5)
            {
                __board[i][j] = rand() % 9 + 1;
            }
        }
    }

    if (validate_board(__board))
    {
        memcpy(board, __board, sizeof(board));
        return;
    }

    random_board();
}

/* Check if all fields are field. */
int game_is_won()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }

    return 1;
}

int main()
{
    /* Create new empty array. */
    int input[9][9] = {0};
    /* No input was made, so it's valid. */
    int validInput = 1;
    /* Initialize random seed. */
    srand(time(NULL));
    /* Generate random board. */
    random_board();
    /* Copy board state into input for validation. */
    memcpy(input, board, sizeof(board));

    do
    {
        system("@cls");
        /* copy the input on the board, only if its valid. */
        if (!validate_board(input) || !validInput)
            printf(ANSI_COLOR_RED "INVALID MOVE, TRY AGAIN" ANSI_COLOR_RESET);
        else
            memcpy(board, input, sizeof(board));

        int row, column, number;
        print_board();
        validInput = 1;

        printf("ENTER A ROW (1-9): ");
        scanf("%d", &row);

        printf("ENTER A COLUMN (1-9): ");
        scanf("%d", &column);

        printf("ENTER A NUMBER (1-9): ");
        scanf("%d", &number);

        validInput &= row > 0 && row < 10;
        validInput &= column > 0 && column < 10;
        validInput &= number > 0 && number < 10;

        if (validInput)
            input[row - 1][column - 1] = number;

    } while (!game_is_won());

    return 0;
}
