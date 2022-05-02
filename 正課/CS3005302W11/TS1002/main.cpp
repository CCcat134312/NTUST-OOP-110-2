// Name: ªL«H¦ö
// Date: 2022/5/2 ¤U¤È 04:32:41
// Last Update: 2022/5/2 ¤U¤È 04:32:41
// Problem statement: Word game
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
	Point(int x, int y) { this->x = x, this->y = y; };
};
bool dfs(vector<string> table, string word, int index, Point now)
{
	if (index == word.size())
	{
		int cnt(0);
		// count how many '0' in table 
		for (const auto& v : table)
		{
			for (const auto& i : v)
			{
				if (i == '0')
					cnt++;
			}
		}
		// if number of '0' equal to word.size() -> already reach end point
		if (cnt == index)
			return true;
	}
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			Point pTemp(now.x + i, now.y + j);
			if (pTemp.x < 0 || pTemp.x >= 4 || pTemp.y < 0 || pTemp.y >= 4)	// if point out of range -> continue 
				continue;

			char cTemp = table[pTemp.x][pTemp.y];
			if (cTemp == word[index])
			{
				table[pTemp.x][pTemp.y] = '0';
				if (dfs(table, word, index + 1, pTemp))
					return true;
				// if this path isn't connect make table recovery to the state that haven't choice this point
				table[pTemp.x][pTemp.y] = cTemp;
			}
		}
	}
	return false;
}
bool isValidWord(vector<string> table, string word)
{
	vector<Point> starts;
	// find all start point
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] == word[0])
				starts.push_back(Point(i, j));	// record the point that can be start point
		}
	}
	for (const auto& p : starts)
	{
		if (dfs(table, word, 0, p)) // if one path can reach end -> valid
			return true;
	}
	return false;
}
int main()
{
	for (string tableInput; cin >> tableInput; cout << '\n')
	{
		vector<string> table(4);
		table[0] = tableInput;
		for (int i = 0; i < 3; i++)
		{
			cin >> tableInput;
			table[i + 1] = tableInput;
		}
		ifstream fin("words.txt");
		for (string wordInput; fin >> wordInput;)
		{
			if (isValidWord(table, wordInput))
				cout << wordInput << '\n';
		}
		fin.close();
	}
	return 0;
}
