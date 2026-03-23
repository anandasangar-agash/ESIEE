#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "customer.h"

#define MAX_QUEUE_SIZE 50

typedef struct _link {
    customer c;
    struct _link *next;
} link;

struct _queue {
    link *first;
    link *last;
    int size;
};

queue *create_q() {
    queue *q = malloc(sizeof(queue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

void free_q(queue *q) {
    while (q->first != NULL)
        dequeue_q(q);
    free(q);
}

int size_q(queue *q) {
    return q->size;
}

void enqueue_q(queue *q, customer c) {
    assert(q->size < MAX_QUEUE_SIZE);
    link *new_lnk = malloc(sizeof(link));
    assert(new_lnk != NULL);
    new_lnk->c = c;
    new_lnk->next = NULL;
    if (q->size == 0) {
        q->first = new_lnk;
    }
    else {
        q->last->next = new_lnk;
    }
    q->last = new_lnk;
    q->size++;
}

customer dequeue_q(queue *q) {
    assert(q->size > 0);
    link *next = q->first->next;
    customer c = q->first->c;
    free(q->first);
    q->first = next;
    q->size--;
    if (q->size == 0)
        q->last = NULL;
    return c;
}
