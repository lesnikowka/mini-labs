#include "Header.h"


int main() {
	int m1, n1, m2, n2, m3, n3;
	scanf_s("%d %d", &m1, &n1);
	scanf_s("%d %d", &m2, &n2);
	srand(time(0));

	m3 = m1;
	n3 = n2;

	if (n1 != m2) {
		printf("invalid value");
		return 0;
	}

	telem** arr1 = create_arr(m1, n1);
	telem** arr2 = create_arr(m2, n2);
	telem** arr3 = create_arr(m3, n3);

	random_fill(m1, n1, arr1);
	random_fill(m2, n2, arr2);

	//printf("First matrix: ");
	//print_matr(m1, n1, arr1);
	//printf("\n\nSecond matrix: ");
	//print_matr(m2, n2, arr2);

	printf("\n\nTime: %lf", time(m1, n1, n2, arr1, arr2, arr3));
	
	//printf("\n\nResult matrix: ");
	//print_matr(m3, n3, arr3);

	free_arr(m1, arr1);
	free_arr(m2, arr2);
	free_arr(m3, arr3);

	return 0;
}