#include "plateau.h"

void InitialisationPlateau(Plateau *P)
{
    int i, j;
    for(i = 0; i < NB_COL; i++)
    {
        for(j = 0; j < NB_LIG; j++)
        {
            ((P->bloc)[i][j]).col = i;
            ((P->bloc)[i][j]).lig = j;
        }
    }
    P->vide.col = NB_COL - 1;
    P->vide.lig = NB_LIG - 1;
}

void MelangerPlateau(Plateau *P) {
    int k;
    int dir;
    int new_col, new_lig;
    Carre tmp;

    for (k = 0; k < 120; k++) {

        dir = rand() % 4;

        new_col = P->vide.col;
        new_lig = P->vide.lig;

        if (dir == 0) new_lig--; 
        if (dir == 1) new_lig++;
        if (dir == 2) new_col--; 
        if (dir == 3) new_col++; 

        if (new_col >= 0 && new_col < NB_COL &&
            new_lig >= 0 && new_lig < NB_LIG) {

            tmp = P->bloc[new_col][new_lig];
            P->bloc[new_col][new_lig] = P->bloc[P->vide.col][P->vide.lig];
            P->bloc[P->vide.col][P->vide.lig] = tmp;

            P->vide.col = new_col;
            P->vide.lig = new_lig;
        }
    }
}

void ChangeCarre(Plateau *P, int col, int lig) {

    printf("Clicked on: %d, %d\n", col, lig);
    if ((col == P->vide.col && (lig == P->vide.lig - 1 || lig == P->vide.lig + 1)) ||
        (lig == P->vide.lig && (col == P->vide.col - 1 || col == P->vide.col + 1))) {
        Carre tmp = P->bloc[col][lig];
        P->bloc[col][lig] = P->bloc[P->vide.col][P->vide.lig];
        P->bloc[P->vide.col][P->vide.lig] = tmp;
        P->vide.col = col;
        P->vide.lig = lig;
    }
}