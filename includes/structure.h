//
// Created by jakubszczucinski on 4/13/24.
//

#ifndef TABGAME_STRUCTURE_H
#define TABGAME_STRUCTURE_H

typedef struct chainReaction {
    int x;
    int y;
    struct chainReaction *next;
} ChainReaction;

typedef struct game {
    int tabSize;
    int hasPlayed;
    int time;
    int **tab;
    int isWin;
    ChainReaction *chainReaction;
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
