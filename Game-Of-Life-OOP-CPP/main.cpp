/* 
 *			HW05
 * 
 * File:	main.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 *
 */

#include <iostream>
#include "Cell.h"
#include "GameOfLife.h"

using namespace std;

const string getFileName();

int main()
{
	Cell c1(10,2);
	Cell c2(2,0);
	Cell c3(10,5);
			
	GameOfLife game1(getFileName());
	GameOfLife game2(getFileName());
	GameOfLife game3;
	game3 = game2;
	
	cout << "CELL OPERATIONS" << endl << endl;
	
	cout << "COMPARISON" << endl;
	cout << "cell1: (" << c1.getX() << ", " << c1.getY() << ")" << endl;
	cout << "cell2: (" << c2.getX() << ", " << c2.getY() << ")" << endl;
	cout << "Please enter two number for x and y of cell3: ";
	cin >> c3;
	cout << "cell3: (" << c3.getX() << ", " << c3.getY() << ")" << endl;
	
	if (c1 < c3) 
		cout << "cell1 < cell3" << endl;
	else
		cout << "cell1 >= cell3" << endl;
	if (c2 <= c3) 
		cout << "cell2 <= cell3" << endl;
	else
		cout << "cell2 > cell3" << endl;
	if (c1 == c3) 
		cout << "cell1 == cell3" << endl;
	else
		cout << "cell1 != cell3" << endl;
	if (c2 == c3) 
		cout << "cell2 == cell3" << endl;
	else
		cout << "cell2 != cell3" << endl << endl;
	
	cout << "PREFIX AND POSTFIX INCREMENT" <<endl;
	c1 = ++c2;
	cout << "cell1 = ++cell2" << endl;
	cout << "cell1: " << c1 << endl;
	cout << "cell2: " << c2 << endl;
	c1 = c2++;
	cout << "cell1 = cell2++" << endl;
	cout << "cell1: " << c1 << endl;
	cout << "cell2: " << c2 << endl << endl;
	
	cout << "GAME OF LIFE OPERATIONS" << endl << endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game2" << endl << game2 << endl;
	
	cout << "PREFIX AND POSTFIX INCREMENT" <<endl;
	game2 = ++game1;
	cout << "Game2 = ++Game1" << endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game2" << endl << game2 << endl;
	game2 = game1++;
	cout << "Game2 = Game1++" << endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game2" << endl << game2 << endl;
	
	cout << "PREFIX AND POSTFIX DECREMENT" <<endl;
	game2 = --game1;
	cout << "Game2 = --Game1" << endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game2" << endl << game2 << endl;
	game2 = game1--;
	cout << "Game2 = Game1--" << endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game2" << endl << game2 << endl;

	cout << "GAME AND CELL ADDITION" <<endl;
	cout << "cell3: (" << c3.getX() << ", " << c3.getY() << ")" << endl;
	game2 = game1 + c3;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game2 = Game1 + cell3" << endl << game2 << endl;
	
	cout << "GAME AND CELL SUBSTRACTION" <<endl;
	cout << "cell3: (" << c3.getX() << ", " << c3.getY() << ")" << endl;
	cout << "Game2" << endl << game2 << endl;
	game2 = game2 - c3;
	cout << "Game2 = Game2 - cell3" << endl << game2 << endl;
	
	cout << "GAME AND GAME ADDITION" <<endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game3" << endl << game3 << endl;
	game2 = game1 + game3;
	cout << "Game2 = Game1 + Game3" << endl << game2 << endl;
	
	cout << "GAME AND GAME SUBSTRACTION" <<endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game3" << endl << game3 << endl;
	game2 = game1 - game3;
	cout << "Game2 = Game1 - Game3" << endl << game2 << endl;
	
	cout << "INDEX OF" <<endl;
	c3 = game1[3][0];
	cout << "Game1" << endl << game1 << endl;
	cout << "Game1[3][0]" << endl;
	cout << "cell3: (" << c3.getX() << ", " << c3.getY() << ")" << endl << endl;
	
	cout << "FUNCTION" <<endl;
	c3 = game1(6,0);
	cout << "Game1" << endl << game1 << endl;
	cout << "Game1(6,0)" << endl;
	cout << "cell3: (" << c3.getX() << ", " << c3.getY() << ")" << endl << endl;
	
	cout << "ASSIGNMENT INCREMENT" <<endl;
	cout << "Game1" << endl << game1 << endl;
	cout << "Game3" << endl << game3 << endl;
	game3 += game1;
	cout << "Game3 += Game1" << endl;
	cout << "Game3" << endl << game3 << endl;
	
	return 0;
}

const string getFileName()
{
	string name;
	ifstream sourceFile;
	
	cout << "Please enter the name ";
	cout << "of the .txt file you want to load (without extension): ";
	cout << endl;
	getline(cin, name);
	sourceFile.open((name + ".txt").c_str());
	
	while (sourceFile == NULL)
	{
		cout << name << " doesn't exist." << endl << endl;
		cout << "Please enter the name ";
		cout << "of the .txt file you want to load (without extension): ";
		cout << endl;
		getline(cin, name);
		sourceFile.open((name + ".txt").c_str());
	}
	
	sourceFile.close();
	return name;
}
