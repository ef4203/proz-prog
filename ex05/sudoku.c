#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m\n"
#define SEPERATOR "  +-------+-------+-------+\n"

/* Data transfer structure. */
struct t_boardDto
{
    int state[9][9];
};

/* Clears the screen. */
void clear_screen()
{
    /* "@cls" clears the screen on windows systems.
     * "clear" clears the screen on unix-like systems.*/
    system("@cls||clear");
}

/* Prints a single row of the playing board. */
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
void print_board(int dataArray[9][9])
{
    clear_screen();

    printf("    1 2 3   4 5 6   7 8 9\n");
    printf(SEPERATOR);
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            printf(SEPERATOR);
        print_row(dataArray[i], i);
    }
    printf(SEPERATOR);
}

/* Checks if a board is valid. */
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

/* Checks if the input variables are valid. */
int validate_input(int row, int column, int number)
{
    if (row < 1 || row > 9)
        return 0;
    else if (column < 1 || column > 9)
        return 0;
    else if (number < 1 || number > 9)
        return 0;
    else
        return 1;
}

struct t_boardDto populate_board_with_random()
{
    struct t_boardDto board = {0};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int chance = rand() % 10;
            if (chance == 5)
            {
                board.state[i][j] = rand() % 9 + 1;
            }
        }
    }

    if (validate_board(board.state))
        return board;
    else
        return populate_board_with_random();
}

/* Check if all fields are field. */
int game_is_won(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[9][9] == 0)
                return 0;
        }
    }

    return 1;
}

int main()
{
    /*-------------------------------------------*/
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
    /*-------------------------------------------*/
    /*-------------------------------------------*/

    /* Create new empty array. */
    int input[9][9] = {0};

    /* Initialize random seed. */
    srand(time(NULL));

    /* Generate random board. */
    struct t_boardDto randomBoard = populate_board_with_random();

    /* Extract board from DTO. */
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = randomBoard.state[i][j];
        }
    }

    /* Copy board state into input for validation. */
    memcpy(input, board, sizeof(board));

    /* No input was made, so it's legal. */
    int legalInput = 1;

    int c;

    do
    {
        /* copy the input on the board, only if its valid. */
        if (validate_board(input))
        {
            memcpy(board, input, sizeof(board));
            print_board(board);
        }
        else
        {
            print_board(board);
            printf(ANSI_COLOR_RED "INVALID MOVE, TRY AGAIN" ANSI_COLOR_RESET);
        }

        if (!legalInput)
            printf(ANSI_COLOR_RED "INVALID INPUT, TRY AGAIN" ANSI_COLOR_RESET);

        int row, column, number;

        printf("ENTER A ROW (1-9): ");
        while (scanf("%d", &row) != 1)
        {
            while (!isspace(c = getchar()))
                ;
            ungetc(c, stdin);
            printf("You must enter a valid number. Try again.\n");
            continue;
        }

        printf("ENTER A COLUMN (1-9): ");

        while (scanf("%d", &column) != 1)
        {
            while (!isspace(c = getchar()))
                ;
            ungetc(c, stdin);
            printf("You must enter a valid number. Try again.\n");
            continue;
        }

        printf("ENTER A NUMBER (1-9): ");
        while (scanf("%d", &number) != 1)
        {
            while (!isspace(c = getchar()))
                ;
            ungetc(c, stdin);
            printf("You must enter a valid number. Try again.\n");
            continue;
        }

        if (validate_input(row, column, number))
        {
            legalInput = 1;
            input[row - 1][column - 1] = number;
        }
        else
            legalInput = 0;

    } while (!game_is_won(board));

    return 0;
}
