CC=gcc
CFLAGS=-Wall -std=c17
LDFLAGS=-lMLV
OBJ=main.o plateau.o interface.o

taquin: $(OBJ)
	$(CC) -o taquin $(OBJ) $(CFLAGS) $(LDFLAGS)

main.o: main.c plateau.h
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)

plateau.o: plateau.c plateau.h
	$(CC) -c plateau.c $(CFLAGS)

interface.o: interface.c interface.h
	$(CC) -c interface.c $(CFLAGS) $(LDFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f taquin