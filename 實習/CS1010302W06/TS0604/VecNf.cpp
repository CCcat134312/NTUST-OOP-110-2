// Name: 林信佑
// Date: 2022/3/24 下午 01:36:01
// Last Update: 2022/3/24 下午 01:36:01
// Problem statement: N Dim Vector
#include "VecNf.h"

VecNf::VecNf()
{
	data = { 0.0f };
}

VecNf::VecNf(float* dest, int cnt)
{
	for (int i = 0; i < cnt; i++)
		data.push_back(dest[i]);
}

VecNf::VecNf(const VecNf& rhs)
{
	data = rhs.data;
}

int VecNf::Size() const
{
	return data.size();
}

VecNf& VecNf::operator=(const VecNf& vecnf)
{
	std::cout << "ASSIGNMENT!!!\n";
	data = vecnf.data;
	return *this;
}

float& VecNf::operator[](int index)
{
	return data[index];
}

VecNf operator+(const VecNf& v1, const VecNf& v2)
{
	VecNf result;
	if (v1.Size() != v2.Size())
	{
		std::cout << "dimensions inconsistent\n";
		return result;
	}
	int size = v1.Size();
	result.data[0] = v1.data[0] + v2.data[0];
	for (int i = 1; i < size; i++)
		result.data.push_back(v1.data[i] + v2.data[i]);
	return result;
}

VecNf operator-(const VecNf& v1, const VecNf& v2)
{
	VecNf result;
	if (v1.Size() != v2.Size())
	{
		std::cout << "dimensions inconsistent\n";
		return result;
	}
	int size = v1.Size();
	result.data[0] = v1.data[0] - v2.data[0];
	for (int i = 1; i < size; i++)
		result.data.push_back(v1.data[i] - v2.data[i]);
	return result;
}

float operator*(const VecNf& v1, const VecNf& v2)
{
	float result(0);
	if (v1.Size() != v2.Size())
	{
		std::cout << "dimensions inconsistent\n";
		return result;
	}
	int size = v1.Size();
	for (int i = 0; i < size; i++)
		result += v1.data[i] * v2.data[i];
	return result;
}

VecNf operator*(const VecNf& v1, float mul)
{
	VecNf newVec;
	newVec.data.clear();
	for (const auto& f : v1.data)
		newVec.data.push_back(f * mul);
	return newVec;
}

VecNf operator*(float mul,const VecNf& v1)
{
	VecNf newVec;
	newVec.data.clear();
	for (const auto& f : v1.data)
		newVec.data.push_back(f * mul);
	return newVec;
}