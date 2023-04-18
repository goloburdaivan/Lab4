#include "Matrix.h"

int main() {
	Matrix matrix;

	std::cout << matrix;

	std::cout << "Matrix m-normal: " << matrix.m_norm() << std::endl;
	std::cout << "Matrix l-normal: " << matrix.l_norm() << std::endl;

	return 0;
}