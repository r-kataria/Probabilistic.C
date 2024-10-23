#include "probabilistic.h"
#include <stdlib.h>
#include <time.h>

void probabilistic_function(VoidFunction func, double probability) {
    if (probability < 0.0 || probability > 1.0) {
        // Handle invalid probability
        return;
    }

    double rand_val = (double)rand() / RAND_MAX;
    if (rand_val <= probability) {
        func();
    }
}


void probabilistic_mutual_function(VoidFunction *funcs, double *weights, int count) {
    if (count <= 0) {
        return;
    }

    double total_weight = 0.0;
    for (int i = 0; i < count; i++) {
        total_weight += weights[i];
    }

    if (total_weight <= 0.0) {
        return;
    }

    // Generate cumulative weights
    double *cumulative_weights = (double *)malloc(count * sizeof(double));
    double cumsum = 0.0;
    for (int i = 0; i < count; i++) {
        cumsum += weights[i];
        cumulative_weights[i] = cumsum / total_weight;
    }

    // Random selection
    double rand_val = (double)rand() / RAND_MAX;
    for (int i = 0; i < count; i++) {
        if (rand_val <= cumulative_weights[i]) {
            funcs[i]();
            break;
        }
    }

    free(cumulative_weights);
}


void probabilistic_distribution_function(int (*func)(void), int trials, double **distribution, int **outcomes, int *outcome_count) {
    if (trials <= 0) {
        return;
    }

    // Simple hash table implementation
    int *result_values = (int *)malloc(trials * sizeof(int));
    int *result_counts = (int *)malloc(trials * sizeof(int));
    int unique_count = 0;

    for (int i = 0; i < trials; i++) {
        int result = func();
        int found = 0;

        for (int j = 0; j < unique_count; j++) {
            if (result_values[j] == result) {
                result_counts[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            result_values[unique_count] = result;
            result_counts[unique_count] = 1;
            unique_count++;
        }
    }

    // Allocate output arrays
    *outcome_count = unique_count;
    *outcomes = (int *)malloc(unique_count * sizeof(int));
    *distribution = (double *)malloc(unique_count * sizeof(double));

    for (int i = 0; i < unique_count; i++) {
        (*outcomes)[i] = result_values[i];
        (*distribution)[i] = (double)result_counts[i] / trials;
    }

    free(result_values);
    free(result_counts);
}
