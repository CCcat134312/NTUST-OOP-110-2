// Name: 林信佑
// Date: 2022/4/12 下午 03:24:47
// Last Update: 2022/4/12 下午 03:24:47
// Problem statement: Design Polynomial Class
#include "Polynomial.h"

Polynomial::Polynomial()
{
	coefficients = {};
}

Polynomial::Polynomial(double* arr, int size)
{
	coefficients = std::vector<double>(arr, arr + size);
}

Polynomial::Polynomial(const Polynomial& arg)
{
	coefficients = arg.coefficients;
}

int Polynomial::mySize() const
{
	for (int i = coefficients.size() - 1; i >= 0; i--)
	{
		if (coefficients[i] != 0)
			return i + 1;
	}
	return 0;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
	coefficients = rhs.coefficients;
	return *this;
}

double& Polynomial::operator[](const unsigned int index)
{
	while (index > coefficients.size() - 1)
		coefficients.push_back(0);
	return coefficients[index];
}

#pragma region operator+
Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{
	int p1Size = p1.coefficients.size(), p2Size = p2.coefficients.size();
	int maxSize = std::max(p1Size, p2Size);
	Polynomial newPoly;
	for (int i = 0; i < maxSize; i++)
	{
		int temp = 0;
		if (i < p1Size)
			temp += p1.coefficients[i];
		if (i < p2Size)
			temp += p2.coefficients[i];
		newPoly.coefficients.push_back(temp);
	}
	return newPoly;
}

Polynomial operator+(const Polynomial& p1, const double& add)
{
	Polynomial newPoly = p1;
	if (newPoly.coefficients.size() == 0)
		newPoly.coefficients.push_back(add);
	else
		newPoly.coefficients[0] += add;
	return newPoly;
}

Polynomial operator+(const double& add, const Polynomial& p1)
{
	Polynomial newPoly = p1;
	if (newPoly.coefficients.size() == 0)
		newPoly.coefficients.push_back(add);
	else
		newPoly.coefficients[0] += add;
	return newPoly;
}
#pragma endregion operator+

#pragma region operator-
Polynomial operator-(const Polynomial& p1, const Polynomial& p2)
{
	int p1Size = p1.coefficients.size(), p2Size = p2.coefficients.size();
	int maxSize = std::max(p1Size, p2Size);
	Polynomial newPoly;
	for (int i = 0; i < maxSize; i++)
	{
		int temp = 0;
		if (i < p1Size)
			temp += p1.coefficients[i];
		if (i < p2Size)
			temp -= p2.coefficients[i];
		newPoly.coefficients.push_back(temp);
	}
	return newPoly;
}

Polynomial operator-(const Polynomial& p1, const double& sub)
{
	Polynomial newPoly = p1;
	if (newPoly.coefficients.size() == 0)
		newPoly.coefficients.push_back(-sub);
	else
		newPoly.coefficients[0] -= sub;
	return newPoly;
}

Polynomial operator-(const double& sub, const Polynomial& p1)
{
	Polynomial newPoly = p1;
	for (auto& c : newPoly.coefficients)
		c *= -1;

	if (newPoly.coefficients.size() == 0)
		newPoly.coefficients.push_back(sub);
	else
		newPoly.coefficients[0] += sub;
	return newPoly;
}
#pragma endregion operator-

#pragma region operator*
Polynomial operator*(const Polynomial& p1, const Polynomial& p2)
{
	int p1Size = p1.coefficients.size(), p2Size = p2.coefficients.size();
	Polynomial newPoly;
	newPoly.coefficients = std::vector<double>(p1Size + p2Size - 1, 0);	// p1Size - 1 + p2Size - 1 + 1
	for (int i = 0; i < p1Size; i++)
	{
		for (int j = 0; j < p2Size; j++)
		{
			newPoly[i + j] += p1.coefficients[i] * p2.coefficients[j];
		}
	}
	return newPoly;
}

Polynomial operator*(const Polynomial& poly, const double& mul)
{
	Polynomial newPoly = poly;
	for (auto& i : newPoly.coefficients)
		i *= mul;
	return newPoly;
}

Polynomial operator*(const double& mul, const Polynomial& poly)
{
	Polynomial newPoly = poly;
	for (auto& i : newPoly.coefficients)
		i *= mul;
	return newPoly;
}
#pragma endregion operator*

double evaluate(const Polynomial& poly, double arg)
{
	double result(0);
	for (int i = 0; i < poly.coefficients.size(); i++)
	{
		int mul = 1;
		for (int j = 0; j < i; j++)
			mul *= arg;
		result += (mul * poly.coefficients[i]);
	}
	return result;
}
