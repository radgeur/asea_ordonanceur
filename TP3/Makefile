CC = gcc
CFLAGS = -W -Wall -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g -m32

all: clean main

ctx.o : ./hw/hw.h ctx.c 
	$(CC) $(CFLAGS) -c ctx.c

main : ./hw/hw.o ctx.o sem.o main.o library.o
	$(CC) $(CFLAGS) -o main ./hw/hw.o ctx.o sem.o main.o library.o

main.o: main.c ctx.h hw/hw.h sem.h
	$(CC) $(CFLAGS) -c main.c

sem.o : ctx.h sem.c 
	$(CC) $(CFLAGS) -c sem.c

library.o : library.c
	$(CC) $(CFLAGS) -c library.c

clean:
	-rm *.o main .#* *~
