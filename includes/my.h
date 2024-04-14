//
// Created by jakubszczucinski on 4/13/24.
//

#ifndef TABGAME_MY_H
#define TABGAME_MY_H
#include "structure.h"
#include "lib.h"

void launchGame(void);
Game *setupGame(void);
Error *setupError(void);
void printTab(Game *game);
void printUser(Game *game, Map *map);
int printError(Game *game, Error *error);
void printWin(Game *game);
Map *input(Game *game, Error *error, char *input);
int gameplay(Game *game, Map *map, Error *error);
void freeGame(Game *game);
void freeMap(Map *map);
void resetError(Error *error);
#endif //TABGAME_MY_H
