/* 
 *			HW05
 * 
 * File:	Cell.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 * 
 */

#include "Cell.h"
		
Cell::Cell(int newX = 0, int newY = 0):x(newX),y(newY)
{/*Intentionally left blank*/}
void Cell::setX(int newX)
{
	x = newX;
}
void Cell::setY(int newY)
{
	y = newY;
}
const int Cell::getX() const
{
	return x;
}
const int Cell::getY() const
{
	return y;
}
const bool Cell::operator <(const Cell& otherCell) const
{
	if (y < otherCell.y) 
		return true;
	else if(y == otherCell.y)
	{
		if(x < otherCell.x)
			return true;
		else
			return false;
	}
	else
		return false;
}
const bool Cell::operator >(const Cell& otherCell) const
{
	if (y > otherCell.y) 
		return true;
	else if(y == otherCell.y)
	{
		if(x > otherCell.x)
			return true;
		else
			return false;
	}
	else
		return false;
}
const bool Cell::operator ==(const Cell& otherCell) const
{
	if (y == otherCell.y && x == otherCell.x) 
		return true;
	else
		return false;
}
const bool Cell::operator !=(const Cell& otherCell) const
{
	if (!(y == otherCell.y && x == otherCell.x))
		return true;
	else
		return false;
}
const bool Cell::operator >=(const Cell& otherCell) const
{
	if (*this > otherCell || *this == otherCell)
		return true;
	else
		return false;
}
const bool Cell::operator <=(const Cell& otherCell) const
{
	if (*this < otherCell || *this == otherCell)
		return true;
	else
		return false;
}
const Cell Cell::operator ++()
{
	++x;
	++y;
	return *this;
}
const Cell Cell::operator ++(int unused)
{
	Cell oldCell(x,y);
	++x;
	++y;
	return oldCell;
}
const Cell Cell::operator --()
{
	--x;
	--y;
	return *this;
}
const Cell Cell::operator --(int unused)
{
	Cell oldCell(x,y);
	--x;
	--y;
	return oldCell;
}
ostream& operator << (ostream& output, const Cell& c)
{
	output << "x: " << c.x << " y: " << c.y;
	return output;
}
istream& operator >> (istream& input, Cell& c)
{
	input >> c.x >> c.y;
	return input;
}