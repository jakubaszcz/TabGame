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

int printError(Game *game, Error *error) {
    if (error->isError) {
        if (error->isArguments) {
            printf("\x1B[31mYou must provied 2 arguments.\x1B[0m\n");
        }
        if (error->isAlpha) {
            printf("\x1B[31mYou're 2 arguments must be integer.\x1B[0m\n");
        }
        if (error->isSize) {
            printf("\x1B[31mYou're integer must be 0<...<%d.\x1B[0m\n", game->tabSize - 1);
        }
        return 1;
    }
    return 0;
}