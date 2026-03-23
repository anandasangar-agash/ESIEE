CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lMLV
OBJ=main.o plateau.o

taquin: $(OBJ)
	$(CC) -o taquin $(OBJ) $(CFLAGS) $(LDFLAGS)

main.o: main.c plateau.h
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)

plateau.o: plateau.c plateau.h
	$(CC) -c plateau.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f taquin