#!/bin/bash

g++ -O3 -march=native -Wall -Wextra -std=c++11 -fopenmp -openmp src/main.cpp -I./include
g++ -O3 -march=native -Wall -Wextra -std=c++11 -fopenmp -openmp src/print.cpp -I./include
g++ -O3 -march=native -Wall -Wextra -std=c++11 -fopenmp -openmp src/read.cpp -I./include
g++ -O3 -march=native -Wall -Wextra -std=c++11 -fopenmp -openmp src/update.cpp -I./include

g++ -o omp main.o print.o read.o update.o
 rm *.o
