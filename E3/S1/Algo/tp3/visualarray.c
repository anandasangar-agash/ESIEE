#include "visualarray.h"
#include <stdlib.h>

/**
 * Stores all information related to the visualization.
 *
 * arr           : linked array
 * size          : array size
 * min_value     : minimum value in arr
 * max_value     : maximum value in arr
 * width         : window width (in pixels)
 * element_width : width of one bar / point
 * bar           : non-zero for bars, 0 for points
 */
typedef struct {
    int *arr;
    int size;
    int min_value;
    int max_value;
    int width;
    int element_width;
    int bar;
} visual;

/* Global visualization state to simplify life (and student code) */
visual* v;


/**
 * Initializes the visualization.
 * Must be called before any visualize_* function.
 */
void init_visual(int *arr, int size, int preferred_width, int bar) {
    v = (visual *)malloc(sizeof(visual));
    v->arr = arr;
    v->size = size;
    v->bar = bar;

    int i, min = arr[0], max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    v->min_value = min;
    v->max_value = max;
    v->element_width = preferred_width/size;
    v->width = v->element_width*size;

    MLV_create_window("Visualarray", "Visualarray", v->width, v->width);
    visualize();
}


/**
 * Closes the window and frees visualization data.
 * Does NOT free the linked array.
 */
void free_visual() {
    free(v);
    MLV_free_window();
}


/* Internal helper: draw one array element at position x */
void draw_pos(int x, int y, MLV_Color col) {
    int span = v->max_value-v->min_value;
    if (v->bar) {
        MLV_draw_filled_rectangle(
                    v->element_width*x, 
                    (v->element_width*(v->size-1)*(v->max_value+v->min_value-y))/span,
                    (v->element_width > 2 ? v->element_width*0.75 : v->element_width),
                    (v->element_width*(v->size-1)*(y-v->min_value+1))/span,
                    col);
    }
    else {
        MLV_draw_filled_rectangle(
                    v->element_width*x, 
                    (v->element_width*(v->size-1)*(v->max_value+v->min_value-y))/span,
                    v->element_width,
                    v->element_width,
                    col);
    }
}


/* Draws the array without updating the window */
void visualize_array() {
    MLV_draw_filled_rectangle(
                0, 
                0, 
                v->width,
                v->width,
                BACKGROUND_COLOR);
    int i;
    for (i = 0; i < v->size; i++)
        draw_pos(i, v->arr[i], FOREGROUND_COLOR);
}


/* Draws the array and updates the window */
void visualize() {
    visualize_array();
    MLV_actualise_window();
}

void visualize_pause(int ms) {
    visualize();
    MLV_wait_milliseconds(ms);
}

void visualize_positions(int pos[], int n, MLV_Color c) {
    visualize_array();
    int i;
    for (i = 0; i < n; i++)
        draw_pos(pos[i], v->arr[pos[i]], c);
    MLV_actualise_window();
}

void visualize_positions_pause(int pos[], int n, MLV_Color c, int ms) {
    visualize_positions(pos, n, c);
    MLV_wait_milliseconds(ms);
}

void visualize_2_positions(int i, int j, MLV_Color c) {
    int pos[2];
    pos[0] = i;
    pos[1] = j;
    visualize_positions(pos, 2, c);
}

void visualize_2_positions_pause(int i, int j, MLV_Color c, int ms) {
    visualize_2_positions(i, j, c);
    MLV_wait_milliseconds(ms);
}
