#include "event.h"
#include "customer.h"
#include "queue.h"
#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_VENDORS 3
#define CLOSING_TIME 6000
#define ARRIVAL_RATE (1.0/60)
#define MEAN_SERVICE_TIME 150


/**
 * A vendor in the bakery.
 *
 * vendors[i].busy == 0 - vendor i is free
 * vendors[i].busy == 1 - vendor i is serving a customer
 * vendors[i].served_customer is the customer currently being served by vendor i
 */
typedef struct {
    int      busy;
    customer served_customer;
} vendor;

/* Main simulation structures */
prioqueue*  event_queue;        /* event priority queue */
queue*      customer_queue;     /* customer waiting queue */
vendor      vendors[N_VENDORS]; /* the vendors behind the counter */
int         current_time =0;
int         nb_client=0;

double exponential_delay(double rate) {
    return -log(1-((double)rand()/RAND_MAX))/rate;
}

void add_customer(customer c){
    int i;
    for(i=0; i<N_VENDORS; i++){
        if(vendors[i].busy == 0){
            vendors[i].served_customer = c;
            vendors[i].busy = 1;

            int service_time = current_time + (int)exponential_delay(1.0/MEAN_SERVICE_TIME);
            event e_d = make_departure_event(service_time, i);
            insert_pq(event_queue, e_d);
            return;
        }
    }
    enqueue_q(customer_queue, c);
}

void process_arrival(event e) {
    /* Placeholder: implementation added later */
    customer c = make_customer(current_time);
    add_customer(c);
    int next_arrival = current_time + (int)exponential_delay(ARRIVAL_RATE);
    if(next_arrival < CLOSING_TIME){
        event e_a = make_arrival_event(next_arrival); 
        insert_pq(event_queue, e_a);
    }
    (void)e;
}

void process_departure(event e) {
    /* Placeholder: implementation added later */
    int vendor_id = e.vendor_id;
    vendors[vendor_id].busy = 0;
    
    if(size_q(customer_queue)>0){
        customer c = dequeue_q(customer_queue);
        vendors[vendor_id].served_customer = c;
        vendors[vendor_id].busy = 1;
        int service_time = current_time + (int)exponential_delay(1.0/MEAN_SERVICE_TIME);
        event e_d = make_departure_event(service_time, vendor_id);
        insert_pq(event_queue, e_d);
    }
    (void)e;
}


void visualisation(){
    int i;
    printf("%d | ", current_time);
    
    for(i=0; i<N_VENDORS; i++){
        if(vendors[i].busy == 1){
            printf("X");
        } else {
            printf("_");
        }
    }
    
    printf(" | ");
    
    int queue_size = size_q(customer_queue);
    for(i=0; i<queue_size; i++){
        printf("X");
    }
    
    printf("\n");
}

void event_loop(){
    while(size_pq(event_queue)>0){
        event e = extract_min_pq(event_queue);
        current_time = e.time;
        
        if(e.type == EVENT_DEPARTURE){
            process_departure(e);
            nb_client++;
        } else {
            process_arrival(e);
        }
        
        visualisation();
    }
}

int main() {

    int i;
    event_queue = create_pq();
    customer_queue = create_q();
    for(i=0; i < N_VENDORS; i++){
        vendors[i].busy = 0;
    }

    customer c1 = make_customer(42);
    enqueue_q(customer_queue, c1);
    printf("Heure d'arrivé : %d\n", dequeue_q(customer_queue).arrival_time);

    event e_a = make_arrival_event(60);
    insert_pq(event_queue, e_a);

    event_loop();

    printf("Nombre de client est : %d\n", nb_client);

    return 0;
}
