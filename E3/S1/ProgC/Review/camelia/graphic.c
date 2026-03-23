#include <MLV/MLV_all.h>

#include "graphic.h"

void draw_base() {
    int cell_size = 70;
    int x0 = 50, y0 = 50;
    int base_size = 9 * cell_size;
    int i, j;
    
    /* Lignes horizontales */
    for (i = 0; i <= 9; i++) {
        int y = y0 + i * cell_size;
        
        /* Lignes épaisses */
        if (i % 3 == 0) {
            MLV_draw_line(x0, y - 1, x0 + base_size, y - 1, MLV_COLOR_DEEPPINK);
            MLV_draw_line(x0, y, x0 + base_size, y, MLV_COLOR_DEEPPINK);
            MLV_draw_line(x0, y + 1, x0 + base_size, y + 1, MLV_COLOR_DEEPPINK);
        } else {
            /* Lignes fines */
            MLV_draw_line(x0, y, x0 + base_size, y, MLV_COLOR_PINK2);
        }
    }
    
    /* Lignes verticales */
    for (j = 0; j <= 9; j++) {
        int x = x0 + j * cell_size;
        
        /* Lignes épaisses */
        if (j % 3 == 0) {
            MLV_draw_line(x - 1, y0, x - 1, y0 + base_size, MLV_COLOR_DEEPPINK);
            MLV_draw_line(x, y0, x, y0 + base_size, MLV_COLOR_DEEPPINK);
            MLV_draw_line(x + 1, y0, x + 1, y0 + base_size, MLV_COLOR_DEEPPINK);
        } else {
            /* Lignes fines */
            MLV_draw_line(x, y0, x, y0 + base_size, MLV_COLOR_PINK2);
        }
    }
    
    MLV_actualise_window();
}

void print_numbers(Board B, InitialMask mask) {
    int cell_size = 70;
    int x0 = 50, y0 = 50;
    int i, j;
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (B[i][j] != 0) {
                MLV_Color color;
                char text[10];
                
                /* Chiffre initial = blanc, chiffre placé = vert */
                if (mask[i][j] == 1) {
                    color = MLV_COLOR_WHITE;
                } else {
                    color = MLV_COLOR_YELLOW;
                }
                
                sprintf(text, " %d ", B[i][j]);
                
                /* Afficher le chiffre centré dans la case */
                MLV_draw_text(
                    x0 + j * cell_size + 22,
                    y0 + i * cell_size + 15,
                    "%d",
                    color,
                    B[i][j]
                );
            }
        }
    }
    
    MLV_actualise_window();
}

int get_clicked_cell(int mouse_x, int mouse_y, int* row, int* col) {
    int x0 = 50, y0 = 50;
    int cell_size = 70; /* taille d'une cellule */
    int grid_size = 9 * cell_size;  /* 630 pixels */
    
    /* Vérifier si le clic est dans la grille */
    if (mouse_x < x0 || mouse_x > x0 + grid_size ||
        mouse_y < y0 || mouse_y > y0 + grid_size) {
        return 0;  /* Clic hors de la grille globale */
    }
    
    /* Calculer les indices de la case */
    *col = (mouse_x - x0) / cell_size;  /* colonne (0-8) --> division entière pour savoir quelle colonne*/
    *row = (mouse_y - y0) / cell_size;  /* ligne (0-8) */
    
    return 1;  /* Clic valide dans la grille */
}

void draw_selection_dial(Board B, int row, int col) {
    int cell_size = 70;
    int x0 = 50, y0 = 50;
    
    /* Position FIXE du cadran : à droite de la grille */
    int dial_x = 800;
    int dial_y = 250;
    int dial_cell_size = 60;  /* Taille des cases du cadran */
    
    int i, j;
    int num = 1;
    
    /* Afficher "?" dans la case cliquée */
    MLV_draw_text(
        x0 + col * cell_size + 25,
        y0 + row * cell_size + 20,
        "?",
        MLV_COLOR_YELLOW
    );
    
    /* Lignes horizontales du cadran */
    for (i = 0; i <= 3; i++) {
        int y = dial_y + i * dial_cell_size;
        MLV_draw_line(dial_x, y, dial_x + 3 * dial_cell_size, y, MLV_COLOR_PINK2);
    }
    
    /* Lignes verticales du cadran */
    for (j = 0; j <= 3; j++) {
        int x = dial_x + j * dial_cell_size;
        MLV_draw_line(x, dial_y, x, dial_y + 3 * dial_cell_size, MLV_COLOR_PINK2);
    }
    
    /* Chiffres 1-9 dans le cadran */
    num = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            MLV_draw_text(
                dial_x + j * dial_cell_size + 20,
                dial_y + i * dial_cell_size + 15,
                "%d",
                MLV_COLOR_WHITE,
                num
            );
            num++;
        }
    }
    
    MLV_actualise_window();
}

void redraw_grid(Board B, InitialMask mask) {
    /* Effacer tout */
    MLV_draw_filled_rectangle(0, 0, 1200, 800, MLV_COLOR_BLACK);
    
    /* Redessiner */
    draw_base();
    print_numbers(B, mask);
}

int get_selected_number(int mouse_x, int mouse_y) {
    int dial_x = 800;
    int dial_y = 250;
    int dial_cell_size = 60;
    
    /* Vérifier si le clic est dans la zone du cadran */
    if (mouse_x < dial_x || mouse_x > dial_x + 3 * dial_cell_size ||
        mouse_y < dial_y || mouse_y > dial_y + 3 * dial_cell_size) {
        return 0;  /* Clic hors du cadran */
    }
    
    /* Calculer quelle case du cadran a été cliquée */
    int col = (mouse_x - dial_x) / dial_cell_size;  /* 0, 1 ou 2 */
    int row = (mouse_y - dial_y) / dial_cell_size;  /* 0, 1 ou 2 */
    
    /* Convertir position en chiffre (1-9) */
    int num = row * 3 + col + 1;
    
    return num;
}


