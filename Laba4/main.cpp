#include "Matrix.h"

int main() {
	Matrix matrix(5);

	std::cout << matrix;

	std::cout << "Matrix m-normal: " << matrix.m_norm() << std::endl;
	std::cout << "Matrix l-normal: " << matrix.l_norm() << std::endl;
	std::cout << "Matrix k-normal: " << matrix.k_norm() << std::endl;

	return 0;
}