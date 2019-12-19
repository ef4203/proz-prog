#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m\n"
#define SEPERATOR "  +-------+-------+-------+\n"

static int board[9][9] = {0};

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

/* Check if the game has ended. */
int game_is_over()
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

/* Checks if the number is a valid option. */
int is_available(int __board[9][9], int row, int col, int num)
{
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;

    for (int i = 0; i < 9; i++)
    {
        if (__board[row][i] == num)
            return 0;
        if (__board[i][col] == num)
            return 0;
        if (__board[rowStart + (i % 3)][colStart + (i / 3)] == num)
            return 0;
    }

    return 1;
}

/* Solves the given board recursively. */
int solve_sudoku(int __board[9][9], int row, int col)
{
    if (row < 9 && col < 9)
    {
        if (__board[row][col] != 0)
        {
            if ((col + 1) < 9)
                return solve_sudoku(__board, row, col + 1);
            else if ((row + 1) < 9)
                return solve_sudoku(__board, row + 1, 0);
            else
                return 1;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                if (is_available(__board, row, col, i))
                {
                    __board[row][col] = i;
                    if ((col + 1) < 9)
                    {
                        if (solve_sudoku(__board, row, col + 1))
                            return 1;
                        else
                            __board[row][col] = 0;
                    }
                    else if ((row + 1) < 9)
                    {
                        if (solve_sudoku(__board, row + 1, 0))
                            return 1;
                        else
                            __board[row][col] = 0;
                    }
                    else
                        return 1;
                }
            }
        }
        return 0;
    }
    else
        return 1;
}

int main()
{
    srand(time(NULL));
    random_board();
    printf("GENERATED BOARD:\n\n");
    print_board();

    if (solve_sudoku(board, 0, 0))
    {
        printf("\nSOLVED BOARD:\n\n");
        print_board();
    }
    else
        printf(ANSI_COLOR_RED "\nNO SOLUTION FOUND" ANSI_COLOR_RESET);

    return 0;
}
