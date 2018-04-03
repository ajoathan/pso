#include<cstddef>

namespace pso {
	template<size_t SIZE>
	class solution {
		double values[SIZE];

		public:
		double& operator[](std::size_t idx);
		const double& operator[](std::size_t idx) const;
		solution operator+(const solution &b) const;
	};
}

