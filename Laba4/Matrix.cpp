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

void Matrix::fill_random() {
	srand(time(NULL));
	for (size_t i = 0; i < _size; i++) {
		for (size_t j = 0; j < _size; j++) {
			memory[i][j] = rand() % 100;
		}
	}
}

Matrix::Matrix() : _size(3) {

	init();
	fill_random();
}

Matrix::Matrix(size_t size) : _size(size) {
	init();
	fill_random();
}

Matrix::Matrix(Matrix& matrix) : _size(matrix._size) {

	if (matrix.memory != nullptr) {
		init();
		for (size_t i = 0; i < _size; i++) {
			for (size_t j = 0; j < _size; j++) {
				memory[i][j] = matrix.memory[i][j];
			}
		}
	}
}

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> list) throw(InvalidInitList) {

#ifdef _DEBUG
	std::cout << "[DEBUG] Called init list constructor" << std::endl;
#endif // _DEBUG


	size_t rows = list.size();

	for (auto row : list) {
		if (row.size() != rows) throw InvalidInitList();
	}

	_size = rows;

	init();

	size_t i = 0;
	size_t j = 0;
	for (auto row : list) {
		j = 0;
		for (auto element : row) {
			memory[i][j++] = element;
		}

		i++;
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

int Matrix::l_norm() const {
	int max = 0;
	int sum = 0;

	for (size_t i = 0; i < _size; i++) {

		sum = 0;

		for (size_t j = 0; j < _size; j++) {
			sum += memory[j][i];
		}

		if (sum > max) {
			max = sum;
		}
	}

	return max;
}

double Matrix::k_norm() const {

	double sum = 0;

	for (size_t i = 0; i < _size; i++) {
		for (size_t j = 0; j < _size; j++) {
			sum += pow(memory[i][j], 2);
		}
	}

	return sqrt(sum);
}

int Matrix::size() const {
	return _size;
}

void Matrix::clear() {
	for (size_t i = 0; i < _size; i++) {
		for (size_t j = 0; j < _size; j++) {
			memory[i][j] = 0;
		}
	}
}

Matrix Matrix::operator+(const Matrix& matrix) {
	size_t size = matrix.size();
	Matrix result(size);

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			result[i][j] = memory[i][j] + matrix[i][j];
		}
	}

	return result;
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