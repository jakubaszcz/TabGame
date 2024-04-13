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

void gameLoop(Game *game) {
    char *command = NULL;
    size_t size = 0;
    while (1) {
        system("clear");
        printTab(game);
        printUser(game);
        getline(&command, &size, stdin);
        game->time++;
        continue;
    }
}

void launchGame(void) {
    Game *game = setupGame();
    createTab(game);
    gameLoop(game);
}