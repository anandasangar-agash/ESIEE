#include <stdio.h>
#include <MLV/MLV_all.h>

#include "sudoku.h"
#include "in_out.h"
#include "graphic.h"

int main(int argc, char* argv[]){
    Board B;
    InitialMask mask;  /* Masque des cases initiales */
    int mouse_x, mouse_y;
    int row, col;
    int selected_num;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier_grille>\n", argv[0]);
        return 1;
    }
    
    if (!fread_board(argv[1], B)) {
        return 1;
    }
    
    /* Créer le masque des cases initiales */
    create_initial_mask(B, mask);
    
    MLV_create_window_with_default_font("Sudoku", "Sudoku", 1200, 800, "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 30);

    draw_base();
    print_numbers(B, mask);
    
    /* BOUCLE DE JEU */
    while (!is_grid_complete(B)) {
        
        MLV_wait_mouse(&mouse_x, &mouse_y);
        
        if (!get_clicked_cell(mouse_x, mouse_y, &row, &col)) {
            continue;
        }
        
        if (B[row][col] != 0) {
            printf("Case déjà remplie avec %d\n", B[row][col]);
            continue;
        }
        
        printf("Case vide (%d,%d) cliquée.\n", row, col);
        draw_selection_dial(B, row, col);
        
        MLV_wait_mouse(&mouse_x, &mouse_y);
        selected_num = get_selected_number(mouse_x, mouse_y);
        
        if (selected_num == 0) {
            printf("Annulation.\n");
            redraw_grid(B, mask);
            continue;
        }
        
        printf("Chiffre sélectionné : %d\n", selected_num);
        
        if (can_place(B, row, col, selected_num)) {
            printf("Placement valide !\n");
            B[row][col] = selected_num;
        } else {
            printf("Placement invalide !\n");
        }
        
        redraw_grid(B, mask);
    }
    
    /* SI victoire ! */
    printf("\nBRAVO ! Sudoku réussi !!!\n");
    
    MLV_draw_text(
        400, 400,
        "BRAVO ! Sudoku réussi !!!",
        MLV_COLOR_YELLOW
    );
    MLV_actualise_window();
    
    printf("Cliquez pour fermer...\n");
    MLV_wait_mouse(NULL, NULL);
    
    MLV_free_window();
    return 0;
}
