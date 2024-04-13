#include "../includes/my.h"

Game *setupGame(void) {
    Game *game = malloc(sizeof(Game));
    game->tabSize = 10;
    return game;
}