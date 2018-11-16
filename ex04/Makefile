CFLAGS = -std=c99 -pedantic -Wall -Wextra
CC = gcc

default: a b c

a:
	@$(CC) $(CFLAGS) -o Sine.exe sin.c
	@./Sine.exe

b:
	@$(CC) $(CFLAGS) -o ATan.exe atan.c
	@./ATan.exe

c:
	@$(CC) $(CFLAGS) -o Log.exe log.c
	@./Log.exe

clean:
	@rm *.exe
