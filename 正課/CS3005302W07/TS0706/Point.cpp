#include "Point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Point::inRange(int size) const
{
	if (x < 0 || x >= size)
		return false;
	if (y < 0 || y >= size)
		return false;
	return true;
}

Point Point::operator=(const Point& point)
{
	return Point(point.x, point.y);
}

std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point.x >> point.y;
	point.x++;
	point.y++;
	return is;
}

bool operator==(const Point& p1, const Point& p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	return false;
}

Point operator+(const Point& p1, const Point& p2)
{
	return Point(p1.x + p2.x, p1.y + p2.y);
}
