#include "customer.h"

customer make_customer(int arrival_time) {
    customer c;
    c.arrival_time = arrival_time;
    return c;
}
