PROGRAM1 = sudokusolv
PROGRAM2 = mandel

CFLAGS = -std=c99 -pedantic -Wall -Wextra
CC = gcc

ifeq ($(OS),Windows_NT)
	MIME = .exe
else
	MIME = .out
endif

default: $(PROGRAM1)

$(PROGRAM1):
	@$(CC) $(CFLAGS) -o $(PROGRAM1)$(MIME) $(PROGRAM1).c -lm
	@./$(PROGRAM1)$(MIME)

$(PROGRAM2):
	@$(CC) $(CFLAGS) -o $(PROGRAM2)$(MIME) $(PROGRAM2).c -lm
	@./$(PROGRAM2)$(MIME)

clean:
	@rm *$(MIME)
	@rm *.bmp
