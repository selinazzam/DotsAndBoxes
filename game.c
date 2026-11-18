#include <stdio.h>
#include "game.h"
#include "board.h"

static void clear_line(void)
{
    int ch = getchar();

    while (ch != '\n' && ch != EOF) {
        ch = getchar();
    }
}

static void print_scores(const Board *board)
{
    printf("********************************************************\n");
    printf("Player A score: %d\n", getScore(board, 'A'));
    printf("Player B score: %d\n", getScore(board, 'B'));
    printf("********************************************************\n");
}

int play_game(void)
{
    Board board;
    char player = 'A';
    int r1, c1, r2, c2;
    int got, boxes;
    int scoreA, scoreB;

    initializeBoard(&board);
    displayBoard(&board);

    while (!isBoardFull(&board)) {

        printf("Player %c's turn. Enter the row and column of the first dot (e.g., A0 -> 0 0) and second dot:\n",
               player);

        got = scanf("%d", &r1);

        if (got == EOF) {
            return 0;
        }

        if (got != 1) {
            clear_line();
            printf("Invalid input. Enter four integers.\n");
            continue;
        }

        if (r1 == -1) {
            clear_line();
            return 0;
        }

        got = scanf("%d %d %d", &c1, &r2, &c2);

        if (got == EOF) {
            return 0;
        }

        clear_line();

        if (got != 3) {
            printf("Invalid input. Enter four integers.\n");
            continue;
        }

        if (!drawLine(&board, r1, c1, r2, c2)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        boxes = claimCompletedBoxes(&board, player);

        print_scores(&board);
        displayBoard(&board);

        if (boxes > 0) {
            printf("Player %c completed %d box(es) and plays again.\n",
                   player, boxes);
        } else {
            if (player == 'A') {
                player = 'B';
            } else {
                player = 'A';
            }
        }
    }

    scoreA = getScore(&board, 'A');
    scoreB = getScore(&board, 'B');

    printf("\nFinal scores:\n");
    printf("Player A score: %d\n", scoreA);
    printf("Player B score: %d\n", scoreB);

    if (scoreA > scoreB) {
        printf("Player A wins!\n");
    } else if (scoreB > scoreA) {
        printf("Player B wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 1;
}

int play_again(void)
{
    char answer;

    printf("\nPlay again? (y/n): ");

    if (scanf(" %c", &answer) != 1) {
        return 0;
    }

    clear_line();

    return (answer == 'y' || answer == 'Y');
}
