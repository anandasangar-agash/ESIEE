#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "code.h"

#define POP_SIZE 10

void random_key(Bitkey* k){
    for(int i = 0; i < NB_OCT; i++){
        k->values[i] = rand() % 256;
    }
}

typedef struct {
    Bitkey key;
    float fitness;
} Individual;

int compare(const void* a, const void* b){
    float f1 = ((Individual*)a)->fitness;
    float f2 = ((Individual*)b)->fitness;
    return (f2 > f1) - (f2 < f1);
}

void crossover(Bitkey* child, Bitkey* p1, Bitkey* p2, Bitkey* p3){
    for(int i = 0; i < NB_OCT; i++){
        child->values[i] = 0;

        for(int bit = 0; bit < 8; bit++){
            int b1 = (p1->values[i] >> bit) & 1;
            int b2 = (p2->values[i] >> bit) & 1;
            int b3 = (p3->values[i] >> bit) & 1;

            int sum = b1 + b2 + b3;

            if(sum >= 2)
                child->values[i] |= (1 << bit);
        }
    }
}


void generate_generation(Bitkey* result, int depth){
    if(depth == 0){
        random_key(result);
        return;
    }

    Individual pop[POP_SIZE];


    for(int i = 0; i < POP_SIZE; i++){
        generate_generation(&pop[i].key, depth - 1);
        pop[i].fitness = fitness_key(&pop[i].key);
    }

    qsort(pop, POP_SIZE, sizeof(Individual), compare);

    crossover(result, &pop[0].key, &pop[1].key, &pop[2].key);
}

int main(){
    srand(time(NULL));

    Bitkey best;

    while(1){
        generate_generation(&best, 6);

        float f = fitness_key(&best);
        printf("Fitness: %f\n", f);

        if(f >= 100.0){
            printf("KEY FOUND!\n");
            enter_the_matrix(&best);
            break;
        }
    }

    return 0;
}