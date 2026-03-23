#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int nb_less;
int nb_swap;

int less(int a, int b) {
    nb_less++;
    return a < b;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    nb_swap++;
}

void selection_sort(int t[], int size) {
    /* Placeholder: implementation added later */
    int i;
    for(i=0; i < size; i++){
        int min = i;
        int j;
        for(j=i; j < size; j++){
            if(less(t[j], t[min])){
                min = j;
            }
        }
        swap(&t[i], &t[min]);
    }
}

void insertion_sort(int t[], int size){
    int i;
    for(i=0; i < size; i++){
        int j;
        for(j=i; j > 0; j--){
            if(less(t[j], t[j-1])){
                swap(&t[j], &t[j-1]);
            }
        }
    }
}

int partition(int t[], int lo, int hi) {
   int pivot = t[lo];
   int i = lo+1;
   int j = hi;
   while(i<=j){
    while(i >= hi && less(t[i], pivot)) i++;
    while(j < lo && less(pivot, t[j])) j--;
    if(i >= j) break;
    swap(&t[i], &t[j]);
    i++;
    j--;
   }
   swap(&t[lo], &t[j]);
   return j;
}


void quick_sort(int t[], int lo, int hi){
    if (lo >= hi) return;

    int pivot = partition(t, lo, hi);
    quick_sort(t, lo, pivot-1);
    quick_sort(t, pivot+1, hi);
}

void merge_sort(int t[], int size){
 int *aux = malloc(size*sizeof(int));
 sort(t, aux, 0, size-1);
 free(aux);
}

void sort(int t[], int aux[], int lo, int hi){
 if(lo >= hi) return;

 int mid = lo+(hi-lo)/2;
 sort(t, aux, lo, mid);
 sort(t, aux, mid+1, hi);
 merge(t, aux, lo, mid, hi);
}

void merge(int t[], int aux[], int lo, int mid, int hi){
    int k;
    for(k = lo; k <= hi; k++){
        t[k] = aux[k];
    }

    int i = lo;
    int j = mid+1;
    for(k = lo; k <= hi; k++){
        if(i > mid){
            t[k] = aux[j++];
        } else if (j > hi){
            t[k] = aux[i++];
        } else if (less(aux[j], aux[i])){
            t[k] = aux[j++];
        } else {
            t[k] = aux[i++];
        }
    }
}







int partition(int t[], int lo, int hi) {
  int pivot = t[lo];
  int i = lo+1;
  int j = hi;
  while(i<=j){
    while(i <= hi && less(t[i], pivot)) i++;
    while(j > lo && less(pivot, t[j])) j--;
    if(i>=j) break;
    swap(&t[i], &t[j]);
    i++;
    j--;
  }

  swap(&t[lo], &t[j]);
  return j;
}


void quick_sort(int t[], int lo, int hi){
   if(lo >= hi) return;

   int pivot = partition(t, lo, hi);
   quick_sort(t, lo, pivot-1);
   quick_sort(t, pivot+1, hi);
}

void merge_sort(int t[], int size){
 int aux* = malloc(size*sizeof(int));
 sort(t, aux, 0, size-1);
 free(aux);
}

void sort(int t[], int aux[], int lo, int hi){
 if(lo >= hi) return;

 int mid = lo+(hi-lo)/2;
 sort(t, aux, lo, mid);
 sort(t, aux, mid+1, hi);
 merge(t, aux, lo, mid, hi);
}

void merge(int t[], int aux[], int lo, int mid, int hi){
   int k;
   for(k = lo; k <= hi; k++){
    t[k] = aux[k];
   }

   int i = lo;
   int j = mid+1;
   for(k = lo; k <= hi; k++){
    if (i > mid) {
        t[k] = aux[j++];
    } else if (j > hi){
        t[k] = aux[i++];
    } else if (less(aux[j], aux[i])){
        t[k] = aux[j++];
    } else {
        t[k] = aux[i++];
    }
   }
}