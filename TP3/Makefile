CC = gcc
CFLAGS = -W -Wall -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g -m32

all: clean main

ctx.o : ./hw/hw.h ctx.c ctx.h
	$(CC) $(CFLAGS) -c ctx.c

main : ./hw/hw.o ctx.o sem.o main.o library.o
	$(CC) $(CFLAGS) -o main ./hw/hw.o ctx.o sem.o main.o library.o

main.o: main.c ctx.h ctx.c hw/hw.h hw/hw.c sem.h sem.c library.h library.c
	$(CC) $(CFLAGS) -c main.c

sem.o : ctx.h sem.c sem.h
	$(CC) $(CFLAGS) -c sem.c

library.o : ctx.h library.h library.c
	$(CC) $(CFLAGS) -c library.c

clean:
	-rm *.o main .#* *~
