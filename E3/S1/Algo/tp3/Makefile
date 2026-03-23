CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
LDLIBS_MLV=$(shell pkg-config --libs-only-l MLV)
DEPS=visualarray.h array.h sort.h
OBJ=array.o sort.o
OBJMLV=visualarray.o array.o sort.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

tp3: tp3.o $(OBJ)
	$(CC) -o $@ $^

tp3-instr: tp3-instr.o $(OBJ)
	$(CC) -o $@ $^

demo1: demo1.o $(OBJMLV)
	$(CC) -o $@ $^ $(LDLIBS_MLV)

demo2: demo2.o $(OBJMLV)
	$(CC) -o $@ $^ $(LDLIBS_MLV)

.PHONY: clean
clean:
	rm -f *.o tp3 demo1 demo2 tp3-instr
