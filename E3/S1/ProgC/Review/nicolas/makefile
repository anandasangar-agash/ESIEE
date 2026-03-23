CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lMLV
OBJ=sudoku.o main.o graphic_module.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(CFLAGS) $(LDFLAGS)

main.o: main.c sudoku.h
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)

sudoku.o: sudoku.c sudoku.h
	$(CC) -c sudoku.c $(CFLAGS)

graphic_module.o: graphic_module.c graphic_module.h
	$(CC) -c graphic_module.c $(CFLAGS) $(LDFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f sudoku
