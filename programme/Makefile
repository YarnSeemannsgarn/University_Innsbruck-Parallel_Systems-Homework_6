CC=gcc
CFLAGS=-O2 -Wall -fopenmp
SOURCES=matrix_multiplication_openmp.c sieve_of_erastosthenes_openmp.c dijkstra_openmp.c util.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=matrix_multiplication_openmp sieve_of_erastosthenes_openmp dijkstra_openmp

all: $(EXECUTABLES)

matrix_multiplication_openmp: $(OBJECTS)
	$(CC) $(CFLAGS) matrix_multiplication_openmp.o util.o -o $@

sieve_of_erastosthenes_openmp: $(OBJECTS)
	$(CC) $(CFLAGS) sieve_of_erastosthenes_openmp.o util.o -o $@ -lm

dijkstra_openmp: $(OBJECTS)
	$(CC) $(CFLAGS) dijkstra_openmp.o util.o -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLES) $(OBJECTS) 
