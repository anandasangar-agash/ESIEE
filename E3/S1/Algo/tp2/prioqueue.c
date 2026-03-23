#include "prioqueue.h"
#include "event.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_PRIOQUEUE_SIZE 50

struct _prioqueue {
    event  tab[MAX_PRIOQUEUE_SIZE];
    int    size;
};

prioqueue *create_pq() {
    prioqueue *q = (prioqueue*)malloc(sizeof(prioqueue));
    q->size = 0;
    return q;
}

void free_pq(prioqueue *q) {
    free(q);
}

int size_pq(prioqueue *q) {
    return q->size;
}

void insert_pq(prioqueue *q, event e){
    assert(q->size < MAX_PRIOQUEUE_SIZE);
    int i;
    q->tab[q->size] = e;
    q->size++;
    for(i = q->size-1; i > 0; i--){
        if(q->tab[i].time > q->tab[i-1].time){
            event c = q->tab[i];
            q->tab[i]= q->tab[i-1];
            q->tab[i-1]= c;
        }
    }
}

event extract_min_pq(prioqueue *q){
    assert(q->size > 0);
    event e = q->tab[q->size-1];
    q->size--;
    return e;
}