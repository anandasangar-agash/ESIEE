#include <stdio.h>
#include <stdlib.h>

void init_tab(int *tab, int size){
    int i;

    for(i = 0; i < size; i++){
        tab[i] = i+1;
    }
}

void print_tab(int *tab, int size){
    int i;

    for(i = 0; i < size; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");

}


int main(int argc, char *argv[]){

    if (argc < 2) {
        printf("Veuillez entrer un nombre\n");
        return 1;
    }
    int taille = atoi(argv[1]);

    int *tab = malloc( taille * sizeof(int));

    init_tab(tab, taille);
    print_tab(tab, taille);

    free(tab);
    return 0;
}

