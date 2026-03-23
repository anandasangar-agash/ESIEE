#include <MLV/MLV_all.h>
#include "event.h"
#include "sudoku.h"

void handle_event(int x, int y, int grid[9][9], int initial_grid[9][9],
                 int *selected_row, int *selected_col,
                 int grid_x, int grid_y, int grid_size,
                 int palette_x, int palette_width, int cell_size, int palette_cell_size,
                 int panel_height, int window_width, int margin)
{
    MLV_Event event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, &x, &y, NULL, NULL);
    if (event == MLV_MOUSE_BUTTON)
    {
        handle_mouse_click(x, y, grid, initial_grid, selected_row, selected_col,
                           grid_x, grid_y, grid_size,
                           palette_x, palette_width, cell_size, palette_cell_size,
                           panel_height, window_width, margin);
    }
}

void handle_mouse_click(int x, int y, int grid[9][9], int initial_grid[9][9],
                        int *selected_row, int *selected_col,
                        int grid_x, int grid_y, int grid_size,
                        int palette_x, int palette_width, int cell_size, int palette_cell_size,
                        int panel_height, int window_width, int margin)
{
    int hint_button_x = window_width - 100 - margin / 2;
    int hint_button_y = margin / 2;
    int button_width = 100;
    int button_height = 40;

    if (x >= hint_button_x && x < hint_button_x + button_width &&
        y >= hint_button_y && y < hint_button_y + button_height)
    {
        give_hint(grid, initial_grid);
        return;
    }

    if (x >= grid_x && x < grid_x + grid_size &&
        y >= grid_y && y < grid_y + grid_size)
    {
        *selected_col = (x - grid_x) / cell_size;
        *selected_row = (y - grid_y) / cell_size;
    }
    else if (x >= palette_x && x < palette_x + palette_width &&
             y >= grid_y && y < grid_y + 10 * palette_cell_size)
    {
        int palette_index = (y - grid_y) / palette_cell_size + 1;
        if (*selected_row != -1 && *selected_col != -1)
        {
            if (initial_grid[*selected_row][*selected_col] != 0)
            {
                return;
            }

            if (palette_index <= 9)
            {
                grid[*selected_row][*selected_col] = palette_index;
            }
            else if (palette_index == 10)
            {
                grid[*selected_row][*selected_col] = 0;
            }
        }
    }

    return;
}