#include "../includes/my.h"

void printTab(Game *game) {
    for (int i = 0; i < game->tabSize; i++) {
        for (int j = 0; j < game->tabSize; j++)
        {
            printf("[%d]", game->tab[i][j]);
            if ((j + 1) == game->tabSize) {
                continue;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printUser(Game *game) {
    if (game->time != 0) {
        if (game->time == 1)
            printf("\nYou played %d time", game->time);
        if (game->time >= 2)
            printf("\nYou played %d times", game->time);
    }
    printf("\n> ");
}