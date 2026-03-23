#ifndef SORT_H
#define SORT_H

/* Returns non-zero if a is strictly less than b */
int less(int a, int b);

/* Swaps the values pointed to by a and b */
void swap(int *a, int *b);

/* Sorts the array t of length size using selection sort */
void selection_sort(int t[], int size);

/* Sorts the array t of length size using insertion sort */
void insertion_sort(int t[], int size);

/* Sorts the array t of length size using quick sort */
void quick_sort(int t[], int lo, int hi);

#endif /* SORT_H */
