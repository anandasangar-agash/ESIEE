#include <stdio.h>

#include "sort.h"
#include "array.h"

#define MAX_SIZE 10

extern int nb_less;
extern int nb_swap;





int main(void){

    int size = MAX_SIZE;
    nb_less = 0;
    nb_swap = 0;

    int* tab = NULL;

    tab = create_array(size);
    fill_random_array(tab, size, 100);

    selection_sort(tab, size);

    printf("SELECTION\n");
    printf("%d comparaisons\n", nb_less);
    printf("%d échanges\n", nb_swap);

    nb_less = 0;
    nb_swap = 0;

    tab = create_array(size);
    fill_random_array(tab, size, 100);

    insertion_sort(tab, size);

    printf("INSERTION\n");
    printf("%d comparaisons\n", nb_less);
    printf("%d échanges\n", nb_swap);

    nb_less = 0;
    nb_swap = 0;

    tab = create_array(size);
    fill_random_array(tab, size, 100);

    quick_sort(tab, 0, size-1);

    printf("QUICKSORT\n");
    printf("%d comparaisons\n", nb_less);
    printf("%d échanges\n", nb_swap);

}