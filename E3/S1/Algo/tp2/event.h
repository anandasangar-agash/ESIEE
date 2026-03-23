#ifndef EVENT_H
#define EVENT_H

typedef enum {
    EVENT_ARRIVAL,
    EVENT_DEPARTURE
} event_type;

typedef struct {
    event_type  type;       /* event type */
    int         time;       /* event time */
    int         vendor_id;  /* vendor index (EVENT_DEPARTURE only) */
} event;

/* Create an arrival event scheduled at event_time */
event make_arrival_event(int event_time);

/* Create a departure event for vendor vendor_id's customer at event_time */
event make_departure_event(int event_time, int vendor_id);

#endif /* EVENT_H */
