#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probabilistic.h"

void greet() {
    printf("Hello!\n");
}

int main() {
    srand((unsigned int)time(NULL));

    printf("Executing probabilistic greet function:\n");
    for (int i = 0; i < 5; i++) {
        probabilistic_function(greet, 0.5);
    }

    return 0;
}
