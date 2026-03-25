#ifndef  __PLATEAU__
#define __PLATEAU__

#include <stdlib.h>
#include <stdio.h>

#define NB_COL 4
#define NB_LIG 4

typedef struct
{
   int lig;
   int col;
} Carre;

typedef struct 
{
    Carre vide;
    Carre bloc[NB_COL][NB_LIG];
} Plateau;

void InitialisationPlateau(Plateau* P);

void MelangerPlateau(Plateau *P);

void ChangeCarre(Plateau *P, int col, int lig);

#endif