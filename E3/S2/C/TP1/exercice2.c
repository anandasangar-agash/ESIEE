#include <stdio.h>
#include <stdlib.h>

char** create_tab(int n, int m){
    int i;
    char** t;
    if((t=(char**)malloc(n*sizeof(char*))) == NULL){
        fprintf(stderr, "Not enough memory!\n");
    }
    for(i=0; i<n; i++){
        if((t[i]=(char*)malloc(m*sizeof(char))) == NULL){
            fprintf(stderr, "Not enough memory!\n");
        }
    }
    return t;
}

void free_tab(char** t, int n){
    if (t==NULL) return;
    int i;
    for(i=0; i<n; i++){
        if(t[i] != NULL){
            free(t[i]);
        }
    }
    free(t);
}

void init_tab(char **tab, int n, int m){

   int i, j;
   for(i=0; i<n; i++){
    for(j=0; j<m; j++){
        tab[i][j] = 'a' + ((i + j) % 26);
    }
   }
}

void print_tab(char **tab, int n, int m){
    int i, j;
   for(i=0; i<n; i++){
    for(j=0; j<m; j++){
       printf("%c ", tab[i][j]);
    }
    printf("\n");
   }
}


int main(int argc, char *argv[]){

    int n, m;
    printf("Donnez deux dimensions entières : ");

    scanf("%d %d", &n, &m);
    printf("%d %d\n", n, m);

    char** tab = create_tab(n, m);

    init_tab(tab, n, m);

    print_tab(tab, n, m);

    free_tab(tab, n);

    return 0;
}