#ifndef PROBABILISTIC_H
#define PROBABILISTIC_H

#include <stdbool.h>

// Type definition for a generic function pointer
typedef void (*VoidFunction)(void);

// Function declarations
void probabilistic_function(VoidFunction func, double probability);
void probabilistic_mutual_function(VoidFunction *funcs, double *weights, int count);
void probabilistic_distribution_function(int (*func)(void), int trials, double **distribution, int **outcomes, int *outcome_count);

#endif // PROBABILISTIC_H
