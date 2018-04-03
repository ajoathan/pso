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
	};

	template<size_t SIZE>
	class particle {
		solution<SIZE> _actual;
		solution<SIZE> _speed;

		solution<SIZE> _pbest;
		std::vector<particle<SIZE>*> neighbors;

		public:
		const solution<SIZE> pbest() const;
		const solution<SIZE> nbest() const;
		void update();
		virtual double evaluate() = 0;
	};
}

