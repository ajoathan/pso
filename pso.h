#include<cstddef>

namespace pso {
	template<size_t SIZE>
	class solution {
		double values[SIZE];

		public:
		double& operator[](std::size_t idx) {
			return values[idx];
		}

		const double& operator[](std::size_t idx) const {
			return values[idx];
		}
	};
}

