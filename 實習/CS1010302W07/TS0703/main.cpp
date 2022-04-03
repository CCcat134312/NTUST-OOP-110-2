// Name: 林信佑
// Date: 2022/3/31 下午 03:00:38
// Last Update: 2022/3/31 下午 03:00:38
// Problem statement: Seven-segment Display
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma region definition

#define BLANK ' '
#define ROW '_'
#define COL '|'

bool table[10][7] = {
	{1,1,1,1,1,1,0},	// 0
	{0,1,1,0,0,0,0},	// 1
	{1,1,0,1,1,0,1},	// 2
	{1,1,1,1,0,0,1},	// 3
	{0,1,1,0,0,1,1},	// 4
	{1,0,1,1,0,1,1},	// 5
	{1,0,1,1,1,1,1},	// 6
	{1,1,1,0,0,0,0},	// 7
	{1,1,1,1,1,1,1},	// 8
	{1,1,1,1,0,1,1}		// 9
};

#pragma endregion

int main()
{
	for (string input; getline(cin, input); cout << '\n')
	{
#pragma region top part

		for (auto c : input)
		{
			if (!isdigit(c))
				continue;

			cout << BLANK;

			if (table[c - '0'][0])	// a segment
				cout << ROW;
			else
				cout << BLANK;

			cout << BLANK;
		}
		cout << '\n';

#pragma endregion

#pragma region middle part

		for (auto c : input)
		{
			if (!isdigit(c))
				continue;

			if (table[c - '0'][5])	// f segment
				cout << COL;
			else
				cout << BLANK;

			if (table[c - '0'][6])	// g segment
				cout << ROW;
			else
				cout << BLANK;

			if (table[c - '0'][1])	// b segment
				cout << COL;
			else
				cout << BLANK;
		}
		cout << '\n';

#pragma endregion

#pragma region bottom part

		for (auto c : input)
		{
			if (!isdigit(c))
				continue;

			if (table[c - '0'][4])	// e segment
				cout << COL;
			else
				cout << BLANK;

			if (table[c - '0'][3])	// d segment
				cout << ROW;
			else
				cout << BLANK;

			if (table[c - '0'][2])	// c segment
				cout << COL;
			else
				cout << BLANK;
		}

#pragma endregion
	}
	return 0;
}