// Name: 林信佑
// Date: 2022/3/31 下午 03:06:23
// Last Update: 2022/3/31 下午 03:06:23
// Problem statement: Cow calculation
#include <iostream>
#include <string>
using namespace std;

int strToint(string number)
{
	int result(0);
	for (auto c : number)
	{
		result *= 4;
		if (c == 'U')
			result += 1;
		else if (c == 'C')
			result += 2;
		else if (c == 'D')
			result += 3;
	}
	return result;
}

int main()
{
	cout << "COWCULATIONS OUTPUT\n";
	int times;
	for (cin >> times; times--;)
	{
		string input1, input2;
		cin >> input1 >> input2;
		int num1 = strToint(input1), num2 = strToint(input2);
		for (int i = 0; i < 3; i++)
		{
			char op;
			cin >> op;
			if (op == 'A')
				num2 += num1;
			else if (op == 'R')
				num2 >>= 2;
			else if (op == 'L')
				num2 <<= 2;
		}
		string answer;
		cin >> answer;
		if (strToint(answer) == num2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}