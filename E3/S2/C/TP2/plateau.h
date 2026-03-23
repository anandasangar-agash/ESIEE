#ifndef  __PLATEAU__
#define __PLATEAU__

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

int InitialisationPlateau(Plateau* P);

#endif