// Name: 林信佑
// Date: 2022/5/7 上午 10:51:49
// Last Update: 2022/5/7 上午 10:51:49
// Problem statement: Matrix Multiplication
#include "Matrix.h"

Matrix::Matrix(int row, int col)
{
	this->row = row;
	this->col = col;
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
	}
}

std::istream& operator>>(std::istream& is, Matrix& matrix)
{
	for (auto& v : matrix.data)
	{
		for (auto& i : v)
			is >> i;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
	for (int i = 0; i < matrix.data.size(); i++)
	{
		for (int j = 0; j < matrix.data[i].size(); j++)
		{
			os << matrix.data[i][j];
			if (j != matrix.data[i].size() - 1)
				os << ' ';
		}
		if (i != matrix.data.size() - 1)
			os << '\n';
	}
	return os;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	Matrix result(m1.row, m2.col);
	for (int i = 0; i < result.row; i++)
	{
		for (int j = 0; j < result.col; j++)
		{
			result.data[i][j] = 0;
			for (int k = 0; k < m1.col; k++)
				result.data[i][j] += (m1.data[i][k] * m2.data[k][j]);
		}
	}
	return result;
}