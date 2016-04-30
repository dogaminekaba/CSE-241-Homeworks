/* 
 *			HW05
 * 
 * File:	GameOfLife.h
 * Author:	Doğa Mine Kaba
 *			121044004
 *
 */

#ifndef GAMEOFLIFE_H
#define	GAMEOFLIFE_H

#include "Cell.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class GameOfLife 
{
public:
	GameOfLife();
	GameOfLife(const string);
	const int getWidth() const;
	const int getHeight() const;
	//gets turn count (N) from user
	const int getN() const;
	//calculates the next states of the cells
	void play();
	//prints the board on the screen
	void displayGame() const;
	//adds living cells of second game to first game
	void join(const GameOfLife& otherGame);
	//OPERATOR OVERLOADINGS
	//advance the game by one step
	const GameOfLife operator ++ ();
	const GameOfLife operator ++ (int unused);
	//undo the game by one step
	const GameOfLife operator -- ();
	const GameOfLife operator -- (int unused);
	
	friend const GameOfLife operator + (const GameOfLife& game, 
										const Cell& cell);
	friend const GameOfLife operator - (const GameOfLife& game, 
										const Cell& cell);
	friend const GameOfLife operator + (const GameOfLife& game1, 
										const GameOfLife& game2);
	friend const GameOfLife operator - (const GameOfLife& game1, 
										const GameOfLife& game2);
	friend ostream& operator << (ostream& output, const GameOfLife& game);
	const vector<Cell> operator [] (const int index) const;
	const Cell operator ()(const int x, const int y) const;
	const GameOfLife operator += (const GameOfLife& other);
private:
	vector<Cell> livingCells;
	vector< vector<Cell> > history;
	int startPointX;
	int startPointY;
	int width;
	int height;
	//gets width, height and living cells from file
	const int readFile(const string fileName);
	//checks if the cell with given coordinates is alive
	const bool isAlive(const int x, const int y) const;
	//returns number of alive neighbours of the cell with given coordinates
	const int aliveNeighbours(const int x, const int y) const;
	//writes the board in the file with given name
	void writeToFile() const;
	//removes the dead cell from livingCells vector
	void removeFromAlives(const int x, const int y);
	//updates the height, width and start points of the board
	void updateBoardSize();
};

#endif	/* GAMEOFLIFE_H */

