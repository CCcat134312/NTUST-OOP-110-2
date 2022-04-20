// Name: 林信佑
// Date: 2022/4/20 下午 03:29:36
// Last Update: 2022/4/20 下午 03:29:36
// Problem statement: The Translation Machine
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// generate and initialize the table
vector<vector<bool>> generateTable()
{
	vector<vector<bool>> table(26, vector<bool>(26, false));
	for (int i = 0; i < 26; i++)
		table[i][i] = true;
	return table;
}

// judge that begin can be translated to end
bool canSwitch(vector<vector<bool>>& table, int begin, int end)
{
	if (table[begin][end])
		return true;

	vector<bool> visited(26, false);
	queue<int> myQue;
	// bfs
	myQue.push(begin);
	for (int num; !myQue.empty(); myQue.pop())
	{
		num = myQue.front();
		for (int i = 0; i < 26; i++)
		{
			if (table[num][i] && !visited[i])
			{
				visited[i] = true;
				myQue.push(i);
			}
		}
	}
	return visited[end];
}

int main()
{
	// read data until EOF
	for (int pairNum, queNum; cin >> pairNum >> queNum;)
	{
		// pairNum and queNum -> end the program
		if (pairNum == 0 && queNum == 0)
			break;

		auto table = generateTable();
		// get datas which begin can be translated to end
		for (char begin, end; pairNum--;)
		{
			cin >> begin >> end;
			table[begin - 'a'][end - 'a'] = true;
		}

		// get query
		for (string input1, input2; queNum--;)
		{
			cin >> input1 >> input2;
			// length is not the same
			if (input1.size() != input2.size())
			{
				cout << "no\n";
				continue;
			}

			bool flag(true);
			for (int i = 0; i < input1.size(); i++)
			{
				// if one character can't be translated to another -> translate fail
				if (!canSwitch(table, input1[i] - 'a', input2[i] - 'a'))
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
	return 0;
}