#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probabilistic.h"

void option_a() {
    printf("Option A executed\n");
}

void option_b() {
    printf("Option B executed\n");
}

int main() {
    srand((unsigned int)time(NULL));

    VoidFunction funcs[] = {option_a, option_b};
    double weights[] = {0.7, 0.3};
    int count = 2;

    printf("Executing mutual function:\n");
    for (int i = 0; i < 5; i++) {
        mutual_function(funcs, weights, count);
    }

    return 0;
}
