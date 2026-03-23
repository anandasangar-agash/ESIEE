#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct {
    int arrival_time;  /* arrival time */
} customer;

/* Create and return a customer with the given arrival time. */
customer make_customer(int arrival_time);

#endif /* CUSTOMER_H */
