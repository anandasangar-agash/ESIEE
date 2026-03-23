#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "sort.h"

#define MAX_VALUE 10000
#define MAX_SIZE 10

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int *create_random(int size){
    int *t = malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        t[i] = rand() % 100;
    }
    return t;
}

int *create_sorted(int size){
    int *t = malloc(size * sizeof(int));
    int i;
    for(i = 0; i <size; i++){
        t[i]=i;
    }
    return t;
}

int *create_reverse(int size){
    int *t = malloc(size * sizeof(int));
    int i;
    for(i=0; i < size; i++){
        t[i] = size - i;
    }
    return t;
}

int *create_almost_sorted(int size) {
    int *t = create_sorted(size);
    int swaps = size * 5 / 100;
    int i;
    for (i = 0; i < swaps; i++) {
        int a = rand() % size;
        int b = rand() % size;
        swap(&t[a], &t[b]);
    }
    return t;
}


int *create_few_values(int size) {
    int *t = malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        t[i] = rand() % 3;
    }
    return t;
}

int *copy_tab(int tab[], int size){
    int *t = malloc(size * sizeof(int));
    int i;
    for(i=0; i < size; i++){
        t[i] = tab[i];
    }
    return t;
}

int arrays_equal(const int *a, const int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void test_sort(const char *name, int *tab, int *ctab, int size) {
    printf("=== %s ===\n", name);

    printf("QSORT\nAvant\n");
    display_array(tab, size);
    qsort(tab, size, sizeof(int), compare);
    printf("Après\n");
    display_array(tab, size);

    printf("SELECTION\nAvant\n");
    display_array(ctab, size);
    selection_sort(ctab, size);
    printf("Après\n");
    display_array(ctab, size);

    if (arrays_equal(tab, ctab, size))
        printf("RESULTAT IDENTIQUE \n");
    else
        printf("RESULTAT DIFFERENT \n");
}


int main(void) {

    srand(time(NULL));

    int size = MAX_SIZE;
    int max_value = MAX_VALUE;

    /* working array */
    int* tab = NULL;

    /* allocate and initialize the array with random values */
    tab = create_array(size);
    fill_random_array(tab, size, max_value);

    display_array(tab, size);

    /* sort the array */
    selection_sort(tab, size);
    
    display_array(tab, size);
    
    /* free the array */
    free(tab);
    tab = NULL;

    int* tab0 = create_random(size);
    int* tab1 = create_sorted(size);
    int* tab2 = create_reverse(size);
    int* tab3 = create_almost_sorted(size);
    int* tab4 = create_few_values(size);
    int* ctab0 = copy_tab(tab0, size);
    int* ctab1 = copy_tab(tab1, size);
    int* ctab2 = copy_tab(tab2, size);
    int* ctab3 = copy_tab(tab3, size);
    int* ctab4 = copy_tab(tab4, size);

    test_sort("ALEATOIRE", tab0, ctab0, size);
    test_sort("TRIE", tab1, ctab1, size);
    test_sort("INVERSE", tab2, ctab2, size);
    test_sort("PRESQUE TRIE", tab3, ctab3, size);
    test_sort("PEU DE VALEURS", tab4, ctab4, size);

    free(tab0);
    free(tab1);
    free(tab2);
    free(tab3);
    free(tab4);
    free(ctab0);
    free(ctab1);
    free(ctab2);
    free(ctab3);
    free(ctab4);

    int* itab0 = create_random(size);
    printf("INSERTION\n");
    display_array(itab0, size);
    insertion_sort(itab0, size);
    display_array(itab0, size);

    int* qtab0 = create_reverse(200);
    printf("QUICKSORT\n");
    display_array(qtab0, 200);
    quick_sort(qtab0, 0, 200-1);
    display_array(qtab0, 200);

    return EXIT_SUCCESS;
}
