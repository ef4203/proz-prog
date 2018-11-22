PROGRAM = sudoku

CFLAGS = -std=c99 -pedantic -Wall -Wextra
CC = gcc

ifeq ($(OS),Windows_NT)
	MIME = .exe
else
	MIME = .out
endif

default: $(PROGRAM)

$(PROGRAM):
	@$(CC) $(CFLAGS) -o $(PROGRAM)$(MIME) $(PROGRAM).c
	@./$(PROGRAM)$(MIME)

clean:
	@rm *$(MIME)
