#include "../includes/my.h"

void resetError(Error *error) {
    if (!error->isError)
        return;
    error->isError = 0;
    error->isAlpha = 0;
    error->isArguments = 0;
    error->isSize = 0;
}