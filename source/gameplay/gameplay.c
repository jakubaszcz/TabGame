#include "../../includes/my.h"

void findPath(Game *game, int x, int y) {
    ChainReaction *new = NULL;
    ChainReaction *current = NULL;
    new = malloc(sizeof(ChainReaction));
    if (game->tab[x][y] != 0) {
        game->tab[x][y]++;
        new->x = x;
        new->y = y;
        new->next = NULL;
        if (game->chainReaction == NULL) {
            game->chainReaction = new;
        } else {
            current = game->chainReaction;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new;
        }
        if ((x - 1 >= 0 && game->tab[x - 1][y] < game->tab[x][y]) && game->tab[x - 1][y] != 0) {
            findPath(game, x - 1, y);
        }
        if ((y - 1 >= 0 && game->tab[x][y - 1] < game->tab[x][y]) && game->tab[x][y - 1] != 0) {
            findPath(game, x, y - 1);
        }
        if ((x + 1 < game->tabSize && game->tab[x + 1][y] < game->tab[x][y]) && game->tab[x + 1][y] != 0) {
            findPath(game, x + 1, y);
        }
        if ((y + 1 < game->tabSize && game->tab[x][y + 1] < game->tab[x][y]) && game->tab[x][y + 1] != 0) {
            findPath(game, x, y + 1);
        }
        if (game->tab[x][y] >= 10) {
            game->tab[x][y] = 0;
        }
    }
}

int gameWin(Game *game) {
    for (int i = 0; i < game->tabSize; i++) {
        for (int j = 0; j < game->tabSize; j++) {
            if (game->tab[i][j] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

int gameplay(Game *game, Map *map, Error *error) {
    findPath(game, atoi(map->array[0]), atoi(map->array[1]));
    if (!gameWin(game))
        game->isWin = 1;
    return 0;
}