//
// Created by jakubszczucinski on 4/13/24.
//

#ifndef TABGAME_STRUCTURE_H
#define TABGAME_STRUCTURE_H

typedef struct game {
    int tabSize;
    int time;
    int **tab;
} Game;

typedef struct error {
    int isError;
    int isSize;
    int isAlpha;
    int isArguments;
} Error;

typedef struct map {
    char **array;
    int length;
    int count;
} Map;

#endif //TABGAME_STRUCTURE_H
