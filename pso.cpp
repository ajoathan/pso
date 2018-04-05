#include<cstdlib>
#include<cmath>

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
	solution<SIZE> solution<SIZE>::operator-(const solution &b) const {
		solution<SIZE> ret;
		for (int i=0; i<SIZE; i++) {
			ret[i] = values[i] - b[i];
		}
		return ret;
	}

	template<size_t SIZE>
	solution<SIZE> solution<SIZE>::operator*(const solution &b) const {
		solution<SIZE> ret;
		for (int i=0; i<SIZE; i++) {
			ret[i] = values[i] * b[i];
		}
		return ret;
	}

	template<size_t SIZE>
	solution<SIZE> operator*(const double a, const solution<SIZE> &b) {
		solution<SIZE> ret;
		for (int i=0; i<SIZE; i++) {
			ret[i] = a * b[i];
		}
		return ret;
	}

	template<size_t SIZE>
	const solution<SIZE> particle<SIZE>::pbest() const {
		return _pbest;
	}

	template<size_t SIZE>
	solution<SIZE> particle<SIZE>::update(
			double c1, double c2, solution<SIZE> gbest) {
		double psi = c1 + c2;
		double x = 2 / abs (2 - psi - sqrt(psi*psi - 4*psi));

		solution<SIZE> e1, e2;
		for (int i=0; i<SIZE; i++) {
			e1[i] = (double) rand() / RAND_MAX;
			e2[i] = (double) rand() / RAND_MAX;
		}

		_speed = x * (_speed + c1 * e1 * (_pbest - _actual)
				+ c2 * e2 * (gbest - _actual));
		_actual = _actual + _speed;

		if (evaluate() > _val_pbest) {
			_val_pbest = evaluate();
			_pbest = _actual;
		}
		return _actual;
	}

	template class solution<5>;
	template class particle<5>;
}

