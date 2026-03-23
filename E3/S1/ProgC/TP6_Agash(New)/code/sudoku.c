#include <stdio.h>
#include "sudoku.h"


/**
 * ============================================================================
 * FONCTION initialize_empty_board
 * ============================================================================
 * Initialise une grille Sudoku 9x9 en mettant toutes les cases à 0 (vide).
 * Cette grille vide servira de base avant lecture d'un fichier ou pour 
 * un nouveau jeu.
 * 
 * PARAM : Board board - référence vers la grille à initialiser
 * RETOUR : rien (modifie board en place)
 */
void initialize_empty_board(Board board) {
    int i, j;
    for (i = 0; i < 9; i++)           
        for (j = 0; j < 9; j++)       
            board[i][j] = 0;        
}


/**
 * ============================================================================
 * FONCTION print_board
 * ============================================================================
 * Affiche la grille Sudoku dans le terminal avec un formatage lisible :
 * - Bordures horizontales avec "-----"
 * - Séparateurs verticaux "|" entre cases
 * - Espaces "." pour les cases vides
 * - Chiffres pour les cases remplies
 * 
 * PARAM : Board board - la grille à afficher
 * RETOUR : rien (sortie console)
 */
void print_board(Board board) {
    printf("-------------------------------------\n"); 

    int i, j;
    for (i = 0; i < 9; i++) {         
        printf("| ");                  
        
        for (j = 0; j < 9; j++) {     
            if (board[i][j] == 0)     
                printf(" ");          
            else                     
                printf("%d", board[i][j]);
            
            printf(" | ");            
        }
        
        printf("\n");                
        printf("-------------------------------------\n"); 
    }
}


/**
 * ============================================================================
 * FONCTION is_valid
 * ============================================================================
 * Vérifie si une valeur peut être placée dans une case donnée de la grille.
 * Teste 3 contraintes Sudoku :
 * 1. Pas de doublon dans la ligne
 * 2. Pas de doublon dans la colonne  
 * 3. Pas de doublon dans le bloc 3x3
 * 
 * PARAM :
 *   Board board - grille actuelle
 *   int row     - ligne cible (0-8)
 *   int col     - colonne cible (0-8)
 *   int val     - valeur à tester (1-9)
 * RETOUR : 1 si valide, 0 si conflit
 */
int is_valid(Board board, int row, int col, int val) {
    int i, j;
    
    if (val < 1 || val > 9) {
        return 0;
    }
   
    for (i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return 0;
        }
    }
    
    for (i = 0; i < 9; i++) {
        if (board[i][col] == val) {
            return 0;
        }
    }
    
    int startRow = row - (row % 3);    
    int startCol = col - (col % 3);   
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (startRow + i == row && startCol + j == col) {
                continue;
            }
            if (board[startRow + i][startCol + j] == val) {
                return 0;
            }
        }
    }
    
    return 1;
}


/**
 * ============================================================================
 * FONCTION is_full
 * ============================================================================
 * Vérifie si la grille Sudoku est complètement remplie (victoire).
 * Parcours toutes les cases : si une case est à 0, la grille n'est pas finie.
 * 
 * PARAM : Board board - grille à tester
 * RETOUR : 1 si toutes cases remplies, 0 s'il reste des cases vides
 */
int is_full(Board board) {
    int i, j;
    for (i = 0; i < 9; ++i) {     
        for (j = 0; j < 9; ++j) { 
            if (board[i][j] == 0) {  
                return 0;          
            }
        }
    }
    return 1;  
}
