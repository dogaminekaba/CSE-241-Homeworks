/* 
 *			HW05
 * 
 * File:	GameOfLife.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 * 
 */

#include "GameOfLife.h"

GameOfLife::GameOfLife() 
{	
	startPointX = 0;
	startPointY = 0;
	width = 0;
	height = 0;
}
GameOfLife::GameOfLife(const string fileName)
{	
	startPointX = 0;
	startPointY = 0;
	width = 0;
	height = 0;
	
	readFile(fileName);
}
const int GameOfLife::getWidth() const
{
	return width;
}
const int GameOfLife::getHeight() const
{
	return height;
}
const int GameOfLife::readFile(const string fileName)
{
	ifstream sourceFile;
	string line;
	bool notEndFile;
	int i=0, j=0;
	
	sourceFile.open((fileName + ".txt").c_str());
	
	/* Get size of start points, width and height */
	notEndFile = getline (sourceFile, line);
	
	j=0;	//temporary height
	while (notEndFile)
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == 'X' || line[i] == 'x')
			{
				//Update living cells vector
				livingCells.push_back(Cell(i,j));
				
				//Update board size
				if (i > width)
					width = i;
				height = j;
			}
		}
		++j;
		notEndFile = getline (sourceFile, line);
	}
	sourceFile.close();
}
void GameOfLife::displayGame() const
{
	bool contains = false;
	
	for (int i = startPointY; i <= height; i++)
	{
		for (int j = startPointX; j <= width; j++)
		{
			if (isAlive(j, i))
			{
				contains = false;
				cout << "x";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}
const int GameOfLife::getN() const
{
	string line;
	int moveCount = -1;
	
	do
	{
		cout << "Please enter the move count you want to see: ";
		getline(cin, line);
		moveCount = 0;
		for (int i = 0; i < line.length(); i += 1)
		{
			if(line[i] <= '9' && line[i] >= '0')
				moveCount = moveCount*10 + (line[i] - '0');
			else
			{
				cout << "You should enter a positive integer. " << endl;
				moveCount = -1;
				break;
			}
		}
	} while ( moveCount == -1 );
	
	return moveCount;
}
const bool GameOfLife::isAlive(const int x, const int y) const
{
	bool result = false;
	
	for (int i = 0; i < livingCells.size(); i++)
	{
		if (livingCells.at(i).getX() == x && 
			livingCells.at(i).getY() == y)
			result = true;
	}
	return result;
}
void GameOfLife::removeFromAlives(const int x, const int y)
{
	for (int i = 0; i < livingCells.size(); i++)
	{
		if (livingCells.at(i).getX() == x && 
			livingCells.at(i).getY() == y)
			livingCells.erase(livingCells.begin()+i);
	}
}
const int GameOfLife::aliveNeighbours(const int x, const int y) const
{
	int neighbourX = x-1 , neighbourY = y-1;
	int neighbourCount = 0;
	
	for (int i = 0; i < 3; i += 1)
	{
		for (int j = 0; j < 3; j += 1)
		{
			if (!(x == neighbourX && y == neighbourY) &&
				isAlive(neighbourX,neighbourY))
					++ neighbourCount;
			++neighbourY;
		}
		neighbourY = y-1;
		++neighbourX;
	}
	return neighbourCount;
}
void GameOfLife::play()
{
	//Temporary vectors to hold next states without changing current states
	vector<Cell> tempLivingCells;
	vector<Cell> tempDiedCells;
	
	int neighbourCount = 0;
	int tempX = 0, tempY = 0;
	
	history.push_back(livingCells);
	
	for (int i = startPointY; i <= height; i++)
	{
		for (int j = startPointX; j <= width; j++)
		{
			neighbourCount = aliveNeighbours(j, i);
			if (isAlive(j, i))
			{
				if (neighbourCount < 2 || neighbourCount > 3)
					tempDiedCells.push_back(Cell(j, i));
			}
			else
			{
				if (neighbourCount == 3)
					tempLivingCells.push_back(Cell(j, i));
			}
		}
	}
	//Update cells which died
	for (int i = 0; i < tempDiedCells.size(); i++) 
	{
		tempX = tempDiedCells.at(i).getX();
		tempY = tempDiedCells.at(i).getY();
		removeFromAlives(tempX, tempY);
	}
	//Update cells which are born
	for (int i = 0; i < tempLivingCells.size(); i++) 
	{
		tempX = tempLivingCells.at(i).getX();
		tempY = tempLivingCells.at(i).getY();
		livingCells.push_back(Cell(tempX, tempY));
	}
	updateBoardSize();
}
void GameOfLife::updateBoardSize()
{
	int	tempX, tempY;
	
	if (!livingCells.empty()) 
	{
		tempX = livingCells.at(0).getX();
		tempY = livingCells.at(0).getY();

		startPointX = tempX;
		startPointY = tempY;
		width = tempX;
		height = tempY;

		for (int i = 1; i < livingCells.size(); i++)
		{
			tempX = livingCells.at(i).getX();
			tempY = livingCells.at(i).getY();

			if (tempX < startPointX)
				startPointX = tempX;
			if (tempY < startPointY)
				startPointY = tempY;
			if (tempX > width)
				width = tempX;
			if (tempY > height)
				height = tempY;
		}
	}
}
void GameOfLife::join(const GameOfLife& otherGame)
{
	history.push_back(livingCells);
	int tempX, tempY;
	for (int i = 0; i < otherGame.livingCells.size(); i++)
	{
		tempX = otherGame.livingCells.at(i).getX();
		tempY = otherGame.livingCells.at(i).getY();
		
		if (!isAlive(tempX, tempY))
			livingCells.push_back(otherGame.livingCells.at(i));
	}
	updateBoardSize();
}
//OPERATOR OVERLOADINGS
const GameOfLife GameOfLife::operator ++ ()
{
	play();
	return *this;
}
const GameOfLife GameOfLife::operator ++ (int unused)
{
	GameOfLife temp;
	temp = *this;
	play();
	return temp;
}
const GameOfLife GameOfLife::operator -- ()
{
	if (history.size()) 
	{
		livingCells = history.at(history.size()-1);
		updateBoardSize();
		history.pop_back();
	}
	return *this;
}
const GameOfLife GameOfLife::operator -- (int unused)
{
	GameOfLife temp;
	temp = *this;
	if (history.size()) 
	{
		livingCells = history.at(history.size()-1);
		updateBoardSize();
		history.pop_back();
	}
	return temp;
}
const GameOfLife operator + (const GameOfLife& game, const Cell& cell)
{
	GameOfLife temp;
	temp = game;
	
	if (!game.isAlive(cell.getX(), cell.getY())) 
	{
		temp.livingCells.push_back(cell);
		temp.updateBoardSize();
		temp.history.push_back(temp.livingCells);
	}
	else
		return temp;
}
const GameOfLife operator - (const GameOfLife& game, const Cell& cell)
{
	GameOfLife temp;
	temp = game;
	
	if (game.isAlive(cell.getX(), cell.getY())) 
	{
		temp.removeFromAlives(cell.getX(), cell.getY());
		temp.updateBoardSize();
		temp.history.push_back(temp.livingCells);
	}
	else
		return temp;
}
const GameOfLife operator + (const GameOfLife& game1, 
							const GameOfLife& game2)
{
	GameOfLife temp;
	temp.join(game1);
	temp.join(game2);
	temp.updateBoardSize();
	temp.history.clear();
	
	return temp;
}
const GameOfLife operator - (const GameOfLife& game1, 
							const GameOfLife& game2)
{
	GameOfLife temp;
	int x=0, y=0;
	int tempIndex = 0;
	
	temp = game1;
	
	for (int i = 0; i < game2.livingCells.size(); i++)
	{
		x = game2.livingCells.at(i).getX();
		y = game2.livingCells.at(i).getY();
		if (temp.isAlive(x, y))
		{
			temp.livingCells.erase(temp.livingCells.begin() + tempIndex);
			--tempIndex;
		}
		++tempIndex;
	}
	temp.updateBoardSize();
	temp.history.clear();
	return temp;
}
ostream& operator << (ostream& output, const GameOfLife& game)
{
	bool contains = false;
	
	for (int i = game.startPointY; i <= game.height; i++)
	{
		for (int j = game.startPointX; j <= game.width; j++)
		{
			if (game.isAlive(j, i))
			{
				contains = false;
				output << "x";
			}
			else
				output << " ";
		}
		output << endl;
	}
	return output;
}
const vector<Cell> GameOfLife::operator [] (const int index) const
{
	vector<Cell> vec;
	
	for (int i = startPointX; i < width; i++)
	{
		if (isAlive(index,i))
			vec.push_back(Cell(index,i));
		else
			vec.push_back(Cell(-1000,-1000));
	}
	return vec;
}
const Cell GameOfLife::operator ()(const int x, const int y) const
{
	if (isAlive(x, y))
		return Cell(x, y);
	else
		return Cell(-1000,-1000);
}
const GameOfLife GameOfLife::operator += (const GameOfLife& other)
{
	join(other);
	updateBoardSize();
	history.push_back(livingCells);
	return *this;
}