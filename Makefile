
CC = gcc
CFLAGS = -Wall -Wextra -g

test_board: test_board.c board.c board.h
	$(CC) $(CFLAGS) -o test_board test_board.c board.c

clean:
	rm -f test_board *.o
