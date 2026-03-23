#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "array.h"
#include "visualarray.h"

/* Visualization of Bubble sort using bars
 * https://en.wikipedia.org/wiki/Bubble_sort
 */

#define MAX_SIZE 15
#define WIDTH 640

#define STEP_DELAY 500

void bubble_sort_simple(int tab[], int size) {
    int i, k;
    for (i = 0; i < size; i++) {
        for (k = size-1; k > i; k--) {

            if (less(tab[k], tab[k-1])) {

                /* Wrong order: visualize in RED */
                visualize_2_positions_pause(k-1, k, MLV_COLOR_RED, STEP_DELAY);

                swap(&tab[k-1], &tab[k]);

            }

            /* The pair is now in correct order (GREEN) */
            visualize_2_positions_pause(k-1, k, MLV_COLOR_GREEN, STEP_DELAY);

        }
    }

    /* Final visualization: fully sorted array */
    visualize();
}

int main(void) {

    int *tab = create_array(MAX_SIZE);
    fill_random_permutation(tab, MAX_SIZE);

    /* open a window and link tab to it */
    init_visual(tab, MAX_SIZE, WIDTH, 1);

    bubble_sort_simple(tab, MAX_SIZE);
    MLV_wait_milliseconds(2000);

    /* close the window */
    free_visual();

    free(tab);

    return EXIT_SUCCESS;
}
