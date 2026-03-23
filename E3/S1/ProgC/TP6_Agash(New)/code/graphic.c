#include <stdio.h>
#include "graphic.h"


/**
 * ============================================================================
 * FONCTION clear_screen
 * ============================================================================
 * Efface complètement l'écran en le remplissant d'un rectangle noir sur toute
 * la surface de la fenêtre (WIN_W x WIN_H). Cette fonction est appelée en 
 * début de chaque frame pour éviter les traces des dessins précédents.
 * 
 * PARAM : aucun
 * RETOUR : rien
 */
void clear_screen() {
    MLV_draw_filled_rectangle(0, 0, WIN_W, WIN_H,
                              MLV_rgba(0, 0, 0, 255));
}


/**
 * ============================================================================
 * FONCTION draw_grid
 * ============================================================================
 * Dessine la grille Sudoku 9x9 avec un double système de lignes :
 * - Lignes FINES (gris clair) : quadrillage complet toutes les cellules
 * - Lignes ÉPAISSES (blanc) : bordures des 9 blocs 3x3 uniquement (lignes/cols 0,3,6)
 * Cela crée un contraste visuel fort pour bien distinguer les régions Sudoku.
 * 
 * PARAM : aucun
 * RETOUR : rien (dessine directement à l'écran)
 */
void draw_grid(void) {
    int i;
    
    for (i = 0; i <= GRID_SIZE; i++) {
        MLV_draw_line(
            GRID_X, GRID_Y + i * CELL,
            GRID_X + GRID_SIZE * CELL, GRID_Y + i * CELL,
            MLV_rgba(150, 150, 150, 255)  
        );
        MLV_draw_line(
            GRID_X + i * CELL, GRID_Y,
            GRID_X + i * CELL, GRID_Y + GRID_SIZE * CELL,
            MLV_rgba(150, 150, 150, 255)  
        );
    }
    
    int thick_color = MLV_rgba(255, 255, 255, 255); 
    int block;
    
    for (block = 0; block <= 3; block += 3) {
        MLV_draw_line(
            GRID_X, GRID_Y + block * CELL,
            GRID_X + GRID_SIZE * CELL, GRID_Y + block * CELL,
            thick_color
        );
        MLV_draw_line(
            GRID_X, GRID_Y + (block + 3) * CELL,
            GRID_X + GRID_SIZE * CELL, GRID_Y + (block + 3) * CELL,
            thick_color
        );
    }
    
    for (block = 0; block <= 3; block += 3) {  
        MLV_draw_line(
            GRID_X + block * CELL, GRID_Y,
            GRID_X + block * CELL, GRID_Y + GRID_SIZE * CELL,
            thick_color
        );
        MLV_draw_line(
            GRID_X + (block + 3) * CELL, GRID_Y,
            GRID_X + (block + 3) * CELL, GRID_Y + GRID_SIZE * CELL,
            thick_color
        );
    }
}


/**
 * ============================================================================
 * FONCTION draw_numbers
 * ============================================================================
 * Affiche tous les chiffres présents dans la grille Sudoku (cases non-vides).
 * Chaque chiffre est centré dans sa cellule et affiché en blanc.
 * Les chiffres initiaux du fichier et ceux saisis par le joueur sont tous 
 * affichés de la même façon (pas de distinction visuelle).
 * 
 * PARAM : Board grid - la grille 9x9 contenant les valeurs (1-9 ou 0=vide)
 * RETOUR : rien
 */
