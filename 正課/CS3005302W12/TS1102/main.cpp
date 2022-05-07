// Name: 林信佑
// Date: 2022/5/7 上午 10:51:49
// Last Update: 2022/5/7 上午 10:51:49
// Problem statement: Matrix Multiplication
#include <iostream>

#include "Matrix.h"
using namespace std;

int main()
{
	// get two matrix row and column
	int m1r, m1c, m2r, m2c;
	cin >> m1r >> m1c >> m2r >> m2c;
	Matrix m1(m1r, m1c), m2(m2r, m2c);
	cin >> m1 >> m2;
	if (m1.col == m2.row)
	{
		Matrix result = m1 * m2;
		cout << result;
	}
	else
		cout << "Matrix multiplication failed.\n";
	return 0;
}