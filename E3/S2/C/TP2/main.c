#include <stdio.h>
#include <MLV/MLV_all.h>
#include "plateau.h"


int main(int argc, char* argv[]){

    Plateau P;

    MLV_Image *image;
    MLV_Image* morceaux[NB_COL][NB_LIG];

    int i, j;

    InitialisationPlateau(&P);
    
    MLV_create_window("Jeu de Taquin", "Jeu de Taquin", 512, 512);

    image = MLV_load_image("unnamed.png");
    int w = MLV_get_image_width(image) / NB_COL;
    int h = MLV_get_image_height(image) / NB_LIG;

    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){
            morceaux[i][j] = MLV_copy_partial_image(
                image,
                i * w, j * h,  
                w, h           
            );
        }
    }

    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){
            MLV_draw_image(morceaux[i][j], i * w, j * h);
            int epaisseur = 3;  
            int k;
            for(k = 0; k < epaisseur; k++){
                MLV_draw_rectangle(
                    i * w + k,
                    j * h + k,
                    w - 2*k,
                    h - 2*k,
                    MLV_COLOR_BLACK
                );
            }
        }
    }

    i = MLV_get_random_integer(0, NB_COL);
    j = MLV_get_random_integer(0, NB_LIG);
    MLV_draw_filled_rectangle(i * w, j * h, w, h, MLV_COLOR_BLACK);

    MLV_actualise_window();
    MLV_wait_seconds(10);
    
    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){
            MLV_free_image(morceaux[i][j]);
        }
    }

    MLV_free_window();
    return 0;
}