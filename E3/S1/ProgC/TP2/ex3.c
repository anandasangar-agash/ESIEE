#include <stdio.h>

int fonction_iterative(int n){
    int i;
    for(i=n; i>0; i--){
        printf("%d ", i);
    };
    for(i=1; i<=n; i++){
        printf("%d ", i);
    };
    return 0;
};

int fonction_recurssive(int n){
   
    if(n>=1){
        printf("%d ", n);
        fonction_recurssive(n-1);
        
    }
    
    return 0;
};

int main(int argc, char* argv[]){
    int n = 10;
    fonction_iterative(n);
    printf("\n");
    fonction_recurssive(n);
    printf("\n");
    return 0;
}