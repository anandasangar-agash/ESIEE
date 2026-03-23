CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
DEPS=arrays.h
OBJ=verif.o verif_func.o parse.o arrays.o
TARGET=verif

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJ) $(TARGET)
