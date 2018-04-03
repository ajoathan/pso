#include <iostream>

#include "pso.h"

int main() {
	pso::solution<5> s1, s2;
	for (int i=0; i<5; i++) {
		s1[i] = i;
		s2[i] = 5-i;
	}

	pso::solution<5> s3 = s1 + s2;
	for (int i=0; i<5; i++) {
		std::cout << s1[i] << "+" << s2[i] << "=" << s3[i] << std::endl;
	}

	std::cout << "Hello World!" << std::endl;
	return 0;
}

