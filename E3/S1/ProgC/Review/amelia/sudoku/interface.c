#include <stdio.h>
#include "interface.h"

/* Fenêtre */
void init_window(void)
{
    MLV_create_window("Sudoku Graphique - TP7", "Sudoku",
                      WINDOW_WIDTH, WINDOW_HEIGHT);
}

void close_window(void)
{
    MLV_free_window();
}

/* Cellule */
void draw_cell_value(int row, int col, int value)
{
    char text[2];
    sprintf(text, "%d", value);

    int x = GRID_ORIGIN_X + col * CELL_SIZE + CELL_SIZE / 2;
    int y = GRID_ORIGIN_Y + row * CELL_SIZE + CELL_SIZE / 2;

    MLV_draw_text(x - 4, y - 8, text, MLV_COLOR_WHITE);
}

/* Grille */
void draw_grid(Board grid, int sel_row, int sel_col)
{
    int i, r, c;

    MLV_draw_filled_rectangle(0, 0,
                              WINDOW_WIDTH, WINDOW_HEIGHT, MLV_COLOR_BLACK);

    for (i = 0; i <= GRID_SIZE; i++)
    {
        int x = GRID_ORIGIN_X + i * CELL_SIZE;
        int y = GRID_ORIGIN_Y + i * CELL_SIZE;

        MLV_draw_line(x, GRID_ORIGIN_Y,
                      x, GRID_ORIGIN_Y + GRID_PIXEL_SIZE,
                      MLV_COLOR_WHITE);

        MLV_draw_line(GRID_ORIGIN_X, y,
                      GRID_ORIGIN_X + GRID_PIXEL_SIZE, y,
                      MLV_COLOR_WHITE);
    }

    for (r = 0; r < GRID_SIZE; r++)
    {
        for (c = 0; c < GRID_SIZE; c++)
        {
            if (r == sel_row && c == sel_col && grid[r][c] == 0)
            {
                MLV_draw_text(
                    GRID_ORIGIN_X + c * CELL_SIZE + CELL_SIZE / 2 - 4,
                    GRID_ORIGIN_Y + r * CELL_SIZE + CELL_SIZE / 2 - 8,
                    "?", MLV_COLOR_RED);
            }
            else if (grid[r][c] != 0)
            {
                draw_cell_value(r, c, grid[r][c]);
            }
        }
    }

    MLV_actualise_window();
}

/* Souris */
int mouse_to_cell(int x, int y, int *row, int *col)
{
    if (x < GRID_ORIGIN_X || y < GRID_ORIGIN_Y)
        return 0;
    x -= GRID_ORIGIN_X;
    y -= GRID_ORIGIN_Y;
    if (x >= GRID_PIXEL_SIZE || y >= GRID_PIXEL_SIZE)
        return 0;
    *col = x / CELL_SIZE;
    *row = y / CELL_SIZE;
    return 1;
}

int wait_click_on_empty_cell(Board B, int *row, int *col)
{
    int x, y;
    while (1)
    {
        MLV_wait_mouse(&x, &y);
        if (mouse_to_cell(x, y, row, col) && B[*row][*col] == 0)
            return 1;
    }
}

int show_number_pad_and_get_choice(int sel_row, int sel_col)
{
    int i, j, x, y;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int val = i * 3 + j + 1;
            int px = PAD_ORIGIN_X + j * CELL_SIZE;
            int py = PAD_ORIGIN_Y + i * CELL_SIZE;

            char txt[2];
            sprintf(txt, "%d", val);

            MLV_draw_rectangle(px, py, CELL_SIZE, CELL_SIZE, MLV_COLOR_WHITE);
            MLV_draw_text(px + CELL_SIZE / 2 - 4,
                          py + CELL_SIZE / 2 - 8,
                          txt, MLV_COLOR_WHITE);
        }
    }

    MLV_actualise_window();
    MLV_wait_mouse(&x, &y);

    if (x < PAD_ORIGIN_X || y < PAD_ORIGIN_Y)
        return 0;
    x -= PAD_ORIGIN_X;
    y -= PAD_ORIGIN_Y;
    if (x >= 3 * CELL_SIZE || y >= 3 * CELL_SIZE)
        return 0;

    return (y / CELL_SIZE) * 3 + (x / CELL_SIZE) + 1;
}
