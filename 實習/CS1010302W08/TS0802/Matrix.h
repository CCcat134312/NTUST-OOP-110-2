// Name: 林信佑
// Date: 2022/4/7 下午 01:27:48
// Last Update: 2022/4/7 下午 01:27:48
// Problem statement: Matrix Multiplication
#pragma once
#include <vector>
#include <iostream>

class Matrix
{
public:
	int row;
	int col;

	std::vector<std::vector<int>> data;

	Matrix(int = 0, int = 0);

	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, Matrix&);

	friend Matrix operator*(const Matrix&, const Matrix&);
};

