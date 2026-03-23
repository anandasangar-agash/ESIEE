#include "event.h"

event make_arrival_event(int event_time) {
    event e;
    e.type = EVENT_ARRIVAL;
    e.time = event_time;
    e.vendor_id = -1;   /* unused */
    return e;
}

event make_departure_event(int event_time, int vendor_id) {
    event e;
    e.type = EVENT_DEPARTURE;
    e.time = event_time;
    e.vendor_id = vendor_id;
    return e;
}
