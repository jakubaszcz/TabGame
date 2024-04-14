#include "../includes/my.h"

void printTab(Game *game) {
    printf("    ");
    for (int i = 0; i < game->tabSize; i++) {
        if (i == game->tabSize) {
            printf("[\x1B[36m%d\x1B[0m]", i);
        } else {
            printf("[\x1B[36m%d\x1B[0m] ", i);
        }
    }
    printf("\n");
    for (int i = 0; i < game->tabSize; i++) {
        printf("[\x1B[36m%d\x1B[0m] ", i);
        for (int j = 0; j < game->tabSize; j++) {
            if (game->tab[i][j] == 0) {
                printf("[\x1B[35m%d\x1B[0m]", game->tab[i][j]);
            } else {
                int isChained = 0;
                ChainReaction *chainReaction = game->chainReaction;
                while (chainReaction != NULL) {
                    if (i == chainReaction->x && j == chainReaction->y) {
                        isChained = 1;
                        break;
                    }
                    chainReaction = chainReaction->next;
                }
                if (isChained) {
                    printf("[\x1B[32m%d\x1B[0m]", game->tab[i][j]);
                } else {
                    printf("[%d]", game->tab[i][j]);
                }
            }
            if ((j + 1) == game->tabSize) {
                continue;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printUser(Game *game, Map *map) {
    if (map != NULL && game->hasPlayed) {
        printf("\nYou played on [\x1B[32m%d\x1B[0m, \x1B[32m%d\x1B[0m].\n", atoi(map->array[0]), atoi((map->array[1])));
        game->hasPlayed = 0;
    }
    if (game->time != 0) {
        if (game->time == 1)
            printf("\nYou played %d time", game->time);
        if (game->time >= 2)
            printf("\nYou played %d times", game->time);
    }
    printf("\n> ");
}

void printWin(Game *game) {
    system("clear");
    printf("Congratulation you win under \x1B[34m%d\x1B[0m moves\n", game->time);
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