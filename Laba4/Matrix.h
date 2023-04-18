
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

	void init(); // inits memory;
	void fill_random(); // fills matrix with random numbers in range [0; 99]
public:

	// Default constructor
	Matrix();

	// Construct with parametres (int size - size of the matrix.);
	Matrix(size_t size);

	// Copy constructor
	Matrix(const Matrix& matrix);

	// Do not use with uniform init!!! Constructor with initializer_list;
	Matrix(std::initializer_list<std::initializer_list<int>> list) throw(InvalidInitList);

	// Util functions
	int m_norm() const;
	int l_norm() const;
	double k_norm() const;
	int size() const;
	void clear();

	// Operators
	int* operator[](const int index) const { return memory[index]; }
	Matrix operator+(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

	~Matrix();
};