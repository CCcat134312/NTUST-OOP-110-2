// Name: 林信佑
// Date: 2022/4/12 下午 03:24:47
// Last Update: 2022/4/12 下午 03:24:47
// Problem statement: Design Polynomial Class
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Polynomial
{
private:
	std::vector<double> coefficients;

public:
	Polynomial();
	Polynomial(double*, int);
	Polynomial(const Polynomial&);

	int mySize() const;

	Polynomial& operator=(const Polynomial&);
	double& operator[](const unsigned int);

	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const double&);
	friend Polynomial operator+(const double&, const Polynomial&);

	friend Polynomial operator-(const Polynomial&, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, const double&);
	friend Polynomial operator-(const double&, const Polynomial&);

	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const double&);
	friend Polynomial operator*(const double&, const Polynomial&);

	friend double evaluate(const Polynomial&, double);
};

