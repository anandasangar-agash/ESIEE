CC = gcc
CFLAGS = -Wall -std=c17

coffre: main.o code.o
	$(CC) -o coffre main.o code.o

main.o: main.c code.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main.o coffre