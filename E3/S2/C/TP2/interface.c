#include "interface.h"

/* Découpe l'image */
void decouper_image(MLV_Image *image, MLV_Image* morceaux[NB_COL][NB_LIG], int w, int h){
    int i, j;
    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){
            morceaux[i][j] = MLV_copy_partial_image(
                image,
                i * w, j * h,
                w, h
            );
        }
    }
}

/* Dessine le plateau */
void dessiner_plateau(Plateau *P, MLV_Image* morceaux[NB_COL][NB_LIG], int w, int h){
    int i, j, k;

    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){

            int src_i = P->bloc[i][j].col;
            int src_j = P->bloc[i][j].lig;

            if (i == P->vide.col && j == P->vide.lig) {
                MLV_draw_filled_rectangle(i * w, j * h, w, h, MLV_COLOR_BLACK);
            } else {
                MLV_draw_image(morceaux[src_i][src_j], i * w, j * h);
            }

            int epaisseur = 3;
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
}

/* Libère les images */
void liberer_morceaux(MLV_Image* morceaux[NB_COL][NB_LIG]){
    int i, j;
    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){
            MLV_free_image(morceaux[i][j]);
        }
    }
}

/* Fonction principale d'affichage */
void jouer_interface(Plateau *P){

    MLV_Image *image;
    MLV_Image* morceaux[NB_COL][NB_LIG];

    image = MLV_load_image("meta-knight.png");

    int w = MLV_get_image_width(image) / NB_COL;
    int h = MLV_get_image_height(image) / NB_LIG;

    int x, y;

    decouper_image(image, morceaux, w, h);

    while(1){

        MLV_clear_window(MLV_COLOR_WHITE);

        dessiner_plateau(P, morceaux, w, h);

        MLV_actualise_window();

        MLV_wait_mouse(&x, &y);

        ChangeCarre(P, x / w, y / h);
    }

    liberer_morceaux(morceaux);
    MLV_free_image(image);
}