#ifndef INTERFACE_H
#define INTERFACE_H

void load_font();
void free_font();
void draw_grid_numbers(int grid[9][9], int initial_grid[9][9], int grid_x, int grid_y,
                       int cell_w, int cell_h, int selected_row, int selected_col);
void draw_grid_lines(int grid_x, int grid_y, int grid_width, int grid_height,
                     int cell_w, int cell_h);
void draw_palette(int palette_x, int grid_y, int palette_width, int palette_cell_size);
void draw_top_panel(int window_width, int panel_height, int margin);
void render_game(int grid[9][9], int initial_grid[9][9], int grid_x, int grid_y,
                 int grid_size, int cell_size, int palette_cell_size,
                 int palette_x, int palette_width, int selected_row, int selected_col,
                 int window_width, int panel_height, int margin);
void create_window(int window_width, int window_height);
void clear_window();
void free_window();
void actualise_window(float seconds);
void render_end(int valid);

#endif
