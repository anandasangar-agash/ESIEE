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
    int i1, j1, i2, j2;
    Carre tmp;
    int k;

    for (k = 0; k < NB_COL * NB_LIG * 10; k++) {
        i1 = rand() % NB_COL;
        j1 = rand() % NB_LIG;

        i2 = rand() % NB_COL;
        j2 = rand() % NB_LIG;

        tmp = P->bloc[i1][j1];
        P->bloc[i1][j1] = P->bloc[i2][j2];
        P->bloc[i2][j2] = tmp;

        if (P->vide.col == i1 && P->vide.lig == j1) {
            P->vide.col = i2;
            P->vide.lig = j2;
        }
        else if (P->vide.col == i2 && P->vide.lig == j2) {
            P->vide.col = i1;
            P->vide.lig = j1;
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