#include <stdio.h>

#define N 3 

void print_array(int buffer[], int max){
    int i;
    printf("[");
    for (i = 0; i < max; i++){
        printf("%d", buffer[i]);
        if (i < max - 1) printf(",");
    }
    printf("]\n");
}

void permutations(int buffer[], int current, int max){
    int i;
   
    if (current > max){
        print_array(buffer, max);
        return;
    }
   
    for (i = 0; i < max; i++){
        if (buffer[i] == 0){      
            buffer[i] = current;    
            permutations(buffer, current + 1, max); 
            buffer[i] = 0;          
        }
    }
}

int main(int argc, char* argv[]){
    int buffer[N] = {0};

    permutations(buffer, 1, N);
    return 0;
}
