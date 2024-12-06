CC = gcc
CFLAGS = -Wall -g

all: mebel
	./mebel

mebel: mebmain.o mebvoid.o
	$(CC) $(CFLAGS) mebmain.o mebvoid.o -o mebel

%.o: %.c meb.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f mebel *.o
