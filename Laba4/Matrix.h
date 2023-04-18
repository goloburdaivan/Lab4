
// For debugging
#define _DEBUG

// Standart libs.
#include<iostream>
#include<iomanip>
#include<memory>



#pragma once

class Matrix {
private:
	int** memory;
	size_t _size;

	void init();
public:

	// Default constructor
	Matrix();

	// Construct with parametres (int size - size of the matrix.);
	Matrix(int size);

	// Copy constructor
	Matrix(Matrix& matrix);

	// Do not use with uniform init!!!
	Matrix(std::initializer_list<std::initializer_list<int>>);

	int m_norm() const;
	int l_norm() const;
	double k_norm() const;

	friend Matrix operator+(const Matrix& matrix);
	friend Matrix operator*(const Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

	~Matrix();
};