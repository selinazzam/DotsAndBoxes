#ifndef BOARD_H
#define BOARD_H

#define ROWS 4
#define COLS 5

typedef struct {
    int horizontal[ROWS + 1][COLS];
    int vertical[ROWS][COLS + 1];
    char owner[ROWS][COLS];
} Board;

void initializeBoard(Board *board);

void displayBoard(const Board *board);

int isValidMove(const Board *board, int r1, int c1, int r2, int c2);

int drawLine(Board *board, int r1, int c1, int r2, int c2);

int claimCompletedBoxes(Board *board, char player);

int isBoardFull(const Board *board);

int getScore(const Board *board, char player);

#endif
