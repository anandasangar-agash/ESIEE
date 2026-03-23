#include <stdio.h>
#include "sudoku.h"

void initialize_empty_board(Board grid){

    int i, j;
    for(i=0; i<MAIN_GRID_LENGTH; i++){
        for(j=0; j<MAIN_GRID_LENGTH; j++){
            grid[i][j] = 0;
        }
    }
}

void print_board(Board grid){

    printf("------------------------------------- \n");
    /* Parcours du tab */
    int i, j;
    for(i=0; i<MAIN_GRID_LENGTH; i++){
        printf("| ");
        for(j=0; j<MAIN_GRID_LENGTH; j++){ 
            if(grid[i][j] != 0){
                printf("%d", grid[i][j]);
            } else{
                printf(" ");
            }
            printf(" | ");
        }
        printf("\n");
        printf("------------------------------------- \n");
    }
    printf("\n");

}

void print_second_board(Second_board grid){

    printf("-------------\n");
    /* Parcours du tab */
    int i, j;
    for(i=0; i<SECOND_GRID_LENGTH; i++){
        printf("| ");
        for(j=0; j<SECOND_GRID_LENGTH; j++){ 
            if(grid[i][j] != 0){
                printf("%d", grid[i][j]);
            } else{
                printf(" ");
            }
            printf(" | ");
        }
        printf("\n");
        printf("-------------\n");
    }
    printf("\n");

}

int insertion_possible(Board grid, unsigned int index_i, unsigned int index_j,
    
    unsigned int val, unsigned int max){
    int i, j;

    /* Ligne */
    for(i=0; i<max; i++){
        if(grid[i][index_j] == val) return 0;
    }

    /* Colonne */
    for(j=0; j<max; j++){
        if(grid[index_i][j] == val) return 0;
    }

    /* Carré 3*3 */
    int start_i = (index_i / SECOND_GRID_LENGTH) * SECOND_GRID_LENGTH;
    int start_j = (index_j / SECOND_GRID_LENGTH) * SECOND_GRID_LENGTH;
    for(i = start_i; i < start_i + SECOND_GRID_LENGTH; i++){
        for(j = start_j; j < start_j + SECOND_GRID_LENGTH; j++){
            if(grid[i][j] == val) return 0;
        }
    }

    return 1;
}

int grille_remplie(Board grid, unsigned int max){
    int i, j;
        for(i=0; i<max; i++){
            for(j=0; j<max; j++){
                if(grid[i][j] == 0) return 0;
            }
        }
    return 1;
}

int fread_board(const char* file, Board board){
  FILE* f;
  int i,j;
  int entry;

  f = fopen(file, "r");
  if (f == NULL){
    fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
    return 0;
  }

  for (i=0 ; i<MAIN_GRID_LENGTH ; i++){
    for (j=0 ; j<MAIN_GRID_LENGTH ; j++){
      fscanf(f, "%d", &entry);
      board[i][j] = entry;
    }
  }
  return 1;
}


/*
Si pleine, affiche
Sinon, recherche une case libre. Une fois trouvée :
    Si possible de mettre une val entre 1 et MAIN_GRID_LENGTH on on rappelle
    sinon on return et on retire la dernière val mise

*/
void recurs_remplir_grille(Board grid, unsigned int max){

    if(grille_remplie(grid, max)){
        print_board(grid);
    }
    else{
        int i, j;
        for(i=0; i<max; i++){
            for(j=0; j<max; j++){
                if(grid[i][j] == 0){

                    /* On essaye d'insérer toutes les val possibles */
                    int val;
                    for(val=1; val<=max; val++){
                        /* On regarde si on peut mettre la val.
                        Sinon, on return, ce n'est pas la bonne possibilité.
                        Pour val possible, il ne doit pas y avoir la même val
                        dans la grille sur la même ligne + colonne + carré de SECOND_GRID_LENGTH*SECOND_GRID_LENGTH */
                        if(insertion_possible(grid, i, j, val, max)){
                            grid[i][j] = val;
                            recurs_remplir_grille(grid, max);
                            grid[i][j] = 0;
                        }
                    }
                    /* On ne cherche que la 1e case nulle, pas besoin d'itérer
                    sur les autres */
                    return;
                }
            }
        }
    }
}