CFLAGS = -std=c99 -pedantic -Wall -Wextra
CC = gcc

output: main.o sort.o
	$(CC) $(CFLAGS) main.o sort.o -o output

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean:
	@rm *.o output
