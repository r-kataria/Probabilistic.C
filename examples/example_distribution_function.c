#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probabilistic.h"

int roll_die() {
    return rand() % 6 + 1;
}

int main() {
    srand((unsigned int)time(NULL));

    int trials = 10000;
    double *distribution = NULL;
    int *outcomes = NULL;
    int outcome_count = 0;

    distribution_function(roll_die, trials, &distribution, &outcomes, &outcome_count);

    printf("Die roll distribution over %d trials:\n", trials);
    for (int i = 0; i < outcome_count; i++) {
        printf("Outcome %d: %.4f\n", outcomes[i], distribution[i]);
    }

    // Clean up
    free(distribution);
    free(outcomes);

    return 0;
}
