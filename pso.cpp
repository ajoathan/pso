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

	template<size_t SIZE>
	const solution<SIZE> particle<SIZE>::pbest() const {
		return _pbest;
	}

	template<size_t SIZE>
	const solution<SIZE> particle<SIZE>::nbest() const {
		double val_nbest = 0;
		particle<SIZE> *nbest;
		for (auto const& neighbor : neighbors) {
			if (neighbor->evaluate() > val_nbest) {
				val_nbest = neighbor->evaluate();
				nbest = neighbor;
			}
		}
		return nbest->pbest();
	}

	template<size_t SIZE>
	void particle<SIZE>::update() {
//		speed = speed + 
	}

	template class solution<5>;
	template class particle<5>;
}

