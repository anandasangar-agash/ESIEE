#include <stdio.h>
#include <MLV/MLV_all.h>
#include "sudoku.h"
#include "in_out.h"

#define WIN_W 1200
#define WIN_H 800

#define GRID_SIZE 9
#define CELL 60
#define GRID_X 100
#define GRID_Y 100

#define PICKER_SIZE 3
#define PICKER_CELL 60
#define PICKER_X (GRID_X + GRID_SIZE * CELL + 100)
#define PICKER_Y (GRID_Y + 3 * CELL)

void clear_screen(void) {
    MLV_draw_filled_rectangle(0, 0, WIN_W, WIN_H,
                              MLV_rgba(0, 0, 0, 255));
}

void draw_grid(void) {
    int i;
    for (i = 0; i <= GRID_SIZE; i++) {
        MLV_draw_line(
            GRID_X,
            GRID_Y + i * CELL,
            GRID_X + GRID_SIZE * CELL,
            GRID_Y + i * CELL,
            MLV_rgba(255, 255, 255, 255)
        );

        MLV_draw_line(
            GRID_X + i * CELL,
            GRID_Y,
            GRID_X + i * CELL,
            GRID_Y + GRID_SIZE * CELL,
            MLV_rgba(255, 255, 255, 255)
        );
    }
}

void draw_numbers(Board grid) {
    int r,c;
    for (r = 0; r < GRID_SIZE; r++) {
        for (c = 0; c < GRID_SIZE; c++) {
            if (grid[r][c] != 0) {
                char txt[2] = { '0' + grid[r][c], '\0' };

                MLV_draw_text(
                    GRID_X + c * CELL + CELL / 2 - 5,
                    GRID_Y + r * CELL + CELL / 2 - 10,
                    txt,
                    MLV_rgba(255, 255, 255, 255)
                );
            }
        }
    }
}

void draw_picker(void) {
    MLV_draw_filled_rectangle(
        PICKER_X, PICKER_Y,
        PICKER_SIZE * PICKER_CELL,
        PICKER_SIZE * PICKER_CELL,
        MLV_rgba(40, 40, 40, 255)
    );
    int i;
    for (i = 0; i <= PICKER_SIZE; i++) {
        MLV_draw_line(
            PICKER_X,
            PICKER_Y + i * PICKER_CELL,
            PICKER_X + PICKER_SIZE * PICKER_CELL,
            PICKER_Y + i * PICKER_CELL,
            MLV_rgba(255, 255, 255, 255)
        );

        MLV_draw_line(
            PICKER_X + i * PICKER_CELL,
            PICKER_Y,
            PICKER_X + i * PICKER_CELL,
            PICKER_Y + PICKER_SIZE * PICKER_CELL,
            MLV_rgba(255, 255, 255, 255)
        );
    }
    int v;
    for (v = 1; v <= 9; v++) {
        char txt[2] = { '0' + v, '\0' };
        int r = (v - 1) / 3;
        int c = (v - 1) % 3;

        MLV_draw_text(
            PICKER_X + c * PICKER_CELL + PICKER_CELL / 2 - 5,
            PICKER_Y + r * PICKER_CELL + PICKER_CELL / 2 - 10,
            txt,
            MLV_rgba(255, 255, 255, 255)
        );
    }
}

void draw_board(Board grid) {
    clear_screen();
    draw_grid();
    draw_numbers(grid);
    draw_picker();
}

int mouse_to_cell(int mx, int my, int* row, int* col) {
    if (mx < GRID_X || my < GRID_Y) return 0;

    mx -= GRID_X;
    my -= GRID_Y;

    if (mx >= GRID_SIZE * CELL || my >= GRID_SIZE * CELL) return 0;

    *col = mx / CELL;
    *row = my / CELL;
    return 1;
}

int mouse_to_picker(int mx, int my) {
    if (mx < PICKER_X || my < PICKER_Y) return 0;
    if (mx >= PICKER_X + PICKER_SIZE * PICKER_CELL) return 0;
    if (my >= PICKER_Y + PICKER_SIZE * PICKER_CELL) return 0;

    int col = (mx - PICKER_X) / PICKER_CELL;
    int row = (my - PICKER_Y) / PICKER_CELL;

    return row * 3 + col + 1; 
}

int main(int argc, char* argv[]) {
    Board grid;
    int mx, my;
    int row = -1, col = -1; 

    initialize_empty_board(grid);

    if (argc > 1 && !fread_board(argv[1], grid)) {
        fprintf(stderr, "Erreur lecture fichier, grille vide.\n");
    }

    MLV_create_window("Sudoku", "Sudoku", WIN_W, WIN_H);

    while (1) {
        draw_board(grid);
        MLV_actualise_window();

        if (is_full(grid)) {
            MLV_draw_text(450, 50, "Grille complete !",
                          MLV_rgba(0, 255, 0, 255));
            MLV_actualise_window();
            MLV_wait_seconds(3);
            break;
        }

        MLV_wait_mouse(&mx, &my);

        int picked = mouse_to_picker(mx, my);
        if (picked != 0 && row != -1 && col != -1) {
            if (is_valid(grid, row, col, picked)) {
                grid[row][col] = picked;
            }
            continue;
        }

        if (mouse_to_cell(mx, my, &row, &col)) {
            if (grid[row][col] != 0) {
                row = col = -1; 
            }
        }
    }

    MLV_free_window();
    return 0;
}
