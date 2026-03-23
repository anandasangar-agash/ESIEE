#include <stdio.h>
#include "sudoku.h"
#include "in_out.h"
#include <MLV/MLV_all.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define GRID_SIZE 9
#define CELL_SIZE 60      
#define GRID_X 100 
#define GRID_Y 100 


void draw_board(Board grid) {
    int i, j;
    int x1, y1, x2, y2;
    
    MLV_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
                              MLV_rgba(0, 0, 0, 255));
    
    for (i = 0; i <= GRID_SIZE; i++) {
        
        x1 = GRID_X;
        y1 = GRID_Y + i * CELL_SIZE;
        x2 = GRID_X + GRID_SIZE * CELL_SIZE;
        y2 = y1;
        MLV_draw_line(x1, y1, x2, y2,
                      MLV_rgba(255, 255, 255, 255));

        
        x1 = GRID_X + i * CELL_SIZE;
        y1 = GRID_Y;
        x2 = x1;
        y2 = GRID_Y + GRID_SIZE * CELL_SIZE;
        MLV_draw_line(x1, y1, x2, y2,
                      MLV_rgba(255, 255, 255, 255));
    }

    
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != 0) {
                char text[2];
                int x, y;
                text[0] = '0' + grid[i][j];
                text[1] = '\0';
                x = GRID_X + j * CELL_SIZE + CELL_SIZE / 2 - 5;
                y = GRID_Y + i * CELL_SIZE + CELL_SIZE / 2 - 10;
                MLV_draw_text(x, y, text,
                              MLV_rgba(255, 255, 255, 255));
            }
        }
    }
}


void screen_to_cell(int x, int y, int* row, int* col) {
    if (x < GRID_X || y < GRID_Y) {
        *row = -1;
        *col = -1;
        return;
    }
    x -= GRID_X;
    y -= GRID_Y;

    if (x >= GRID_SIZE * CELL_SIZE || y >= GRID_SIZE * CELL_SIZE) {
        *row = -1;
        *col = -1;
        return;
    }

    *col = x / CELL_SIZE;
    *row = y / CELL_SIZE;
}


int choose_value(int cell_row, int cell_col) {
    int x0, y0, w, h;
    int mx, my;
    int val_row, val_col;
    int val;

    
    w = 3 * CELL_SIZE;
    h = 3 * CELL_SIZE;
    x0 = GRID_X + cell_col * CELL_SIZE;
    y0 = GRID_Y + cell_row * CELL_SIZE;

    
    if (x0 + w > WINDOW_WIDTH) {
        x0 = WINDOW_WIDTH - w - 10;
    }
    if (y0 + h > WINDOW_HEIGHT) {
        y0 = WINDOW_HEIGHT - h - 10;
    }

    
    MLV_draw_filled_rectangle(x0, y0, w, h,
                              MLV_rgba(50, 50, 50, 230));

    
    {
        int cx = GRID_X + cell_col * CELL_SIZE + CELL_SIZE / 2 - 5;
        int cy = GRID_Y + cell_row * CELL_SIZE + CELL_SIZE / 2 - 10;
        MLV_draw_text(cx, cy, "?",
                      MLV_rgba(255, 255, 0, 255));
    }

    
    for (val = 1; val <= 9; val++) {
        char text[2];
        int vx, vy;
        val_row = (val - 1) / 3;
        val_col = (val - 1) % 3;

        vx = x0 + val_col * CELL_SIZE + CELL_SIZE / 2 - 5;
        vy = y0 + val_row * CELL_SIZE + CELL_SIZE / 2 - 10;

        text[0] = '0' + val;
        text[1] = '\0';

        MLV_draw_text(vx, vy, text,
                      MLV_rgba(255, 255, 255, 255));
    }

    MLV_actualise_window();

    
    MLV_wait_mouse(&mx, &my);

    if (mx < x0 || mx >= x0 + w || my < y0 || my >= y0 + h) {
        return 0;
    }

    val_col = (mx - x0) / CELL_SIZE;
    val_row = (my - y0) / CELL_SIZE;
    val = val_row * 3 + val_col + 1;

    if (val < 1 || val > 9) {
        return 0;
    }
    return val;
}

int main(int argc, char* argv[]) {
    Board grid;
    int x, y;
    int row, col;
    int chosen;
    int running = 1;

    initialize_empty_board(grid);

    
    if (argc > 1) {
        if (!fread_board(argv[1], grid)) {
            fprintf(stderr, "Impossible de lire la grille, on démarre avec une grille vide.\n");
        }
    }

    MLV_create_window("Sudoku", "Sudoku", WINDOW_WIDTH, WINDOW_HEIGHT);

    while (running) {
        draw_board(grid);
        MLV_actualise_window();

        
        if (is_full(grid)) {
            MLV_draw_text(400, 50, "Grille remplie !",
                          MLV_rgba(0, 255, 0, 255));
            MLV_actualise_window();
            MLV_wait_seconds(5);
            break;
        }

        
        MLV_wait_mouse(&x, &y);
        screen_to_cell(x, y, &row, &col);

        if (row < 0 || col < 0) {
            continue; 
        }

        
        if (grid[row][col] != 0) {
            continue;
        }

        chosen = choose_value(row, col);
        if (chosen == 0) {
            continue; 
        }

        
        if (is_legal(grid, row, col, chosen)) {
            grid[row][col] = chosen;
        } else {
            
            MLV_draw_text(400, 50, "Valeur illegale !",
                          MLV_rgba(255, 0, 0, 255));
            MLV_actualise_window();
            MLV_wait_seconds(1);
        }
    }

    MLV_free_window();
    return 0;
}

