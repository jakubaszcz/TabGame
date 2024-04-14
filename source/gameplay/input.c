#include "../../includes/my.h"

int comparator(char character, char *separator) {
    for (int i = 0; separator[i] != '\0'; i++) {
        if (character == separator[i])
            return 1;
    }
    return 0;
}

int counter(char *command, char *separator) {
    int count = 0;
    for (int i = 0; command[i] != '\0'; i++) {
        if (comparator(command[i], separator))
            count++;
    }
    return count;
}

char **createMap(char *command, char *separator, int length) {
    char **map = malloc(sizeof(char *) * (length + 1));
    for (int i = 0; i < length; i++) {
        map[i] = malloc(sizeof(char) * strlen(command));
    }
    int i = 0, j = 0, k = 0;
    for (i = 0; i < length; i++) {
        for (j = k; command[j] != '\0' && command[j] != '\n' && !comparator(command[j], separator); j++) {
            map[i][j - k] = command[j];
        }
        map[i][j - k] = '\0';
        k = j + 1;
    }
    map[i] = NULL;
    return map;
}

int checkArguments(Game *game, Map *map, Error *error) {
    if (map->count != 2) {
        error->isError = 1;
        error->isArguments = 1;
        return 1;
    }
    if (!atoi(map->array[0]) && !atoi(map->array[1])) {
        error->isError = 1;
        error->isAlpha = 1;
        return 1;
    }
    if ((atoi(map->array[0]) > (game->tabSize -1) || atoi(map->array[0]) < 0)
    || (atoi(map->array[1]) > (game->tabSize -1) || atoi(map->array[1]) < 0)) {
        error->isError = 1;
        error->isSize = 1;
        return 1;
    }
    return 0;
}

Map *input(Game *game, Error *error, char *command) {
    Map *map = malloc(sizeof(Map));
    map->length = counter(command, " .-") + 1;
    map->count = map->length;
    map->array = createMap(command, " .-", map->length);
    if (checkArguments(game, map, error))
        return NULL;
    return map;
}