#include <stdio.h>
#include "board.h"

void initializeBoard(Board *board) {
    int i, j;

    for (i = 0; i <= ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board->horizontal[i][j] = 0;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j <= COLS; j++) {
            board->vertical[i][j] = 0;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board->owner[i][j] = ' ';
        }
    }
}

void displayBoard(const Board *board) {
    int i, j;

    printf("\n    ");

    for (j = 0; j <= COLS; j++) {
        printf("%4d", j);
    }

    printf("\n");

    for (i = 0; i <= ROWS; i++) {
        printf("%3d ", i);

        for (j = 0; j < COLS; j++) {
            printf(".");

            if (board->horizontal[i][j]) {
                printf("---");
            } else {
                printf("   ");
            }
        }

        printf(".\n");

        if (i < ROWS) {
            printf("    ");

            for (j = 0; j < COLS; j++) {
                if (board->vertical[i][j]) {
                    printf("|");
                } else {
                    printf(" ");
                }

                printf(" %c ", board->owner[i][j]);
            }

            if (board->vertical[i][COLS]) {
                printf("|");
            } else {
                printf(" ");
            }

            printf("\n");
        }
    }

    printf("\n");
}

int isValidMove(const Board *board, int r1, int c1, int r2, int c2) {
    if (r1 < 0 || r1 > ROWS || r2 < 0 || r2 > ROWS ||
        c1 < 0 || c1 > COLS || c2 < 0 || c2 > COLS) {
        return 0;
    }

    if (r1 == r2) {
        if (c1 + 1 == c2) {
            return board->horizontal[r1][c1] == 0;
        }

        if (c2 + 1 == c1) {
            return board->horizontal[r1][c2] == 0;
        }
    }

    if (c1 == c2) {
        if (r1 + 1 == r2) {
            return board->vertical[r1][c1] == 0;
        }

        if (r2 + 1 == r1) {
            return board->vertical[r2][c1] == 0;
        }
    }

    return 0;
}

int drawLine(Board *board, int r1, int c1, int r2, int c2) {
    if (!isValidMove(board, r1, c1, r2, c2)) {
        return 0;
    }

    if (r1 == r2) {
        if (c1 < c2) {
            board->horizontal[r1][c1] = 1;
        } else {
            board->horizontal[r1][c2] = 1;
        }
    } else {
        if (r1 < r2) {
            board->vertical[r1][c1] = 1;
        } else {
            board->vertical[r2][c1] = 1;
        }
    }

    return 1;
}

int claimCompletedBoxes(Board *board, char player) {
    int i, j;
    int count = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board->owner[i][j] == ' ' &&
                board->horizontal[i][j] &&
                board->horizontal[i + 1][j] &&
                board->vertical[i][j] &&
                board->vertical[i][j + 1]) {

                board->owner[i][j] = player;
                count++;
            }
        }
    }

    return count;
}
int isBoardFull(const Board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            if (board->owner[i][j] == ' ')
                return 0;
    return 1;
}

int getScore(const Board *board, char player) {
    int i, j, count = 0;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            if (board->owner[i][j] == player)
                count++;
    return count;
}
