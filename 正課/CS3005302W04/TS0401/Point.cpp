#include "Point.h"

void Point::Set(int _vertical, int _horizontal)
{
	vertical = _vertical;
	horizontal = _horizontal;
}

void Point::Move(int x, int y)
{
	vertical += x;
	horizontal += y;
}
void Point::Rotate()
{
	swap(vertical, horizontal);
	horizontal *= -1;
}
