// Name: 林信佑
// Date: 2022/3/3 下午 01:26:30
// Last Update: 2022/3/3 下午 01:26:30
// Problem statement: Input_Output3
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int getDigitSize(string input)
{
	int res(0);
	for (char c : input)
	{
		if (c == '.')
			return res;
		res++;
	}
	return res;
}

int main()
{
	for (string input; cin >> input;)
	{
		int allSize, pointSize;
		char setChar;
		cin >> allSize >> pointSize;
		setChar = getchar();	// ignore space that used to separate
		setChar = getchar();

		int digitSize = getDigitSize(input);	// get digit length before '.'
		if (pointSize > 0)
			allSize -= (pointSize + 1);
		allSize -= digitSize;

		string output = "";
		for (int i = 0; i < allSize; i++)	// compensate with input char
			output += setChar;

		int index = 0;
		for (char c : input)	// add integer number
		{
			if (c == '.')
				break;
			output += c;
			index++;
		}

		// add decimal part to output string
		if (pointSize > 0)
		{
			output += '.';
			index++;
		}
		for (int i = 0; i < pointSize; i++, index++)
		{
			if (index >= input.size())	// if index out of range, add '0'
				output += '0';
			else
				output += input[index];
		}
		cout << output << '\n';
	}
	return 0;
}