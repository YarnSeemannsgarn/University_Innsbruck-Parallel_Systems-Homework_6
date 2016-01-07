CC=gcc
CFLAGS=-O2 -Wall -fopenmp
SOURCES=matrix_multiplication_openmp.c sieve_of_erastosthenes_openmp.c util.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=matrix_multiplication_openmp sieve_of_erastosthenes_openmp

all: $(EXECUTABLES)

matrix_multiplication_openmp: $(OBJECTS)
	$(CC) $(CFLAGS) matrix_multiplication_openmp.o util.o -o $@

sieve_of_erastosthenes_openmp: $(OBJECTS)
	$(CC) $(CFLAGS) sieve_of_erastosthenes_openmp.o util.o -o $@ -lm

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLES) $(OBJECTS) 
