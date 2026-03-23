#ifndef VISUALARRAY_H
#define VISUALARRAY_H
#include <MLV/MLV_all.h>

#define BACKGROUND_COLOR MLV_COLOR_BLACK
#define FOREGROUND_COLOR MLV_COLOR_WHITE

/**
 * Initialize the visualization linked to array arr.
 * Opens a window and displays the array.
 *
 * The window width is adjusted to a multiple of size.
 * If bar != 0, values are drawn as bars; otherwise as points.
 */
void init_visual(int *arr, int size, int preferred_width, int bar);

/**
 * Free memory and close the window. 
 * Does not free the memory used by the linked array.
 */
void free_visual();

/**
 * Visualize the entire array in the window.
 */
void visualize();

/**
 * Visualize and pause for a given number of milliseconds.
 */
void visualize_pause(int ms);

/** 
 * Draw the positions pos[0], ..., pos[n-1] using color c.
 * Assumes 0 <= pos[i] < size for all i.
 */
void visualize_positions(int pos[], int n, MLV_Color c);

/**
 * Same as visualize_positions, then pause.
 */
void visualize_positions_pause(int pos[], int n, MLV_Color c, int ms);

/**
 * Convenience function: draw the two positions i and j using color c.
 * Assumes 0 <= i, j < size.
 */
void visualize_2_positions(int i, int j, MLV_Color c);

/**
 * Same as visualize_2_positions, then pause.
 */
void visualize_2_positions_pause(int i, int j, MLV_Color c, int ms);

#endif /* VISUALARRAY_H */
