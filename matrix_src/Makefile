#@author AaronTrites
#Makefile for matrix.c

CC=g++
CFLAGS = -c

all: main

main: matrix.o
	$(CC) matrix.o -o main

matrix.o: matrix.c
	$(CC) $(CFLAGS) matrix.c

clean:
	rm -rf *.o main