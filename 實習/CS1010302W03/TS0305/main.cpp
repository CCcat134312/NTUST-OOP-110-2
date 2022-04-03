// Name: 林信佑
// Date: 2022/3/3 下午 01:36:21
// Last Update: 2022/3/3 下午 01:36:21
// Problem statement: 2-Dimension Array
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x, y;
	Point(int = 0, int = 0);
};

Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

istream& operator >>(istream& is, Point& p)
{
	is >> p.y >> p.x;
	return is;
}

// for debug
ostream& operator <<(ostream& os, Point& p)
{
	os << p.x << ' ' << p.y;
	return os;
}

bool operator !=(const Point& a, const Point& b)
{
	if (a.x != b.x || a.y != b.y)
		return true;
	return false;
}

void printMap(const vector<vector<char>> map)
{
	for (vector<char> v : map)
	{
		for (char c : v)
			cout << c;
		cout << '\n';
	}
	cout << '\n';
}

bool isIndexOutOfRange(const Point size, const Point p)
{
	if (p.x < 0 || p.x >= size.x)
		return true;
	if (p.y < 0 || p.y >= size.y)
		return true;
	return false;
}

bool isPictureFit(const Point size, const Point start, const Point end)
{
	if (isIndexOutOfRange(size, start))
		return false;
	if (isIndexOutOfRange(size, end))
		return false;
	return true;
}

void drawSquare(vector<vector<char>>& map, Point start, Point end)
{
	for (int x = start.x; x <= end.x; x++)
	{
		for (int y = start.y; y <= end.y; y++)
		{
			map[x][y] = 'X';
		}
	}
}

void drawLine(vector<vector<char>>& map, Point start, Point end)
{
	bool xIsIncreace = start.x < end.x, yIsIncreace = start.y < end.y;
	while (start != end)
	{
		map[start.x][start.y] = 'X';
		if (start.x != end.x)
		{
			if (xIsIncreace)
				start.x++;
			else
				start.x--;
		}

		if (start.y != end.y)
		{
			if (yIsIncreace)
				start.y++;
			else
				start.y--;
		}
	}
	map[start.x][start.y] = 'X';
}

void drawTriangle(vector<vector<char>>& map, const Point row, const Point col)
{
	// handle which side will temp close to col
	bool isLeft = col.x > row.x, isUp = col.y > row.y;

	Point temp = row;
	int level(0);	// how many line have printed
	while (temp.y != col.y)
	{
		temp.x = row.x + (isLeft ? level : -level);
		while (temp.x != col.x)
		{
			map[temp.x][temp.y] = 'X';
			temp.x += (isLeft ? 1 : -1);
		}
		map[temp.x][temp.y] = 'X';	// need to draw one more char (temp.x = col.x)
		temp.y += (isUp ? 1 : -1);
		level++;	// count level
	}

	// need to do draw one more line (temp.y = col.y)
	temp.x = row.x + (isLeft ? level : -level);
	while (temp.x != col.x)
	{
		map[temp.x][temp.y] = 'X';
		temp.x += (isLeft ? 1 : -1);
	}
	map[temp.x][temp.y] = 'X';
}

int main()
{
	Point size;
	cin >> size;
	vector<vector<char>> map(size.x, vector<char>(size.y, '*'));	// init map

	for (char op; cin >> op;)
	{
		if (op == 'S')
		{
			int width;
			Point start;
			cin >> width >> start;
			width--;	// end = start + width - 1 -> width-- first
			Point end(start.x + width, start.y + width);
			if (!isPictureFit(size, start, end))
			{
				cout << "Out of range.\n\n";
				continue;
			}
			drawSquare(map, start, end);
		}
		else if (op == 'L')
		{
			Point start, end;
			cin >> start >> end;
			if (!isPictureFit(size, start, end))
			{
				cout << "Out of range.\n\n";
				continue;
			}

			drawLine(map, start, end);
		}
		else if (op == 'T')
		{
			string direction;
			int hypotenuse;
			Point corner;
			cin >> hypotenuse >> corner >> direction;
			hypotenuse--;	// end = start + width - 1 -> width-- first
			Point row = corner, col = corner;

			if (direction == "LU")
			{
				row.x -= hypotenuse;
				col.y -= hypotenuse;
			}
			else if (direction == "RU")
			{
				row.x -= hypotenuse;
				col.y += hypotenuse;
			}
			else if (direction == "LD")
			{
				row.x += hypotenuse;
				col.y -= hypotenuse;
			}
			else if (direction == "RD")
			{
				row.x += hypotenuse;
				col.y += hypotenuse;
			}

			if (!isPictureFit(size, corner, row) || !isPictureFit(size, corner, col))
			{
				cout << "Out of range.\n\n";
				continue;
			}
			drawTriangle(map, row, col);
		}
		else if (op == 'C')	// clear map for debug
		{
			for (auto& v : map)
			{
				for (auto& c : v)
					c = '*';
			}
		}
		else
		{
			break;
		}
		printMap(map);
	}
	return 0;
}