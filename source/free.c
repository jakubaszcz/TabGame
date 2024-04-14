#include "../includes/my.h"

void freeGame(Game *game) {
        for (int i = 0; i < game->tabSize; i++) {
            free(game->tab[i]);
        }
        free(game->tab);
        free(game);
}

void freeMap(Map *map) {
    if (map == NULL)
        return;
    for (int i = 0; map->array[i] != NULL; i++) {
        free(map->array[i]);
    }
    free(map->array);
    free(map);
}