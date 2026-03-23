#include <stdio.h>

int main(int argc, char* argv[]){
    int a,b;
    printf("Entrez vos nombre :");
    scanf("%d %d", &a, &b);
    int c = a + b;
    printf("Le résultat est %d \n", c);
    printf("%d", argc);
    return 0;
}