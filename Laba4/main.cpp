#include "Matrix.h"

int main() {
	Matrix matrix;

	std::cout << matrix;

	std::cout << "Matrix m-normal: " << matrix.m_norm() << std::endl;

	return 0;
}