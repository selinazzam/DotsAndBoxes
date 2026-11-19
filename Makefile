
CC = gcc
CFLAGS = -Wall -Wextra -g

all: dots

dots: main.c game.c board.c game.h board.h
	$(CC) $(CFLAGS) -o dots main.c game.c board.c


clean:
	rm -f dots test_board *.o
