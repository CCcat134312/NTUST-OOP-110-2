// Name: 林信佑
// Date: 2022/3/17 下午 01:38:34
// Last Update: 2022/3/17 下午 01:38:34
// Problem statement: Sudoku Checker
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
bool checkRow(const vector<vector<char>>& sudoku)
{
	for (int row = 0; row < sudoku.size(); row++)
	{
		vector<bool> flag(9, false);
		for (int i = 0; i < sudoku[row].size(); i++)
		{
			int number = sudoku[row][i] - '1';
			if (number < 0 || number > 8)
				return false;
			if (flag[number])
				return false;
			flag[number] = true;
		}
	}
	return true;
}

bool checkCol(const vector<vector<char>>& sudoku)
{
	for (int col = 0; col < sudoku.size(); col++)
	{
		vector<bool> flag(9, false);
		for (int i = 0; i < sudoku[col].size(); i++)
		{
			int number = sudoku[i][col] - '1';
			if (number < 0 || number > 8)
				return false;
			if (flag[number])
				return false;
			flag[number] = true;
		}
	}
	return true;
}

bool checkBlock(const vector<vector<char>>& sudoku)
{
	for (int i = 0; i < sudoku.size(); i += 3)
	{
		for (int j = 0; j < sudoku[i].size(); j += 3)
		{
			vector<bool> flag(9, false);
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					int number = sudoku[i + x][j + y] - '1';
					if (number < 0 || number > 8)
						return false;
					if (flag[number])
						return false;
					flag[number] = true;
				}
			}
		}
	}
	return true;
}

bool isValidSudoku(const vector<vector<char>>& sudoku)
{
	if (checkRow(sudoku) && checkCol(sudoku) && checkBlock(sudoku))
		return true;
	return false;
}

int main()
{
	string input, num;
	while (getline(cin, input))
	{
		vector<vector<char>> sudoku(9, vector<char>(9));
		for (int i = 0; i < 9; i++)
		{
			stringstream ss(input);
			for (int col = 0; getline(ss, num, ',') && col < 9; col++)	// split input data
				sudoku[i][col] = num[0];

			getline(cin, input);	// ignore \n
		}
		if (isValidSudoku(sudoku))
			cout << "True\n";
		else
			cout << "False\n";
	}
	return 0;
}