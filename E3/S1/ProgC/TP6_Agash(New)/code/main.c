#include <stdio.h>
#include <MLV/MLV_all.h>
#include "sudoku.h"
#include "in_out.h"
#include "graphic.h"


int main(int argc, char* argv[]) {
    Board grid;
    int mx, my;
    int row = -1, col = -1; 

    initialize_empty_board(grid);

    if (argc > 1) {
        printf("lecture du fichier %s\n", argv[1]);
        if (!fread_board(argv[1], grid)) {
            fprintf(stderr, "Erreur lecture fichier, grille vide.\n");
            return 1;
        }
    } else {
        printf("aucun fichier passé en argument\n");
        return 1;
    }

    MLV_create_window("Sudoku", "Sudoku", WIN_W, WIN_H);

    while (1) {
        draw_board(grid, row, col);
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
                row = col = -1;
            } else {
                const char* msg = "Valeur impossible a cet endroit";
                int msg_x = PICKER_X + PICKER_SIZE * PICKER_CELL / 4;
                int msg_y = PICKER_Y + PICKER_SIZE * PICKER_CELL + 20;

                MLV_draw_text(
                    msg_x, msg_y,
                    msg,
                    MLV_rgba(255, 0, 0, 255)
                );
                MLV_actualise_window();
                MLV_wait_seconds(1);
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
