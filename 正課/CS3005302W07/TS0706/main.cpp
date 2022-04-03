// Name: 林信佑
// Date: 2022/3/29 下午 08:23:23
// Last Update: 2022/3/29 下午 08:23:23
// Problem statement: Shisensho
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Point.h"
using namespace std;

enum class direction :int { UP, DOWN, RIGHT, LEFT };

// mapping direction to point which used to move "one block"
Point mapDirection(direction dir)
{
	switch (dir)
	{
	case direction::UP:
		return Point(0, -1);
	case direction::DOWN:
		return Point(0, 1);
	case direction::RIGHT:
		return Point(1, 0);
	case direction::LEFT:
		return Point(-1, 0);
	}
}

// reset the path that already had been walked
void resetGraph(vector<vector<int>>& graph)
{
	for (auto& v : graph)
	{
		for (auto& i : v)
		{
			if (i == -1)
				i = 0;
		}
	}
}

bool dfs(vector<vector<int>>& graph, Point now, const Point& end, direction nowFace, int turnTimes)
{
	vector<direction> dirs = { direction::UP, direction::DOWN, direction::RIGHT, direction::LEFT };
	for (const auto& d : dirs)
	{
		Point temp = now + mapDirection(d);
		// handle direction limit
		int turnTemp = (int)(d != nowFace) + turnTimes;

		// reach end
		if (temp == end)
		{
			resetGraph(graph);
			if (turnTemp <= 2)
				return true;
			else
				return false;
		}

		// not reach end
		if (temp.inRange(8) && graph[temp.y][temp.x] == 0 && turnTemp <= 2)
		{
			graph[temp.y][temp.x] = -1;

			// if next step can reach end then this step can as well
			if (dfs(graph, temp, end, d, turnTemp))
			{
				resetGraph(graph);
				return true;
			}
		}
	}
	resetGraph(graph);
	return false;
}

// true: error | false: no problem
bool foolproofInput(const vector<vector<int>>& graph, const Point& start, const Point& end)
{
	if (!start.inRange(7) || !end.inRange(7))
		return true;
	if (start == end)
		return true;

	int startNum = graph[start.y][start.x], endNum = graph[end.y][end.x];
	if (startNum != endNum)
		return true;
	if (startNum == 0 || endNum == 0)
		return true;
	return false;
}

int main()
{
	vector<vector<int>> graph(8, vector<int>(8, 0));
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
			cin >> graph[i][j];
	}
	for (Point start, end; cin >> start >> end;)
	{
		if (foolproofInput(graph, start, end))
		{
			cout << "bad pair\n";
			continue;
		}

		// start from every direction
		bool flag = false;
		vector<direction> dirs = { direction::UP, direction::DOWN, direction::RIGHT, direction::LEFT };
		for (const auto& d : dirs)
		{
			Point temp = start + mapDirection(d);
			if (graph[temp.y][temp.x] == 0)
			{
				graph[temp.y][temp.x] = -1;
				if (dfs(graph, temp, end, d, 0))
					flag = true;
			}
			else if (temp == end)
				flag = true;
		}
		if (flag)
		{
			// clear matched number
			graph[start.y][start.x] = 0;
			graph[end.y][end.x] = 0;
			cout << "pair matched\n";
		}
		else
			cout << "bad pair\n";
	}
	return 0;
}