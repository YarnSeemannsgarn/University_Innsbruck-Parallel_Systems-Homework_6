#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

#define RANGE_MAX 10000
#define MEMORY_MESSAGE "Not enough memory. Choose a smaller problem size!\n"
#define USAGE_MESSAGE "Usage: %s <problem-size> [<debug>]\n"
#define PRINTF_WIDTH 10
#define PRINTF_PRECISION 4

// matrix helpers
int *create_matrix(size_t M, size_t N);
void print_matrix(int *matrix, size_t M, size_t N);

#endif
