// Name: 林信佑
// Date: 2022/2/24 下午 03:49:52
// Last Update: 2022/2/24 下午 03:49:52
// Problem statement: Adding Large Numbers
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct BigInt
{
	BigInt(string);
	string number;
	int size;
};

BigInt::BigInt(string _number)
{
	number = _number;
	size = number.size();
}

BigInt Add(const BigInt& lhs, const BigInt& rhs)
{
	string res = "";
	int lhsSize = lhs.size - 1, rhsSize = rhs.size - 1;	// index of number
	bool carry(false);
	for (int temp(0); lhsSize >= 0 || rhsSize >= 0; lhsSize--, rhsSize--)
	{
		// init the number used to sum two digits
		temp = 0;

		// add two digits (if index is not out of range then add)
		if (lhsSize >= 0)
			temp += (lhs.number[lhsSize] - '0');
		if (rhsSize >= 0)
			temp += (rhs.number[rhsSize] - '0');

		// add last carry
		if (carry)
			temp++;

		// if temp > 9 -> need to add 1 in next loop
		carry = temp > 9;

		// put current digit to result
		res = (char)((temp % 10) + '0') + res;
	}
	if (carry)	// add one more digit to result (99 + 1 = 100)
		res = "1" + res;
	return BigInt(res);
}

// overload operator<<
ostream& operator<<(ostream& os, BigInt& bi)
{
	os << bi.number;
	return os;
}

bool checkInput(string input)
{
	for (char c : input)
		if (!(c >= '0' && c <= '9'))
			return false;	// invalid input

	return true;	// valid input
}

int main()
{
	int addTimes;
	cin >> addTimes;

	for (int i = 0; i < addTimes; i++)
	{
		string inputA, inputB;
		cin >> inputA >> inputB;

		// if a or b is invalid then continue and output error
		if (!checkInput(inputA) || !checkInput(inputB))
		{
			cout << "Not a valid number, please try again.\n";
			continue;
		}

		BigInt a(inputA), b(inputB);
		BigInt result = Add(a, b);
		cout << result << '\n';
	}
	
	return 0;
}