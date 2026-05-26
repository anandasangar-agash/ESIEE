#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noeud{
  char* nom;
  struct noeud* fg;
  struct noeud* fd;
}Noeud;

Noeud* alloue_noeud(char* nom){

    Noeud* noeud = malloc(sizeof(Noeud));

    if(noeud == NULL) return NULL;

    noeud->nom = malloc((strlen(nom)+1)*sizeof(char));
    if(noeud->nom == NULL) return NULL;

    strcpy(noeud->nom, nom);
    noeud->fd = NULL;
    noeud->fg = NULL;

    return noeud;
}

char** char_tab2d(int nb_line, int nb_col){

    char** tab = malloc(nb_line*sizeof(char*));
    if(tab == NULL) return NULL;
    int i;
    for(i = 0; i < nb_line; i++){
        tab[i] = malloc(nb_col*sizeof(char));
        if(tab[i] == NULL) return NULL;
        int j;
        for(j=0; j < nb_col; j++){
            tab[i][j] = 'v';
        }
    }

    return tab;
}


int has_pattern(unsigned int n){
    int i;
    for(i = 0; i < 8*sizeof(unsigned int) -3; i++){
        if( ((n >> i) & (unsigned int)15) == (unsigned int)3){
            return 1;
        }
    }
    return 0;
}

int make_date(void){

    unsigned long int date = 0;

    date |= (22 & 0b111111);
    date |= (4 & 0b111111) << 6;
    date |= (988 & 0b11111111111111111111) << 12;

    return (int) date;
}

int make_date(void){

    return (988 << 12) | (4 << 6) | 22;
}