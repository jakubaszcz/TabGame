#include "../includes/my.h"

Game *setupGame(void) {
    Game *game = malloc(sizeof(Game));
    game->tabSize = 10;
    game->time = 0;
    return game;
}