// Name: 林信佑
// Date: 2022/3/24 下午 01:36:01
// Last Update: 2022/3/24 下午 01:36:01
// Problem statement: N Dim Vector
#pragma once
#include <iostream>
#include <vector>

class VecNf
{
private:
	std::vector<float> data;
public:
	VecNf();
	VecNf(float*, int);
	VecNf(const VecNf&);

	int Size() const;

	VecNf& operator=(const VecNf&);
	float& operator[](int);

	friend VecNf operator+(const VecNf&, const VecNf&);
	friend VecNf operator-(const VecNf&, const VecNf&);
	friend float operator*(const VecNf&, const VecNf&);
	friend VecNf operator*(float, const VecNf&);
	friend VecNf operator*(const VecNf&, float);
};

