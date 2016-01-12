#!/bin/bash

if [ $# -ne 2 ]; then
	echo "usage: $0 nprocs problem-size"
	exit 1
fi

nprocs=$1
problemsize=$2

qsub -cwd \
     -o "dijkstra_openmp_${nprocs}_${problemsize}.dat" \
     -e "dijkstra_openmp_${nprocs}_${problemsize}.dat" \
     -N "dijkstra_openmp" \
     -pe openmp $nprocs \
     -b y \
     "export OMP_NUM_THREADS=$nprocs && ./dijkstra_openmp $problemsize"
