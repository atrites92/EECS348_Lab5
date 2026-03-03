#@author AaronTrites
#Makefile for matrix.c

CC=g++
CFLAGS = -c

all: prog

prog: matrix.o
	$(CC) matrix.o -o prog

matrix.o: matrix.c
	$(CC) $(CFLAGS) matrix.c

clean:
	rm -rf *.o prog