CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
LDFLAGS=-lm
DEPS=event.h customer.h queue.h prioqueue.h
OBJ=bakery.o event.o customer.o queue.o prioqueue.o
TARGET=bakery

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(TARGET)
