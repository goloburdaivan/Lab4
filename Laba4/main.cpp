#include "Matrix.h"

int main() {
	
	try {
		Matrix matrix1;
		Matrix matrix2 = {
			{42, 53, 59},
			{13, 31, 89},
			{78, 21, 21}
		};

		std::cout << "Matrix1: " << std::endl;
		std::cout << matrix1;

		std::cout << "Matrix2: " << std::endl;
		std::cout << matrix2;

		Matrix matrix3 = matrix1 + matrix2;

		std::cout << "Matrix1 + Matrix2: " << std::endl;
		std::cout << matrix3;

		std::cout << "(Matrix3)^2: " << std::endl;
		std::cout << matrix3 * matrix3;

		std::cout << "Matrix m-normal: " << matrix3.m_norm() << std::endl;
		std::cout << "Matrix l-normal: " << matrix3.l_norm() << std::endl;
		std::cout << "Matrix k-normal: " << matrix3.k_norm() << std::endl;
	}
	catch (const InvalidInitList& exception) {
		std::cout << exception.info();
	}

	return 0;
}