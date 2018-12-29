#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m\n"
#define SEPERATOR "  +-------+-------+-------+\n"

/* Data transfer structure. */
struct t_board
{
    int values[9][9];
};

/* Prints a single row of the board. */
void print_row(int row[9], int rowNumber)
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
void print_board(int board[9][9])
{
    printf("    1 2 3   4 5 6   7 8 9\n");
    printf(SEPERATOR);
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            printf(SEPERATOR);
        print_row(board[i], i);
    }
    printf(SEPERATOR);
}

/* Checks if a board state is valid. */
int validate_board(int board[9][9])
{
    int row[9][9] = {0}, col[9][9] = {0}, box[3][3][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)
            {
                int val = board[i][j] - 1;
                if (row[i][val] || col[j][val] || box[i / 3][j / 3][val])
                    return 0;
                row[i][val] = col[j][val] = box[i / 3][j / 3][val] = 1;
            }
        }
    }
    return 1;
}

/* Generates a random valid board. */
struct t_board generate_random_board()
{
    struct t_board board = {0};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int chance = rand() % 10;
            if (chance == 5)
            {
                board.values[i][j] = rand() % 9 + 1;
            }
        }
    }

    if (validate_board(board.values))
        return board;
    else
        return generate_random_board(board);
}

/* Check if the game has ended. */
int game_is_over(int board[9][9])
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
int is_available(int board[9][9], int row, int col, int num)
{
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return 0;
        if (board[i][col] == num)
            return 0;
        if (board[rowStart + (i % 3)][colStart + (i / 3)] == num)
            return 0;
    }

    return 1;
}

/* Solves the given board recursively. */
int solve_sudoku(int board[9][9], int row, int col)
{
    if (row < 9 && col < 9)
    {
        if (board[row][col] != 0)
        {
            if ((col + 1) < 9)
                return solve_sudoku(board, row, col + 1);
            else if ((row + 1) < 9)
                return solve_sudoku(board, row + 1, 0);
            else
                return 1;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                if (is_available(board, row, col, i))
                {
                    board[row][col] = i;
                    if ((col + 1) < 9)
                    {
                        if (solve_sudoku(board, row, col + 1))
                            return 1;
                        else
                            board[row][col] = 0;
                    }
                    else if ((row + 1) < 9)
                    {
                        if (solve_sudoku(board, row + 1, 0))
                            return 1;
                        else
                            board[row][col] = 0;
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
    /* Seed the random number generator */
    srand(time(NULL));

    int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    struct t_board b = generate_random_board();
    memcpy(board, b.values, sizeof(b));

    printf("GENERATED BOARD:\n\n");
    print_board(board);

    if (solve_sudoku(board, 0, 0))
    {
        printf("\nSOLVED BOARD:\n\n");
        print_board(board);
    }
    else
        printf(ANSI_COLOR_RED "\nNO SOLUTION FOUND" ANSI_COLOR_RESET);

    return 0;
}
