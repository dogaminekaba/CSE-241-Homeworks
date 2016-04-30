		/********************************************************/
		/*				Doga Mine Kaba	121044004				*/
		/*					  	  HW01		 					*/
		/*														*/
		/*	This program simulates the Game Of Life.			*/
		/*														*/
		/*	It takes an input file name and takes N moves from	*/
		/*	user. Calculates the next state of the board and	*/
		/*	when user press Enter, prints it on the console.	*/
		/*														*/
		/*	After N times calculation it writes the final 		*/
		/*	state of the board to the file which named by user.	*/
		/*														*/
		/********************************************************/
		
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string getFileName();
/* Asks user the name of file to load */

int findColumnRowSize(string fileName, int *columnSize, int *rowSize);
/* Finds size of array according to source file */

int initializeBoard(string fileName, int **arr, int columnSize, int rowSize);
/* Fills the board with initial values */

int printBoard(int **arr, int columnSize, int rowSize);
/* Prints the board to the screen */

int updateBoard(int **arr, int columnSize, int rowSize);
/* Calculates if current cell is dead or alive and updates the board */

int neighbourCount(int **arr, int columnSize, int rowSize, int indexX, int indexY);
/* Finds the number of alive neighbours */

int getN();
/* Gets the N (move number) */

int writeToFile(int **arr, int columnSize, int rowSize, string outFileName);
/* Writes the last state of the board to the given-named file */

int main()
{
	int ** board;
	int row, column;
	string fileName;
	int controlFormat;
	int moveNum;
	string enter, answer, outFileName;
	int exitState = 0;
	
	cout << endl << "Welcome to The Game of Life!" << endl << endl;
	
	while (exitState != 1)
	{
		fileName = getFileName();
		findColumnRowSize(fileName, &column, &row);
	
		/* Create dynamic array */
	
		board = (int**) malloc(column * sizeof(int*));
	
		for (int i = 0; i < column; i += 1)
			board[i] = (int*) malloc(row * sizeof(int));
	
		controlFormat = initializeBoard(fileName, board, column, row);
	
		/* Print board */
	
		moveNum = getN();
		
		if (controlFormat == 0)
			printBoard(board, column, row);	
		
		/* Update board */
		
		while (moveNum != 0)
		{
			cout << "Press Enter to see next states of cells: ";
			getline(cin, enter);
			if (enter == "")
			{
				updateBoard(board, column, row);
				printBoard(board, column, row);	
				--moveNum;
			}
		}
		
		/* Write to file */
		
		cout << "Please enter a name for output file (without extension): ";
		cin >> outFileName;
		writeToFile(board, column, row, outFileName);
		
		/* Ask to play again */
		
		do
		{
			cout << "Do you want to load another file (Y/N) ? ";
			getline(cin, answer);
			
			if (answer == "N" || answer == "n")
				exitState = 1;
			
		} while (answer != "Y" && answer != "y" &&
				answer != "N" && answer != "n");
				
		free(board);
	}
	
	cout << endl << "Goodbye!" << endl << endl;
	
	return 0;
}

string getFileName()
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

int findColumnRowSize(string fileName, int *columnSize, int *rowSize)
{
	ifstream sourceFile;
	string line;
	bool notEndFile;
	int column = 0, tempColumn = 0;
	
	*columnSize = 0;
	*rowSize = 0;
	
	sourceFile.open((fileName + ".txt").c_str());
	
	/* Get size of row and column */
	notEndFile = getline (sourceFile, line);
	column = line.length();
	while (notEndFile)
	{
		notEndFile = getline (sourceFile, line);
		tempColumn = line.length();
		
		if (notEndFile && tempColumn != column)
		{
			cout << "Column size must be equal in each row." << endl;
			*columnSize = 0;
			*rowSize = 0;
			return -1;
		}
		++*rowSize;
	}
	*columnSize = column;
	
	sourceFile.close();
	
	return 0;
}

int initializeBoard(string fileName, int **arr, int columnSize, int rowSize)
{
	ifstream sourceFile;
	string line;
	
	/* Fill the array */
	
	sourceFile.open ((fileName + ".txt").c_str());
	
	for (int i = 0; i < rowSize; i += 1)
	{
		getline (sourceFile, line);
		for (int j = 0; j < columnSize; j += 1)
		{
			if (line[j] == 'X' || line[j] == 'x') 
				arr[i][j] = 1;
			else if (line[j] == ' ')
				arr[i][j] = 0;
			else
			{
				cout << "Input text file should only contain x and space.";
				cout << endl;
				return -1;
			}
		}
	}
		
	sourceFile.close();
	
	return 0;
}

int printBoard(int **arr, int columnSize, int rowSize)
{
	cout << endl;
	for (int i = 0; i < rowSize; i += 1)
	{
		for (int j = 0; j < columnSize; j += 1)
		{
			if (arr[i][j] == 1) 
				cout << 'x';
			else if (arr[i][j] == 0)
				cout << ' ';
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}

int updateBoard(int **arr, int columnSize, int rowSize)
{
	int newArr[rowSize][columnSize];
	int counter = 0;
	
	/* Fill temporary array */
	
	for (int i = 0; i < rowSize; i += 1)
	{
		for (int j = 0; j < columnSize; j += 1)
		{
			counter = neighbourCount(arr, columnSize, rowSize, i, j);
			if ((arr[i][j] == 1) && (counter == 2 || counter == 3))
				newArr[i][j] = 1;
			else if (arr[i][j] == 0 && counter == 3)
				newArr[i][j] = 1;
			else
				newArr[i][j] = 0;
		}
	}
	
	/* Update old array */
	
	for (int i = 0; i < rowSize; i += 1)
	{
		for (int j = 0; j < columnSize; j += 1)
			arr[i][j] = newArr[i][j];
	}
	return 0;
}

int neighbourCount(int **arr, int columnSize, int rowSize, int indexX, int indexY)
{
	int neighbourX = indexX-1 , neighbourY = indexY-1;
	int neighbourCount = 0;
	
	for (int i = 0; i < 3; i += 1)
	{
		for (int j = 0; j < 3; j += 1)
		{
			if ((neighbourX >= 0) && (neighbourY >= 0) && 
				!(indexX == neighbourX && indexY == neighbourY))
			{
				if (arr[neighbourX][neighbourY] == 1)
					++ neighbourCount;
			}
			++neighbourY;
		}
		neighbourY = indexY-1;
		++neighbourX;
	}
	return neighbourCount;
}

int getN()
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
				cout << "You should enter an integer. " << endl;
				moveCount = -1;
				break;
			}
		}
	} while ( moveCount == -1 );
	
	return moveCount;
}

int writeToFile(int **arr, int columnSize, int rowSize, string outFileName)
{
	ofstream outFile;
	outFile.open ((outFileName + ".txt").c_str());
	
	for (int i = 0; i < rowSize; i += 1)
	{
		for (int j = 0; j < columnSize; j += 1)
		{
			if (arr[i][j] == 1)
				outFile << "x";
			else
				outFile << " ";
		}
		outFile << endl;
	}
	outFile.close();
}


