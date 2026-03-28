#include "interface.h"

/**
 * ============================================================================
 * FONCTION decouper_image
 * ============================================================================
 * Découpe une image en plusieurs morceaux correspondant aux cases du taquin.
 * Chaque sous-image est stockée dans un tableau 2D.
 * 
 * PARAM :
 *   MLV_Image *image                        - image originale
 *   MLV_Image* morceaux[NB_COL][NB_LIG]     - tableau de sous-images
 *   int w                                   - largeur d'un morceau
 *   int h                                   - hauteur d'un morceau
 * RETOUR : rien (remplit le tableau morceaux)
 */
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

/**
 * ============================================================================
 * FONCTION dessiner_plateau
 * ============================================================================
 * Affiche le plateau du taquin à l'écran :
 * - Dessine chaque morceau d'image à la bonne position
 * - Dessine la case vide en noir
 * - Ajoute un contour autour de chaque case
 * 
 * PARAM :
 *   Plateau *P                              - plateau courant
 *   MLV_Image* morceaux[NB_COL][NB_LIG]     - images découpées
 *   int w                                   - largeur d'une case
 *   int h                                   - hauteur d'une case
 * RETOUR : rien (affichage graphique)
 */
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

/**
 * ============================================================================
 * FONCTION liberer_morceaux
 * ============================================================================
 * Libère la mémoire associée aux sous-images créées lors du découpage.
 * 
 * PARAM : 
 *   MLV_Image* morceaux[NB_COL][NB_LIG] - tableau d'images à libérer
 * RETOUR : rien (libère la mémoire)
 */
void liberer_morceaux(MLV_Image* morceaux[NB_COL][NB_LIG]){
    int i, j;
    for(i = 0; i < NB_COL; i++){
        for(j = 0; j < NB_LIG; j++){
            MLV_free_image(morceaux[i][j]);
        }
    }
}


/**
 * ============================================================================
 * FONCTION jouer_interface
 * ============================================================================
 * Fonction principale de l'interface graphique :
 * - Charge une image
 * - La découpe en morceaux
 * - Affiche le plateau en boucle
 * - Gère les clics souris pour déplacer les cases
 * - Détecte la victoire et affiche un message
 * 
 * PARAM : Plateau *P - plateau du jeu
 * RETOUR : rien (boucle de jeu graphique)
 */
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

        if(PlateauGagne(P)) {
            MLV_draw_text(10, 10, "YOU WIN !", MLV_COLOR_WHITE);
            MLV_actualise_window();
            MLV_wait_seconds(5);
            break;
        }

        MLV_actualise_window();

        MLV_wait_mouse(&x, &y);

        ChangeCarre(P, x / w, y / h);
    }

    liberer_morceaux(morceaux);
    MLV_free_image(image);
}