#include <stdio.h>
#include <stdlib.h>

/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }

  new_tab[size] = -1;
  return new_tab;
}

/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}

int array_size(int* array){
    if (array[0] == -1) return 0;

    int size = 0;
    while(array[size] != -1){
        size = size + 1;
    }
    return size;
}

void print_array(int* array){

    if(array[0] == -1){
        printf("Votre tableau est vide !");
    }
    int i;
    for(i=0; array[i] != -1; i++){
        printf("%d ", array[i]);
    }
}

int are_arrays_equal(int* first, int* second){

    int size_tab1 = array_size(first);
    int size_tab2 = array_size(second);

    if (size_tab1 != size_tab2){
        printf("Vos tableaux n'ont pas la même taille !");
        return 0;
    }
    int i;
    for(i=0; i < size_tab1; i++){
        if(first[i] != second[i]){
            printf("Vos tableaux n'ont pas les mêmes contenus !");
            return 0;
        }
    }
    printf("Vos tableaux possèdent les mêmes contenus !");
    return 1;
}

int* copy_array(int* array){
    if (array[0] == -1) return 0;

    int size = array_size(array);

    int* copy = allocate_integer_array(size);
    if (copy == NULL) return NULL;
    int i;
    for (i = 0; i < size; i++) {
        copy[i] = array[i];
    }

    return copy;
}

int* fill_array(void){
    int size;

    printf("Entrez la longueur du tableau : ");
    scanf("%d", &size);

    if (size < 0) {
        printf("La taille doit être positive.\n");
        return 0;
    }

    int* new_tab = allocate_integer_array(size);
    int i;
    for (i = 0; i < size; i++){
        int a;
        printf("Entrez un entier positif #%d : ", i + 1);
        scanf("%d", &a);
        new_tab[i] = a;
    }

    return new_tab;
}

int* random_array(int size, int max_entry){

    int* new_tab = allocate_integer_array(size);

    int i = 0;
    while (i < size){
        int value = rand() % max_entry;
        new_tab[i] = value;
        i++;
    }

    return new_tab;
}

int* concat_array(int* first, int* second){

    int size_tab1 = array_size(first);
    int size_tab2 = array_size(second);
    int new_size = size_tab1 + size_tab2;

    int* tab = allocate_integer_array(new_size);

    int i;
    for(i=0; i < size_tab1; i++){
        tab[i] = first[i];
    }

    for(i=0; i < size_tab2; i++){
        tab[i + size_tab1] = second[i];
    }

    return tab;
}

int* merge_sorted_arrays(int* first, int* second){

    int size1 = array_size(first);
    int size2 = array_size(second);

    int* merged = allocate_integer_array(size1 + size2);
    if (merged == NULL) return NULL;

    int i = 0;
    int j = 0;
    int k = 0; 

    while (i < size1 && j < size2) {
        if (first[i] <= second[j]) {
            merged[k++] = first[i++];
        } else {
            merged[k++] = second[j++];
        }
    }

    while (i < size1) {
        merged[k++] = first[i++];
    }

    while (j < size2) {
        merged[k++] = second[j++];
    }

    return merged;
}

void split_arrays(int* array, int** first, int** second) {
    int size = array_size(array);

    int size1 = size / 2 + (size % 2); 
    int size2 = size - size1;        

    *first  = allocate_integer_array(size1);
    *second = allocate_integer_array(size2);

    if (*first == NULL || *second == NULL) {
        fprintf(stderr, "Erreur allocation\n");
        return;
    }
    int i;
    for (i = 0; i < size1; i++) {
        (*first)[i] = array[i];
    }

    for (i = 0; i < size2; i++) {
        (*second)[i] = array[size1 + i];
    }
}

int* merge_sort(int* array) {
    int size = array_size(array);

    if (size <= 1) {
        int* copy = copy_array(array);
        return copy;
    }

    int *first, *second;
    split_arrays(array, &first, &second);

    printf("Split array in two part :\n");
    print_array(array);
    printf("\n");
    print_array(first);
    printf("\n");
    print_array(second);
    printf("\n");

    int* sorted_first = merge_sort(first);
    int* sorted_second = merge_sort(second);

    free_integer_array(first);
    free_integer_array(second);

    printf("Merge the two following ones :\n");
    print_array(sorted_first);
    printf("\n");
    print_array(sorted_second);
    printf("\n");

    int* merged = merge_sorted_arrays(sorted_first, sorted_second);

    printf("=> ");
    print_array(merged);
    printf("\n");

    free_integer_array(sorted_first);
    free_integer_array(sorted_second);

    return merged;
}

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]) {
    /* 1. Remplir un tableau avec fill_array()*/
    printf("=== Test de fill_array() ===\n");
    int* user_tab = fill_array();
    printf("Tableau rempli par l'utilisateur : ");
    print_array(user_tab);
    printf("\nTaille : %d\n\n", array_size(user_tab));

    /* 2. Créer un tableau aléatoire*/
    printf("=== Test de random_array() ===\n");
    int* rand_tab = random_array(5, 10); 
    printf("Tableau aléatoire : ");
    print_array(rand_tab);
    printf("\nTaille : %d\n\n", array_size(rand_tab));

    /* 3. Copier un tableau*/
    printf("=== Test de copy_array() ===\n");
    int* copy_tab = copy_array(user_tab);
    printf("Copie du tableau utilisateur : ");
    print_array(copy_tab);
    printf("\nTaille : %d\n\n", array_size(copy_tab));

    /* 4. Concaténer deux tableaux*/
    printf("=== Test de concat_array() ===\n");
    int* concat_tab = concat_array(user_tab, rand_tab);
    printf("Concaténation : ");
    print_array(concat_tab);
    printf("\nTaille : %d\n\n", array_size(concat_tab));

    /* 5. Vérifier l'égalité de deux tableaux*/
    printf("=== Test de are_arrays_equal() ===\n");
    are_arrays_equal(user_tab, copy_tab); 
    printf("\n");
    are_arrays_equal(user_tab, rand_tab); 
    printf("\n\n");

    /* 6. Fusionner deux tableaux triés*/
    printf("=== Test de merge_sorted_arrays() ===\n");
    int* sorted1 = merge_sort(user_tab);
    int* sorted2 = merge_sort(rand_tab);
    int* merged_sorted = merge_sorted_arrays(sorted1, sorted2);
    printf("Fusion de deux tableaux triés : ");
    print_array(merged_sorted);
    printf("\nTaille : %d\n\n", array_size(merged_sorted));

    /* 7. Tri fusion d'un tableau aléatoire plus grand*/
    printf("=== Test de merge_sort() ===\n");
    int* big_rand_tab = random_array(20, 100);
    printf("Tableau aléatoire : ");
    print_array(big_rand_tab);
    printf("\n\n");

    int* sorted_big = merge_sort(big_rand_tab);
    printf("Tableau trié : ");
    print_array(sorted_big);
    printf("\n\n");

    /* Libération de la mémoire*/
    free_integer_array(user_tab);
    free_integer_array(rand_tab);
    free_integer_array(copy_tab);
    free_integer_array(concat_tab);
    free_integer_array(sorted1);
    free_integer_array(sorted2);
    free_integer_array(merged_sorted);
    free_integer_array(big_rand_tab);
    free_integer_array(sorted_big);

    return 0;
}

