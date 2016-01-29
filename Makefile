ROOTDIR=/home/enseign/ASE

CC = gcc
CFLAGS = -W -Wall -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g -m32
LIBDIR  = $(ROOTDIR)/lib
INCDIR  = -I$(ROOTDIR)/include
LIBS    = -L$(LIBDIR) -lhardware

all: main

ctx.o : ./hw/hw.h ctx.c ctx.h
	$(CC) $(CFLAGS) -c ctx.c

main : ./hw/hw.o ctx.o sem.o main.o library.o lib_hardware.o
	$(CC) $(CFLAGS) -o main ./hw/hw.o ctx.o sem.o main.o library.o $(LIBS)

main.o: main.c ctx.h ctx.c hw/hw.h hw/hw.c sem.h sem.c library.h library.c disk/lib_hardware.c disk/lib_hardware.h
	$(CC) $(CFLAGS) -c main.c $(INCDIR)

sem.o : ctx.h sem.c sem.h ctx.c
	$(CC) $(CFLAGS) -c sem.c

library.o : ctx.h library.h library.c ctx.c
	$(CC) $(CFLAGS) -c library.c

lib_hardware.o : disk/lib_hardware.c disk/lib_hardware.h disk/drive.c disk/drive.h
	$(CC) $(CFLAGS) -c disk/lib_hardware.c $(INCDIR)

drive.o : disk/drive.c disk/drive.h
	$(CC) $(CFLAGS) -c drive.c $(INCDIR)

clean:
	-rm *.o main .#* *~
