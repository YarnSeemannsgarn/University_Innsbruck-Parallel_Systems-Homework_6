#!/bin/bash

if [ $# -ne 2 ]; then
	echo "usage: $0 nprocs problem-size"
	exit 1
fi

nprocs=$1
problemsize=$2

qsub -cwd \
     -o "matrix_multiplication_openmp_${nprocs}_${problemsize}.dat" \
     -e "matrix_multiplication_openmp_${nprocs}_${problemsize}.dat" \
     -N "matrix_multiplication_openmp" \
     -pe openmp $nprocs \
     -b y \
     "export OMP_NUM_THREADS=$nprocs && ./matrix_multiplication_openmp $problemsize"
