CC = gcc
CFLAGS = -Wall -ansi -g
LDFLAGS = -lMLV

OBJ = main.o sudoku.o interface.o event.o input.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(LDFLAGS)

main.o: main.c sudoku.h interface.h event.h input.h
	$(CC) $(CFLAGS) -c main.c

sudoku.o: sudoku.c sudoku.h
	$(CC) $(CFLAGS) -c sudoku.c

interface.o: interface.c interface.h sudoku.h
	$(CC) $(CFLAGS) -c interface.c

event.o: event.c event.h sudoku.h
	$(CC) $(CFLAGS) -c event.c

input.o: input.c input.h
	$(CC) $(CFLAGS) -c input.c

clean:
	rm -f sudoku *.o

run: sudoku
	./sudoku data/grid1.txt
