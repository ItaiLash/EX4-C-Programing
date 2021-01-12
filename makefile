CC = gcc
FLAGS = -Wall -c

all: frequency

frequency: main.o
	$(CC) -Wall -o frequency trie.o main.o
main.o: main.c trie.c
	$(CC) -Wall -c trie.c main.c


.PHONY: clean all

clean:
	rm -f *.o *.a frequency
