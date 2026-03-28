#include "plateau.h"


/**
 * ============================================================================
 * FONCTION InitialisationPlateau
 * ============================================================================
 * Initialise le plateau du taquin en position résolue :
 * - Chaque case contient ses coordonnées (i, j)
 * - La dernière case (en bas à droite) est définie comme case vide
 * 
 * PARAM : Plateau *P - pointeur vers le plateau à initialiser
 * RETOUR : rien (modifie le plateau en place)
 */
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


/**
 * ============================================================================
 * FONCTION MelangerPlateau
 * ============================================================================
 * Mélange le plateau en effectuant une série de déplacements aléatoires
 * valides de la case vide.
 * 
 * Contrairement à un mélange aléatoire simple, cette méthode garantit que
 * le taquin reste toujours résoluble.
 * 
 * Le mélange consiste à :
 * - Choisir une direction aléatoire (haut, bas, gauche, droite)
 * - Vérifier si le mouvement est valide
 * - Échanger la case vide avec un voisin
 * 
 * PARAM : Plateau *P - plateau à mélanger
 * RETOUR : rien (modifie le plateau en place)
 */
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


/**
 * ============================================================================
 * FONCTION ChangeCarre
 * ============================================================================
 * Permet de déplacer une case si elle est voisine de la case vide.
 * 
 * Conditions :
 * - La case cliquée doit être adjacente (haut, bas, gauche, droite)
 * - Si c'est le cas, elle est échangée avec la case vide
 * 
 * PARAM :
 *   Plateau *P - plateau courant
 *   int col    - colonne de la case sélectionnée
 *   int lig    - ligne de la case sélectionnée
 * RETOUR : rien (modifie le plateau si mouvement valide)
 */
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


/**
 * ============================================================================
 * FONCTION PlateauGagne
 * ============================================================================
 * Vérifie si le plateau est dans l'état résolu.
 * 
 * Le plateau est considéré comme résolu si chaque case contient
 * ses coordonnées d'origine (i, j).
 * 
 * PARAM : Plateau *P - plateau à vérifier
 * RETOUR : 
 *   1 si le plateau est résolu
 *   0 sinon
 */
int PlateauGagne(Plateau *P) {
    int i, j;

    for(i = 0; i < NB_COL; i++) {
        for(j = 0; j < NB_LIG; j++) {
            if (P->bloc[i][j].col != i || P->bloc[i][j].lig != j) {
                return 0;
            }
        }
    }
    return 1;
}