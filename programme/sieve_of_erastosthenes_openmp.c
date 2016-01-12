#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#include "util.h"

int main(int argc, char *argv[]){
  // Handle parameter
  if (argc != 2 && argc != 3) {
    fprintf(stderr, USAGE_MESSAGE, argv[0]);
    return EXIT_FAILURE;
  }
  size_t N = atoi(argv[1]);

  // Compute from 1 - sqrt(N)
  int square_root = (int) sqrt((double)N);
  int *primes = malloc(N * sizeof(int));
  
  // Initialise
  primes[0] = 0;
  primes[1] = 0;
  int i, j;
  for (i = 2; i <= N; ++i){
    primes[i] = 1;
  }

  // Measure time
  double begin_time, end_time;
  begin_time = omp_get_wtime();
  
  // Sieve
  for (i = 2; i < square_root; ++i) {
    #pragma omp parallel for shared(primes)
    for(j = i * i; j <= N; j = j + i) {
      primes[j] = 0;
    }
  }

  end_time = omp_get_wtime();
  printf("Time spent: %fs\n", end_time-begin_time);

  // Check
  if (argc == 3) {
    for (i = 0; i < N; ++i) {
      printf("%i: %i\n", i, primes[i]);
    }
  }

  // Free memory
  free(primes);

  return EXIT_SUCCESS;
}
