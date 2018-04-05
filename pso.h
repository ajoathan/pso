#include<cstddef>
#include<vector>

namespace pso {
	template<size_t SIZE>
	class solution {
		double values[SIZE];

		public:
		double& operator[](std::size_t idx);
		const double& operator[](std::size_t idx) const;
		solution operator+(const solution &b) const;
		solution operator-(const solution &b) const;
		solution operator*(const solution &b) const;
	};

	template<size_t SIZE>
	solution<SIZE> operator*(const double a, const solution<SIZE> &b);

	template<size_t SIZE>
	class particle {
		solution<SIZE> _actual;
		solution<SIZE> _speed;

		solution<SIZE> _pbest;
		double _val_pbest;

		public:
		const solution<SIZE> pbest() const;
		solution<SIZE> update(double c1, double c2, solution<SIZE> gbest);
		virtual double evaluate() = 0;
	};
}

