/* 
 *			HW05
 * 
 * File:	Cell.h
 * Author:	Doğa Mine Kaba
 *			121044004
 *
 */

#ifndef CELL_H
#define	CELL_H
#include <iostream>

using namespace std;

class Cell
{
public:
	//Constructor
	Cell(int newX, int newY);
	//Setters
	void setX(int newX);
	void setY(int newY);
	//Getters
	const int getX() const;
	const int getY() const;
	//Operator overloadings
	const bool operator < (const Cell& otherCell) const;
	const bool operator > (const Cell& otherCell) const;
	const bool operator == (const Cell& otherCell) const;
	const bool operator != (const Cell& otherCell) const;
	const bool operator <= (const Cell& otherCell) const;
	const bool operator >= (const Cell& otherCell) const;
	const Cell operator ++ ();
	const Cell operator ++ (int unused);
	const Cell operator -- ();
	const Cell operator -- (int unused);
	friend ostream& operator <<	(ostream& output, const Cell& c);
	friend istream& operator >>	(istream& input, Cell& c);
private:
	int x;
	int y;
	void checkValues(int x, int y);
};

#endif	/* CELL_H */