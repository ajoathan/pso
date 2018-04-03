#include "pso.h"

namespace pso {
	template<size_t SIZE>
	double& solution<SIZE>::operator[](std::size_t idx) {
		return values[idx];
	}

	template<size_t SIZE>
	const double& solution<SIZE>::operator[](std::size_t idx) const {
		return values[idx];
	}

	template<size_t SIZE>
	solution<SIZE> solution<SIZE>::operator+(const solution &b) const {
		solution<SIZE> ret;
		for (int i=0; i<SIZE; i++) {
			ret[i] = values[i] + b[i];
		}
		return ret;
	}

	template class solution<5>;
}

