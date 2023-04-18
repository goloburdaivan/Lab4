#include<memory>
#pragma once

class Matrix {
private:
	std::unique_ptr<std::unique_ptr<int[]>> memory;
	int _size;
public:

	// Default constructor
	Matrix() {}

	// Construct with parametres (int size - size of the matrix.);
	Matrix(int size) {}

	// Do not use with uniform init!!!
	Matrix(std::initializer_list<std::initializer_list<int>>);

	double m_norm() const;
	double l_norm() const;
	double k_norm() const;

	friend Matrix operator+(const Matrix& matrix);
	friend Matrix operator*(const Matrix& matrix);

	~Matrix();
};