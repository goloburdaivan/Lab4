#include "Matrix.h"

void Matrix::init() {
#ifdef _DEBUG
	std::cout << "[DEBUG] Memory init." << std::endl;
#endif // _DEBUG

	memory = new int* [_size];

	for (size_t i = 0; i < _size; i++) {
		memory[i] = new int[_size];
	}
}

Matrix::~Matrix() {
	
#ifdef _DEBUG
	std::cout << "[DEBUG] Destructor called" << std::endl;
#endif // _DEBUG

	for (size_t i = 0; i < _size; i++) {
		delete[] memory[i];
	}

	delete[] memory;
}

int Matrix::m_norm() const {

	int max = 0;
	int sum = 0;

	for (size_t i = 0; i < _size; i++) {

		sum = 0;

		for (size_t j = 0; j < _size; j++) {
			sum += memory[i][j];
		}

		if (sum > max) {
			max = sum;
		}
	}

	return max;
}

Matrix::Matrix(): _size(3) {

	init();

	srand(time(NULL));

	for (size_t i = 0; i < _size; i++) {
		for (size_t j = 0; j < _size; j++) {
			memory[i][j] = rand() % 100;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
	for (size_t i = 0; i < matrix._size; i++) {
		for (size_t j = 0; j < matrix._size; j++) {
			out << std::setw(5) << std::setfill(' ') << matrix.memory[i][j] << " ";
		}

		out << std::endl;
	}

	return out;
}