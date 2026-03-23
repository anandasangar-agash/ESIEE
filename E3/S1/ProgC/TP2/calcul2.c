#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("Les deux entiers sont : %d et %d\n", a, b);
    printf("La somme est : %d\n", a + b);
    return 0;
}