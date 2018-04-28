#include<cstddef>
#include<vector>

namespace pso {
	class solution {
		std::vector<double> values;

		public:
		solution(std::size_t size);
		std::size_t size() const;
		double& operator[](std::size_t idx);
		const double& operator[](std::size_t idx) const;
		solution operator+(const solution &b) const;
		solution operator-(const solution &b) const;
		solution operator*(const solution &b) const;
	};

	solution operator*(const double &a, const solution &b);

	class particle {
		solution _actual;
		solution _speed;

		solution _pbest;
		double _val_pbest;

		public:
		const solution pbest() const;
		solution update(double c1, double c2, solution gbest);
		virtual double evaluate() = 0;
	};
}

