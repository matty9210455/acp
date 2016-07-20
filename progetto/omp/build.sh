#!/bin/bash

g++ -fopenmp -c -std=c++11 src/main.cpp -I./include
g++ -fopenmp -c -std=c++11 src/print.cpp -I./include
g++ -fopenmp -c -std=c++11 src/read.cpp -I./include
g++ -fopenmp -c -std=c++11 src/update.cpp  -I./include
g++ -fopenmp -o omp main.o print.o read.o update.o
rm *.o
