#include "../includes/my.h"

Game *setupGame(void) {
    Game *game = malloc(sizeof(Game));
    game->tabSize = 10;
    game->time = 0;
    return game;
}

Error *setupError(void) {
    Error *error = malloc(sizeof(Error));
    error->isError = 0;
    error->isSize = 0;
    error->isAlpha = 0;
    error->isArguments = 0;
    return error;
}