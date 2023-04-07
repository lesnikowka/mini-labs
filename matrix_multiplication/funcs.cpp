#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int telem;

telem** create_arr(int m, int n) {
	telem** arr = (telem**)malloc(m * sizeof(telem*));
	for (int i = 0; i < m; i++)
		arr[i] = (telem*)calloc(n, sizeof(telem));
	return arr;
}

void random_fill(int m, int n, telem** arr) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = (telem)rand();
}

void free_arr(int m, telem** arr) {
	for (int i = 0; i < m; i++)
		free(arr[i]);
	free(arr);
}

void print_matr(int m, int n, telem** arr) {
	printf("\n");
	for (int i = 0; i < m; i++) {
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%d   ", arr[i][j]);
	}
}

void mult_matrices1(int m1, int n1, int n2, telem** arr1, telem** arr2, telem** arr3) {
	for (int i = 0; i < m1; i++)
		for (int k = 0; k < n1; k++)
			for (int j = 0; j < n2; j++)
				arr3[i][j] += arr1[i][k] * arr2[k][j];
}

void mult_matrices2(int m1, int n1, int n2, telem** arr1, telem** arr2, telem** arr3) {
	for (int k = 0; k < n1; k++)
		for (int i = 0; i < m1; i++)
			for (int j = 0; j < n2; j++)
				arr3[i][j] += arr1[i][k] * arr2[k][j];
}

double time(int m1, int n1, int n2, telem** arr1, telem** arr2, telem** arr3) {
	double start, end;
	
	start = clock();
	mult_matrices1(m1, n1, n2, arr1, arr2, arr3);
	end = clock();
	
	return (end - start) / CLK_TCK;
}
