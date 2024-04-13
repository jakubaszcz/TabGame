#include "./includes/my.h"

int main(int ac, char **av) {
    if (av[1] != NULL && (!strncmp(av[1], "-h", 2) || !strncmp(av[1], "-help", 5))) {
        printf("You have a square. The size by default is 10.\n"
               "You input the position of a square you want to go, like '3-5', at this position it do +1 for every square near it.\n"
               "If the square get 0, so 9 + 1, the block is broken, you can't use it anymore.\n"
               "You goal, is to broke all square, within the less amount of time.");
        return;
    }
    launchGame();
}