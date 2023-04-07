#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef int telem;

#ifndef Header_h
#define Header_h

telem** create_arr(int m, int n);

void random_fill(int m, int n, telem** arr);

void print_matr(int m, int n, telem** arr);

void free_arr(int m, telem** arr);

void mult_matrices1(int m1, int n1, int n2, telem** arr1, telem** arr2, telem** arr3);

void mult_matrices2(int m1, int n1, int n2, telem** arr1, telem** arr2, telem** arr3);

double time(int m1, int n1, int n2, telem** arr1, telem** arr2, telem** arr3);

#endif