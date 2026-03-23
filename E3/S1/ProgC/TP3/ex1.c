#include <stdio.h>

void fonction_iterative(int n){
        int i, s;

        for(i=n; i > 0; i--){
            s = i*i;
            printf("%d\n", s);
        }

        for(i=1; i<=n; i++){
            s = i*i;
            printf("%d\n", s);
        }
    }

void fonction_recursive(int n){

    if(n>=1){
        printf("%d\n", n*n);
        fonction_recursive(n-1);
        printf("%d\n", n*n);  
    }    
}
    
int main(int argc, char* argv[]){

    fonction_iterative(10);
    printf("-----------\n");
    fonction_recursive(5);
    printf("Hello world!\n");
    return 0;
}