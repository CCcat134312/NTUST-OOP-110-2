// Name: 林信佑
// Date: 2022/4/20 下午 03:39:24
// Last Update: 2022/4/20 下午 03:39:24
// Problem statement: Namespace
#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Authenticate
{
	void inputPassword();
	string getPassword();
}

namespace
{
	bool isValid();
}