void draw_numbers(Board grid) {
    int r, c;
    for (r = 0; r < GRID_SIZE; r++) {     
        for (c = 0; c < GRID_SIZE; c++) {  
            if (grid[r][c] != 0) {         
                char txt[2] = { '0' + grid[r][c], '\0' };  
                
                /* Centrage du texte dans la cellule :
                   x = bord gauche + colonne * taille + centre cellule - décalage texte */
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


/**
 * ============================================================================
 * FONCTION draw_picker
 * ============================================================================
 * Dessine le sélecteur de chiffres (grille 3x3 avec 1 à 9). 
 * - Fond gris foncé
 * - Grille blanche fine
 * - Chiffres 1-9 centrés dans chaque case
 * Le joueur clique dedans pour choisir un chiffre à placer.
 * 
 * PARAM : aucun
 * RETOUR : rien
 */
void draw_picker() {
    /* Fond gris foncé du picker */
    MLV_draw_filled_rectangle(
        PICKER_X, PICKER_Y,
        PICKER_SIZE * PICKER_CELL,
        PICKER_SIZE * PICKER_CELL,
        MLV_rgba(40, 40, 40, 255)
    );
    
    int i;
    /* Lignes horizontales du picker */
    for (i = 0; i <= PICKER_SIZE; i++) {
        MLV_draw_line(
            PICKER_X,
            PICKER_Y + i * PICKER_CELL,
            PICKER_X + PICKER_SIZE * PICKER_CELL,
            PICKER_Y + i * PICKER_CELL,
            MLV_rgba(255, 255, 255, 255)
        );
    }
    
    /* Lignes verticales du picker */
    for (i = 0; i <= PICKER_SIZE; i++) {
        MLV_draw_line(
            PICKER_X + i * PICKER_CELL,
            PICKER_Y,
            PICKER_X + i * PICKER_CELL,
            PICKER_Y + PICKER_SIZE * PICKER_CELL,
            MLV_rgba(255, 255, 255, 255)
        );
    }
    
    /* Affichage des chiffres 1 à 9 */
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


/**
 * ============================================================================
 * FONCTION draw_board
 * ============================================================================
 * Dessine l'ensemble de l'interface :
 * 1. Efface l'écran
 * 2. Grille vide
 * 3. Chiffres de la grille
 * 4. Curseur '?' rouge sur case sélectionnée (si vide)
 * 5. Picker de chiffres
 * 
 * PARAM : 
 *   Board grid     - grille Sudoku actuelle
 *   int sel_row    - ligne sélectionnée (-1 = aucune)
 *   int sel_col    - colonne sélectionnée (-1 = aucune)
 * RETOUR : rien
 */
void draw_board(Board grid, int sel_row, int sel_col) {
    clear_screen();
    draw_grid();
    draw_numbers(grid);

    /* Curseur '?' rouge uniquement sur case vide sélectionnée */
    if (sel_row >= 0 && sel_col >= 0 && grid[sel_row][sel_col] == 0) {
        char txt[2] = { '?', '\0' };
        MLV_draw_text(
            GRID_X + sel_col * CELL + CELL / 2 - 5,
            GRID_Y + sel_row * CELL + CELL / 2 - 10,
            txt,
            MLV_rgba(255, 0, 0, 255) 
        );

        draw_picker();
    }
}


/**
 * ============================================================================
 * FONCTION mouse_to_cell
 * ============================================================================
 * Convertit les coordonnées de la souris (pixels) en coordonnées de case 
 * Sudoku (0-8, 0-8). Retourne 1 si clic dans la grille, 0 sinon.
 * 
 * PARAM : 
 *   int mx, my     - position souris écran
 *   int* row       - ligne calculée (sortie)
 *   int* col       - colonne calculée (sortie)
 * RETOUR : 1 si clic dans grille valide, 0 sinon
 */
int mouse_to_cell(int mx, int my, int* row, int* col) {
    /* Vérif clic dans zone grille */
    if (mx < GRID_X || my < GRID_Y) return 0;

    mx -= GRID_X;  
    my -= GRID_Y;

    /* Vérif dans limites grille */
    if (mx >= GRID_SIZE * CELL || my >= GRID_SIZE * CELL) return 0;

    /* Conversion pixel -> case */
    *col = mx / CELL;
    *row = my / CELL;
    return 1;
}


/**
 * ============================================================================
 * FONCTION mouse_to_picker
 * ============================================================================
 * Détecte un clic dans le picker et retourne le chiffre cliqué (1-9).
 * Retourne 0 si clic hors picker.
 * 
 * PARAM : int mx, my - position souris écran
 * RETOUR : chiffre cliqué (1-9) ou 0 si hors picker
 */
int mouse_to_picker(int mx, int my) {
    /* Vérif limites picker */
    if (mx < PICKER_X || my < PICKER_Y) return 0;
    if (mx >= PICKER_X + PICKER_SIZE * PICKER_CELL) return 0;
    if (my >= PICKER_Y + PICKER_SIZE * PICKER_CELL) return 0;

    /* Conversion en coordonnées case picker 3x3 */
    int col = (mx - PICKER_X) / PICKER_CELL;
    int row = (my - PICKER_Y) / PICKER_CELL;

    /* Numéro du chiffre : ligne*3 + colonne + 1 */
    return row * 3 + col + 1; 
}
