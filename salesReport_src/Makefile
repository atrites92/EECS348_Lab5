#@author AaronTrites
#Makefile for salesReport.c

CC=gcc
CFLAGS = -c

all: main

main: salesReport.o
	$(CC) salesReport.o -o main

salesReport.o: salesReport.c
	$(CC) $(CFLAGS) salesReport.c

clean:
	rm -rf *.o main