#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* create_array(int size) {
    int* t = (int*) malloc(size * sizeof(int)); 
    assert(t != NULL);
    return t;
}

void display_array(int *t, int size) {
    int i = 0;
    printf("[");
    for (i = 0; i < size; i++) {
        printf("%d",t[i]);
        if (i < size-1) printf(", ");
    }
    printf("]\n");
}

void copy_array(int src[], int dst[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

void fill_random_array(int t[], int size, int max_value) {
    int i;
    for (i = 0; i<size; i++) {
        t[i] = rand()%max_value;
    }
}

/**
 * Initialises the array t with a random permutation of
 *   the values 0, 1, ..., size-1.
 * Uses the Fisher–Yates / Knuth shuffle:
 *   https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
void fill_random_permutation(int t[], int size) {
    int i, j, tmp;
    for (i = 0; i < size; i++)
        t[i] = i;

    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }
}
