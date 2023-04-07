#include <iostream>
#include "Vector.h"
#include "Matrix.h"


int main() {
	int m, n;
	std::cout << "Enter size: ";
	std::cin >> m>> n;
	Matrix a(m, n), b(m, n), c(n,m), d;

	std::cin >> a>> b>> c;

	d = a + b;
	std::cout << d;
	d = a * c;
	std::cout << d;
	a += b;
	std::cout << a;


	return 0;
}

