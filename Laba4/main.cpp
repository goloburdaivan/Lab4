#include "Matrix.h"

int main() {
	Matrix matrix;

	std::cout << matrix;

	Matrix copy = matrix;

	std::cout << "Matrix m-normal: " << matrix.m_norm() << std::endl;
	std::cout << "Matrix l-normal: " << matrix.l_norm() << std::endl;
	std::cout << "Matrix k-normal: " << matrix.k_norm() << std::endl;

	try {
		Matrix init_list = { {1, 2, 3}, {3, 4, 5}, {6, 7, 8} };

		std::cout << init_list + copy << std::endl;
	}
	catch (const InvalidInitList& exception) {
		std::cout << exception.info() << std::endl;
	}

	return 0;
}