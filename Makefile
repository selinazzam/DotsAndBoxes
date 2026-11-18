Makefile 

CC = gcc
CFLAGS = -Wall -Wextra -g

all: dots

dots: main.c game.c board.c game.h board.h
	$(CC) $(CFLAGS) -o dots main.c game.c board.c

test_board: test_board.c board.c board.h
	$(CC) $(CFLAGS) -o test_board test_board.c board.c

clean:
	rm -f dots test_board *.o
