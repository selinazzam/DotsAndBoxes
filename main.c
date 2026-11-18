#include <stdio.h>
#include "game.h"

int main(void)
{
    do {
        if (!play_game()) {
            break;
        }
    } while (play_again());

    printf("Thanks for playing!\n");

    return 0;
}
