#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "plateau.h"
#include "interface.h"

int main(int argc, char* argv[]){

    Plateau P;

    srand(time(NULL));

    InitialisationPlateau(&P);
    MelangerPlateau(&P);

    MLV_create_window("Jeu de Taquin", "Jeu de Taquin", 512, 512);

    jouer_interface(&P);

    MLV_free_window();

    return 0;
}