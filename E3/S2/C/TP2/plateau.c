#include "plateau.h"

int InitialisationPlateau(Plateau *P)
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