#include <MLV/MLV_all.h>
#include <stdio.h>
#include "interface.h"
#include "sudoku.h"

static MLV_Font* game_font = NULL;

void load_font()
{
    game_font = MLV_load_font("font/geistmono.ttf", 24);
}

void free_font()
{
    if (game_font != NULL)
    {
        MLV_free_font(game_font);
        game_font = NULL;
    }
}

void draw_grid_numbers(int grid[9][9], int initial_grid[9][9], int grid_x, int grid_y,
                       int cell_w, int cell_h, int selected_row, int selected_col)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (i == selected_row && j == selected_col)
            {
                int cx = grid_x + j * cell_w;
                int cy = grid_y + i * cell_h;
                MLV_draw_filled_rectangle(cx + 2, cy + 2, cell_w - 4, cell_h - 4, MLV_rgba(255, 255, 200, 255));
            }

            if (grid[i][j] == 0)
            {
                continue;
            }

            char buffer[4];
            sprintf(buffer, "%d", grid[i][j]);
            int tx = grid_x + j * cell_w + cell_w / 2 - 8;
            int ty = grid_y + i * cell_h + cell_h / 2 - 12;

            if (initial_grid[i][j] != 0)
            {
                MLV_draw_text_with_font(tx, ty, buffer, game_font, MLV_rgba(41, 128, 185, 255));
            }
            else if (is_valid_placement(grid, i, j, grid[i][j]))
            {
                MLV_draw_text_with_font(tx, ty, buffer, game_font, MLV_rgba(44, 62, 80, 255));
            }
            else
            {
                MLV_draw_text_with_font(tx, ty, buffer, game_font, MLV_rgba(231, 76, 60, 255));
            }
        }
    }
}

void draw_grid_lines(int grid_x, int grid_y, int grid_width, int grid_height,
                     int cell_w, int cell_h)
{
    int i;

    MLV_draw_filled_rectangle(grid_x - 3, grid_y - 3, grid_width + 6, 3, MLV_rgba(44, 62, 80, 255));
    MLV_draw_filled_rectangle(grid_x - 3, grid_y + grid_height, grid_width + 6, 3, MLV_rgba(44, 62, 80, 255));
    MLV_draw_filled_rectangle(grid_x - 3, grid_y - 3, 3, grid_height + 6, MLV_rgba(44, 62, 80, 255));
    MLV_draw_filled_rectangle(grid_x + grid_width, grid_y - 3, 3, grid_height + 6, MLV_rgba(44, 62, 80, 255));

    for (i = 1; i < 9; i++)
    {
        int lx = grid_x + i * cell_w;
        int ly = grid_y + i * cell_h;

        if (i % 3 == 0)
        {
            MLV_draw_filled_rectangle(lx - 1, grid_y, 3, grid_height, MLV_rgba(44, 62, 80, 255));
            MLV_draw_filled_rectangle(grid_x, ly - 1, grid_width, 3, MLV_rgba(44, 62, 80, 255));
        }
        else
        {
            MLV_draw_line(lx, grid_y, lx, grid_y + grid_height, MLV_rgba(189, 195, 199, 255));
            MLV_draw_line(grid_x, ly, grid_x + grid_width, ly, MLV_rgba(189, 195, 199, 255));
        }
    }
}

void draw_palette(int palette_x, int grid_y, int palette_width, int palette_cell_size)
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        int py = grid_y + (i - 1) * palette_cell_size;
        MLV_draw_filled_rectangle(palette_x, py, palette_width, palette_cell_size,
                                  MLV_rgba(236, 240, 241, 255));
        MLV_draw_rectangle(palette_x, py, palette_width, palette_cell_size,
                           MLV_rgba(149, 165, 166, 255));

        char buffer[4];
        if (i <= 9)
        {
            sprintf(buffer, "%d", i);
        }
        else
        {
            sprintf(buffer, "?");
        }
        int tx = palette_x + palette_width / 2 - 8;
        int ty = py + palette_cell_size / 2 - 12;
        MLV_draw_text_with_font(tx, ty, buffer, game_font, MLV_rgba(44, 62, 80, 255));
    }
}

void draw_top_panel(int window_width, int panel_height, int margin)
{
    MLV_draw_filled_rectangle(0, 0, window_width, panel_height,
                              MLV_rgba(52, 73, 94, 255));

    MLV_draw_text_with_font(margin / 2, margin - 2, "SUDOKU PAR PIERRE G", game_font, MLV_rgba(236, 240, 241, 255));

    MLV_draw_filled_rectangle(window_width - 100 - margin / 2, margin / 2, 100, 40, MLV_rgba(52, 152, 219, 255));
    MLV_draw_text_with_font(window_width - 100 - margin / 2 + 15, margin / 2 + 12, "HINT", game_font, MLV_rgba(255, 255, 255, 255));
}

void render_game(int grid[9][9], int initial_grid[9][9], int grid_x, int grid_y,
                 int grid_size, int cell_size, int palette_cell_size,
                 int palette_x, int palette_width, int selected_row, int selected_col,
                 int window_width, int panel_height, int margin)
{
    MLV_clear_window(MLV_rgba(235, 240, 241, 255));
    draw_top_panel(window_width, panel_height, margin);
    draw_grid_numbers(grid, initial_grid, grid_x, grid_y, cell_size, cell_size, selected_row, selected_col);
    draw_grid_lines(grid_x, grid_y, grid_size, grid_size, cell_size, cell_size);
    draw_palette(palette_x, grid_y, palette_width, palette_cell_size);
    MLV_actualise_window();
}

void create_window(int window_width, int window_height)
{
    MLV_create_window("Sudoku", "Sudoku", window_width, window_height);
}

void clear_window()
{
    MLV_clear_window(MLV_rgba(236, 240, 241, 255));
}

void free_window()
{
    MLV_free_window();
}

void actualise_window(float seconds)
{
    MLV_actualise_window();
    MLV_wait_seconds(seconds);
}

void render_end(int valid)
{
    MLV_Font* large_font = MLV_load_font("font/geistmono.ttf", 40);
    MLV_Font* medium_font = MLV_load_font("font/geistmono.ttf", 30);

    if (valid)
    {
        MLV_draw_text_with_font(180, 350, "Bien joué!", large_font, MLV_rgba(46, 204, 113, 255));
        MLV_draw_text_with_font(200, 400, "Sudoku Complet!", medium_font, MLV_rgba(46, 204, 113, 255));
    }
    else
    {
        MLV_draw_text_with_font(220, 370, "La grille est incomplète", large_font, MLV_rgba(231, 76, 60, 255));
        MLV_draw_text_with_font(180, 410, "Mais contient des erreurs!", medium_font, MLV_rgba(231, 76, 60, 255));
    }

    actualise_window(5.0);

    MLV_free_font(large_font);
    MLV_free_font(medium_font);
}
