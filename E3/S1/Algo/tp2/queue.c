

#include "queue.h"
#include "customer.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_QUEUE_SIZE 50

struct _queue {
    customer  tab[MAX_QUEUE_SIZE];
    int       head; /* first index of the queue */
    int       tail; /* first index after the queue */
    int       size; /* size of the queue */
};

queue *create_q() {
    queue *q = malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

void free_q(queue *q) {
    free(q);
}

int size_q(queue *q) {
    return q->size;
}

void enqueue_q(queue *q, customer c){
    assert(q->size < MAX_QUEUE_SIZE);
    q->tab[q->tail] = c;
    q->tail++;
    q->size++;
}

customer dequeue_q(queue *q){
    assert(q->size > 0);
    customer c = q->tab[q->head];
    q->head++;
    q->size--;
    return c;
}