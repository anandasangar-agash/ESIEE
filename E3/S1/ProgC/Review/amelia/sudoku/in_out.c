#include <stdio.h>

#include "in_out.h"

int fread_board(const char* file, Board board){
    FILE* f;
    int i,j;
    int entry;

    f = fopen(file, "r");
    if (f == NULL){
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
        return 0;
    }
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (fscanf(f, "%d", &entry) != 1) {
                fprintf(stderr, "Erreur de lecture du fichier\n");
                fclose(f);
                return 0;
            }
            board[i][j] = entry;
        }
    }
    fclose(f);
    return 1;
}
