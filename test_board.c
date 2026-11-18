#include <stdio.h>
#include "board.h"

int main(void) {
    Board board;
    int r, c;
    int points;

    initializeBoard(&board);

    /* Draw all horizontal lines */
    for (r = 0; r <= ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            drawLine(&board, r, c, r, c + 1);
        }
    }

    /* Draw all vertical lines */
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c <= COLS; c++) {
            drawLine(&board, r, c, r + 1, c);
        }
    }

    points = claimCompletedBoxes(&board, 'A');

    displayBoard(&board);

    printf("Total boxes claimed: %d\n", points);

    return 0;
}

