#ifndef ARRAY_H
#define ARRAY_H

/* Allocates an integer array of the given size */
int* create_array(int size);

/* Displays the array t of length size on standard output */
void display_array(int t[], int size);

/* Copies size elements from src into dst (dst must be allocated) */
void copy_array(int src[], int dst[], int size);

/* Fills the array t with random values in [0, max_value) */
void fill_random_array(int t[], int size, int max_value);

/* Fills t with a random permutation of 0, 1, ..., size-1 */
void fill_random_permutation(int t[], int size);

#endif /* ARRAY_H */
