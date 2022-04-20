// Name: 林信佑
// Date: 2022/4/20 下午 03:39:24
// Last Update: 2022/4/20 下午 03:39:24
// Problem statement: Namespace

#include "user.h"

namespace Authenticate
{
	string username;
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}

namespace
{
	bool isValid()
	{
		if (Authenticate::username.size() != 8)
			return false;
		for (const auto& c : Authenticate::username)
		{
			if (!isalpha(c))
				return false;
		}
		return true;
	}
}