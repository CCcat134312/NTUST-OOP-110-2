#pragma once
#include <iostream>

class Point
{
public:
	int x;
	int y;

	Point(int = 0, int = 0);
	bool inRange(int) const;

	Point operator=(const Point&);

	friend std::istream& operator>>(std::istream&, Point&);
	friend bool operator==(const Point&, const Point&);
	friend Point operator+(const Point&, const Point&);
};

