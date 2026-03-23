#include <stdlib.h>
#include "sudoku.h"

int is_valid_placement(int grid[9][9], int row, int col, int num)
{
    int i, j;

    for (j = 0; j < 9; j++)
    {
        if (j != col && grid[row][j] == num)
            return 0;
    }

    for (i = 0; i < 9; i++)
    {
        if (i != row && grid[i][col] == num)
            return 0;
    }

    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (i = box_row; i < box_row + 3; i++)
    {
        for (j = box_col; j < box_col + 3; j++)
        {
            if ((i != row || j != col) && grid[i][j] == num)
                return 0;
        }
    }

    return 1;
}

int solve_sudoku(int grid[9][9])
{
    int i, j, num;
    int row = -1, col = -1;
    int is_empty = 0;

    for (i = 0; i < 9 && !is_empty; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                is_empty = 1;
                break;
            }
        }
    }

    if (!is_empty)
        return 1;

    for (num = 1; num <= 9; num++)
    {
        if (is_valid_placement(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solve_sudoku(grid))
                return 1;

            grid[row][col] = 0;
        }
    }

    return 0;
}

int sudoku_is_complete(int grid[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

void copy_grid(int source[9][9], int dest[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}

void give_hint(int grid[9][9], int initial_grid[9][9])
{
    int solution[9][9];
    int empty_cells[81][2];
    int count = 0;
    int i, j;

    copy_grid(grid, solution);

    if (!solve_sudoku(solution))
        return;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0 && initial_grid[i][j] == 0)
            {
                empty_cells[count][0] = i;
                empty_cells[count][1] = j;
                count++;
            }
        }
    }

    if (count > 0)
    {
        int random_index = rand() % count;
        int row = empty_cells[random_index][0];
        int col = empty_cells[random_index][1];
        grid[row][col] = solution[row][col];
    }
}

int is_sudoku_valid(int grid[9][9])
{
    int valid = 1;
    int i, j;
    for (i=0;i<9 && valid;i++) {
        for (j=0;j<9;j++) {
            if (grid[i][j] != 0) {
                if (!is_valid_placement(grid, i, j, grid[i][j])) {
                    valid = 0;
                    break;
                }
            }
        }
    }
    return valid;
}