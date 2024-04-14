#include "../includes/my.h"

int **createTabAllocation(Game *game) {
    int **tab = malloc(sizeof(int *) * game->tabSize);
    for (int i = 0; i < game->tabSize; i++) tab[i] = malloc(sizeof(int *) * game->tabSize);
    return tab;
}

void createTabValue(Game *game) {
    int upper = 9, lower = 1;
    srand(time(0));
    for (int i = 0; i < game->tabSize; i++) {
        for (int j = 0; j < game->tabSize; j++)
        {
            int random = (rand() % (upper - lower + 1)) + lower;
            game->tab[i][j] = random;
        }
    }
}

void createTab(Game *game) {
    game->tab = createTabAllocation(game);
    createTabValue(game);
}

void gameLoop(Game *game, Error *error) {
    char *command = NULL;
    Map *map = NULL;
    size_t size = 0;
    while (1) {
        printTab(game);
        printUser(game);
        if (getline(&command, &size, stdin) < 0) {
            break;
        }
        if (strlen(command) <= 1) {
            continue;
        }
        map = input(game, error, command);
        if (printError(game, error)) {
            resetError(error);
            continue;
        }
        game->time++;
        continue;
    }
    free(command);
    free(error);
    freeMap(map);
    freeGame(game);
}

void launchGame(void) {
    Game *game = setupGame();
    Error *error = setupError();
    createTab(game);
    gameLoop(game, error);
}