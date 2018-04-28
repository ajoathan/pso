#include<cstdlib>
#include<cmath>

#include "pso.h"

namespace pso {
	solution::solution(std::size_t size) {
		for (int i=0; i<size; i++) {
			values.push_back(0);
		}
	}

	std::size_t solution::size() const {
		return values.size();
	}

	double& solution::operator[](std::size_t idx) {
		return values[idx];
	}

	const double& solution::operator[](std::size_t idx) const {
		return values[idx];
	}

	solution solution::operator+(const solution &b) const {
		solution ret(b.size());
		for (int i=0; i<values.size(); i++) {
			ret[i] = values[i] + b[i];
		}
		return ret;
	}

	solution solution::operator-(const solution &b) const {
		solution ret(b.size());
		for (int i=0; i<values.size(); i++) {
			ret[i] = values[i] - b[i];
		}
		return ret;
	}

	solution solution::operator*(const solution &b) const {
		solution ret(b.size());
		for (int i=0; i<values.size(); i++) {
			ret[i] = values[i] * b[i];
		}
		return ret;
	}

	solution operator*(const double &a, const solution &b) {
		solution ret(b.size());
		for (int i=0; i<b.size(); i++) {
			ret[i] = a * b[i];
		}
		return ret;
	}

	const solution particle::pbest() const {
		return _pbest;
	}

	solution particle::update(double c1, double c2, solution gbest) {
		double psi = c1 + c2;
		double x = 2 / abs (2 - psi - sqrt(psi*psi - 4*psi));

		solution e1(gbest.size()), e2(gbest.size());
		for (int i=0; i<gbest.size(); i++) {
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
}

