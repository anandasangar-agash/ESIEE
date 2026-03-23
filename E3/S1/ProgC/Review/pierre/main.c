#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudoku.h"
#include "interface.h"
#include "event.h"
#include "input.h"

int main(int argc, char *argv[])
{
    int grid[9][9];
    int initial_grid[9][9] = {0};
    int x = 0, y = 0;
    int selected_row = -1, selected_col = -1;

    int window_width = 730, window_height = 700;
    int panel_height = 70;
    int margin = 30;
    int grid_x = margin;
    int grid_y = panel_height + margin;
    int grid_size = window_height - panel_height - margin * 2;
    int palette_width = grid_size / 10;
    int cell_size = grid_size / 9;
    int palette_cell_size = grid_size / 10;
    int palette_x = grid_x + grid_size + margin;

    srand(time(NULL));

    if (argc != 2)
    {
        fprintf(stderr, "Il faut passer un fichier en argument\n");
        return 1;
    }

    if (read_grid(grid, argv[1]) != 0)
    {
        fprintf(stderr, "Impossible de lire le fichier %s\n", argv[1]);
        return 1;
    }

    copy_grid(grid, initial_grid);

    create_window(window_width, window_height);
    load_font();

    while (1)
    {
        clear_window();

        if (sudoku_is_complete(grid))
        {
            int all_valid = is_sudoku_valid(grid);
            render_end(all_valid);
            break;
        }

        handle_event(x, y, grid, initial_grid, &selected_row, &selected_col,
                     grid_x, grid_y, grid_size,
                     palette_x, palette_width, cell_size, palette_cell_size,
                     panel_height, window_width, margin);

        render_game(grid, initial_grid, grid_x, grid_y, grid_size,
                    cell_size, palette_cell_size, palette_x, palette_width,
                    selected_row, selected_col, window_width, panel_height, margin);

        actualise_window(0.1);
    }

    free_font();
    free_window();
    return 0;
}
