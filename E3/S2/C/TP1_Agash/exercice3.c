#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_tab(char **tab, int n) {
    for(int i = 0; i < n; i++) {
        printf("arg[%d] : %s\n", i, tab[i]);
    }
}

void free_tab(char **tab, int n) {
    for(int i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);
}

// Exercice 4(pas fini)
void print_info_zone(void* adr){
    size_t* info_adr = (size_t*)adr;
    
    printf("Zone a l'adresse : %p\n", adr);

    printf("%lu \n", info_adr[-1]);

    printf("%lu \n", info_adr[-2]);
}


int main(int argc, char *argv[]) {

    char **tab;
    
    tab = malloc(argc * sizeof(char*));

    for(int i = 0; i < argc; i++) {
        tab[i] = malloc(strlen(argv[i]) + 1);
        strcpy(tab[i], argv[i]);
    }

    print_tab(tab, argc);

    printf("---------------\n");

    print_info_zone(tab);

    free_tab(tab, argc);

    return 0;
}

