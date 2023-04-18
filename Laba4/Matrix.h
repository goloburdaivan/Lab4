
// For debugging
#define _DEBUG

// Standart libs.
#include<iostream>
#include<iomanip>
#include<memory>
#include "InvalidInitList.h"

#pragma once

class Matrix {
private:
	int** memory = nullptr;
	size_t _size;

	void init();

	void fill_random();
public:

	// Default constructor
	Matrix();

	// Construct with parametres (int size - size of the matrix.);
	Matrix(size_t size);

	// Copy constructor
	Matrix(Matrix& matrix);

	// Do not use with uniform init!!!
	Matrix(std::initializer_list<std::initializer_list<int>> list) throw(InvalidInitList);

	int m_norm() const;
	int l_norm() const;
	double k_norm() const;


	int* operator[](const int index) const {
		return memory[index];
	}

	friend Matrix operator+(const Matrix& matrix);
	friend Matrix operator*(const Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

	~Matrix();
};