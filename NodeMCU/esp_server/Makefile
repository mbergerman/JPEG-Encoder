CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main.exe: main.o main.o 
	$(CC) -o main.exe main.o main.o 