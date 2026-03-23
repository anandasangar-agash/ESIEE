#include <stdio.h>
#include <stdlib.h>

#define OBJECTIF 200000000

unsigned long long *cache;

void syracuse(unsigned long long n){

    if (n == 0) {
        printf("Le nombre doit être strictement positif\n");
        return;
    }
    printf("%llu ", n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;

        printf("%llu ", n);
    }
}

/* Fonction récursive mémoïsée */
unsigned long long longueur_vol(unsigned long long n){
    if (n == 1) {
        return 0;
    }
    
    /* Valeur déjà calculée */
    if (n < OBJECTIF && cache[n] != -1){
        return cache[n];
    }
        
    unsigned long long suivant;
    if(n % 2 == 0){
        suivant = n / 2;
    } else {
        suivant = 3*n + 1;
    }

    /* Mise en cache si possible */
    unsigned long long longueur = 1 + longueur_vol(suivant);

    if(n < OBJECTIF)
        cache[n] = longueur;

    return longueur;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Veuillez entrer un nombre\n");
        return 1;
    }

    unsigned long long val = strtoul(argv[1], NULL, 10);

    /* Allocation du cache */
    cache = malloc(OBJECTIF * sizeof(unsigned long long));
    unsigned long long i;

    /* Initialisation du cache */
    for (i = 0; i < OBJECTIF; i++)
        cache[i] = -1;

    unsigned long long longueur = longueur_vol(val);
    /*
    syracuse(val);
    */
    printf("Fly length : %llu\n", longueur);

    int max = 0;
    while (val != 1) {
        if (val % 2 == 0)
            val /= 2;
        else
            val = val * 3 + 1;
        if(val > max){
            max = val;
        }
    }
    printf("MAX_FLY : %d\n", max);

    free(cache);

    return 0;
}
