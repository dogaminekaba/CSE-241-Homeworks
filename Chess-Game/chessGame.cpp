		/************************************************************/
		/*				Doga Mine Kaba	121044004					*/
		/*					  	  HW02		 						*/
		/*															*/
		/*						 CHESS								*/
		/*	This program takes coordinates from user, checks them	*/
		/*	if they are legal moves for chess rules. If they are,	*/
		/*	program plays user's move. Then generates it's own		*/
		/*	random move.											*/
		/*	Game goes like this until one of the kings is gone.		*/
		/*	It prepares a new game if user wants.					*/
		/*															*/
		/************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*Function Prototypes*/
void initializeNewBoard	(int chessBoard[][8]);
void printBoard	(int chessBoard[][8]);
bool isFormatTrue	(string userMove);
void getUserMove	(string *userMove, int chessBoard[][8], int *elementNum,
 					int *columnFrom, int *rowFrom, int *columnTo, int *rowTo);
bool isTrueMove	(int chessBoard[][8], int rowFrom, int columnFrom, 
				int rowTo, int columnTo, int elementNum);
bool isTrueMovePawn	(int elementNum, int chessBoard[][8], int columnFrom, 
					int rowFrom, int columnTo, int rowTo);
bool isTrueMoveBishop	(int elementNum, int chessBoard[][8], int columnFrom, 
						int rowFrom, int columnTo, int rowTo);
bool isTrueMoveRook	(int elementNum, int chessBoard[][8], int columnFrom, 
					int rowFrom, int columnTo, int rowTo);
bool isTrueMoveKnight	(int columnFrom, int rowFrom, int columnTo, int rowTo);
bool isTrueMovePawn	(int columnFrom, int rowFrom, int columnTo, int rowTo);
bool isTrueMoveKing	(int columnFrom, int rowFrom, int columnTo, int rowTo);
bool isThereYourElement	(int elementNum, int chessBoard[][8],
						int rowTo, int columnTo);
void generateMove	(int *elementNum, int *columnFrom, int *rowFrom, 
					int *columnTo, int *rowTo, int chessBoard[][8]);
bool isGameOver(int chessBoard[][8]);
bool didUserWin(int chessBoard[][8]);

int main ()
{
	int chessBoard[8][8], counter=1,
		elementNum, columnFrom, rowFrom, columnTo, rowTo,
		elementNumComp, columnFromComp, rowFromComp, columnToComp, rowToComp;

	string userMove; 
	char userAnswer;
	bool isTrue, answer=false;
	
	do
	{
		initializeNewBoard(chessBoard);
		printBoard(chessBoard);
		
		while (!isGameOver(chessBoard))
		{
			cout << "Move " << counter << endl;
			do
			{
				getUserMove(&userMove, chessBoard, &elementNum,
	 						&columnFrom, &rowFrom, &columnTo, &rowTo);
	 			isTrue = isTrueMove(chessBoard, rowFrom, columnFrom,
	 								rowTo, columnTo, elementNum);
	 			if ((columnFrom == columnTo) && (rowFrom == rowTo))
					cout << endl << "You didn't literally make a move." << endl;
				else if(!isTrue)
					cout << endl << "You can't make that move." << endl;
			
			} while (!isTrue);
			++counter;
			
			chessBoard[rowTo][columnTo] = elementNum;
			chessBoard[rowFrom][columnFrom] = 0;
			printBoard(chessBoard);
			
			generateMove(&elementNumComp, &columnFromComp, &rowFromComp, 
						&columnToComp, &rowToComp, chessBoard);
						
			cout << "Move " << counter << endl;
			cout << "Computer's move: ";
			cout << char (columnFromComp + 65) << rowFromComp + 1 << '-';
			cout << char (columnToComp + 65) << rowToComp + 1 << endl << endl;
			
			chessBoard[rowToComp][columnToComp] = elementNumComp;
			chessBoard[rowFromComp][columnFromComp] = 0;
			printBoard(chessBoard);
			++counter;
		}
		if (didUserWin(chessBoard))
			cout << endl << "Congratulations you won :)" << endl;
		else
			cout << endl << "You lose :(" << endl;	
		
		counter = 0;
		
		do
		{
			cout << endl <<"Would you like to play another game? (Y/N)"<< endl;
			cin >> userAnswer;
			if ((userAnswer=='n') || (userAnswer=='N') ||
				(userAnswer=='y') || (userAnswer=='Y'))
			{
				answer = true;
			}
		} while (!answer);
	} while ((userAnswer != 'N') && (userAnswer != 'n'));
	
	return 0;
}

/******************************FUNCTIONS***************************************/

void initializeNewBoard(int chessBoard[][8])
{
	int i, j;
	
	/*Sets the chess pieces of black*/
	for(i=0; i<8; ++i)
		chessBoard[1][i]=11;	//pawns
	chessBoard[0][0]=44;		//rooks
	chessBoard[0][7]=44;
	chessBoard[0][1]=33;		//knights
	chessBoard[0][6]=33;
	chessBoard[0][2]=22;		//bishops
	chessBoard[0][5]=22;
	chessBoard[0][3]=55;		//queen
	chessBoard[0][4]=66;		//king
	
	for (i = 2; i < 6; i += 1)
	{
		for (j = 0; j < 8; j += 1)
		{
			chessBoard[i][j]=0;
		}
	}
	
	/*Sets the chess pieces of white*/
	for(i=0; i<8; ++i)
		chessBoard[6][i]=1;		//pawns
	chessBoard[7][0]=4;			//rooks
	chessBoard[7][7]=4;
	chessBoard[7][1]=3;			//knights
	chessBoard[7][6]=3;
	chessBoard[7][2]=2;			//bishops
	chessBoard[7][5]=2;
	chessBoard[7][3]=5;			//queen
	chessBoard[7][4]=6;			//king
}
/******************************************************************************/
void printBoard(int chessBoard[][8])
{
	int element;
	
	cout << "    A B C D E F G H " << endl;
	cout << "  *-----------------*" << endl;
	
	for (int i = 0; i < 8; i += 1)
	{
		cout << i+1 << " | ";
		for (int j = 0; j < 8; j += 1)
		{
			element = chessBoard[i][j];
			switch(element)
			{
				case 1:	cout << "P ";
					break;
				case 2: cout << "F ";
					break;
				case 3: cout << "A ";
					break;
				case 4: cout << "K ";
					break;
				case 5: cout << "V ";
					break;
				case 6: cout << "Ş ";
					break;
				case 11: cout << "p ";
					break;
				case 22: cout << "f ";
					break;
				case 33: cout << "a ";
					break;
				case 44: cout << "k ";
					break;
				case 55: cout << "v ";
					break;
				case 66: cout << "ş ";
					break;
				default: cout << ". ";
			}
		}
		cout << "|" << endl;
	}
	cout << "  *-----------------*" << endl << endl;
}
/******************************************************************************/
void getUserMove(string *userMove, int chessBoard[][8], int *elementNum,
 				int *columnFrom, int *rowFrom, int *columnTo, int *rowTo)
{	
	int rowFromTemp, columnFromTemp, rowToTemp, columnToTemp, elementNumTemp;
	string tempMove;
	
	cout << "Enter your move: ";
	cin >> *userMove;
	while(!isFormatTrue(*userMove))
	{
		cout << endl;
		cout << "I couldn't understand your move." << endl;
		cout << "Please enter your move like A1-A2." << endl;
		cout << "Enter your move: ";
		cin >> *userMove;
	}
	tempMove = *userMove;
	do
	{
		rowFromTemp = tempMove[1] - 49;
		rowToTemp = tempMove[4] - 49;
		if (tempMove[0]>='A' && tempMove[0]<='H')
			columnFromTemp = tempMove[0] - 65;
		else if (tempMove[0]>='a' && tempMove[0]<='h')
			columnFromTemp = tempMove[0] - 97;
		if (tempMove[3]>='A' && tempMove[3]<='H')
			columnToTemp = tempMove[3] - 65;
		else if (tempMove[3]>='a' && tempMove[3]<='h')
			columnToTemp = tempMove[3] - 97;
		elementNumTemp = chessBoard[rowFromTemp][columnFromTemp];
		if(elementNumTemp <= 6 && elementNumTemp >=1)
			break;
		cout << endl;
		cout << "You can't make that move." << endl;
		cout << "Enter your move: ";
		cin >> *userMove;
		tempMove = *userMove;
		while(!isFormatTrue(*userMove))
		{
			cout << endl;
			cout << "I couldn't understand your move." << endl;
			cout << "Please enter your move like A1-A2." << endl;
			cout << "Enter your move: ";
			cin >> *userMove;
		}
		tempMove = *userMove;
	} while (true);
	*columnFrom = columnFromTemp; *columnTo = columnToTemp;
	*rowFrom = rowFromTemp; *rowTo = rowToTemp;
	*elementNum = elementNumTemp;
}
/******************************************************************************/
bool isFormatTrue(string userMove)
{
	int i=0;
	
	if(	(userMove[0] >= 'A' && userMove[0] <= 'H') ||
		(userMove[0] >= 'a' && userMove[0] <= 'h') )
		++i;
	if(	userMove[1] >= '1' && userMove[1] <= '8' )
		++i;
	if(	userMove[2] == '-' )
		++i;
	if(	(userMove[3] >= 'A' && userMove[3] <= 'H') ||
		(userMove[3] >= 'a' && userMove[3] <= 'h') )
		++i;
	if(	userMove[4] >= '1' && userMove[4] <= '8' )
		++i;	
	
	if (i == 5)
		return true;
	else
		return false;
}
/******************************************************************************/
bool isTrueMoveBishop(int elementNum, int chessBoard[][8], int columnFrom, 
					int rowFrom, int columnTo, int rowTo)
{
	bool isTrue = false;
	int i = columnFrom, j = rowFrom;
	
	if (columnFrom == columnTo && rowFrom == rowTo);
	else if((columnTo>=0 && columnTo<=7) && (rowTo>=0 && rowTo<=7)){
		for (int a = 0; a < 4; a += 1){
			i=columnFrom, j=rowFrom;
			while((i>=0 && i<=7) && (j>=0 && j<=7)){
				if(i==columnTo && j==rowTo){
					isTrue = true;
					break;
				}
				if(a == 0){
					++i, ++j;
					if ((chessBoard[j][i]!=0) && (j!=rowTo) && (i!=columnTo)){
						isTrue = false;
						break;
					}
				}
				if(a == 1){
					++i, --j;
					if ((chessBoard[j][i]!=0) && (j!=rowTo) && (i!=columnTo)){
						isTrue = false;
						break;
					}
				}
				if(a == 2){
					--i, ++j;
					if ((chessBoard[j][i]!=0) && (j!=rowTo) && (i!=columnTo))
					{
						isTrue = false;
						break;
					}
				}
				if(a == 3){
					--i, --j;
					if ((chessBoard[j][i]!=0) && (j!=rowTo) && (i!=columnTo)){
						isTrue = false;
						break;
					}
				}
			}
			if (isTrue)
				break;
		}
	}
	return isTrue;
}
/******************************************************************************/
bool isTrueMoveRook(int elementNum, int chessBoard[][8], int columnFrom, 
					int rowFrom, int columnTo, int rowTo)
{
	bool isTrue = false;
	int i = columnFrom, j = rowFrom, a;

	if (columnFrom == columnTo && rowFrom == rowTo);
	else if((columnTo>=0 && columnTo<=7) && (rowTo>=0 && rowTo<=7)){
		for (a = 0; a < 4; a += 1){
			i=columnFrom, j=rowFrom;
			while((i>=0 && i<=7) && (j>=0 && j<=7)){
				if(i==columnTo && j==rowTo){
					isTrue = true;
					break;
				}
				if(a == 0){
					j+=1;
					if ((chessBoard[j][i]!=0) && (j!=rowTo)){
						isTrue = false;
						break;
					}
				}
				if(a == 1){
					j-=1;
					if ((chessBoard[j][i]!=0) && (j!=rowTo)){
						isTrue = false;
						break;
					}
				}
				if(a == 2){
					i+=1;
					if ((chessBoard[j][i]!=0) && (i!=columnTo))
					{
						isTrue = false;
						break;
					}
				}
				if(a == 3){
					i-=1;
					if ((chessBoard[j][i]!=0) && (i!=columnTo)){
						isTrue = false;
						break;
					}
				}
			}
			if (isTrue)
				break;
		}
	}
	return isTrue;
}
/******************************************************************************/
bool isTrueMoveKnight(int columnFrom, int rowFrom, int columnTo, int rowTo)
{
	bool isTrue = false;
	int i = columnFrom, j = rowFrom;

	if (columnFrom == columnTo && rowFrom == rowTo);
	
	else if((columnTo>=0 && columnTo<=7) && (rowTo>=0 && rowTo<=7))
	{
		i=columnFrom, j=rowFrom;
		if((i>=0 && i<=7) && (j>=0 && j<=7))
		{
			i=columnFrom, j=rowFrom, i+=2, j+=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
				
			i=columnFrom, j=rowFrom, i+=2, j-=1;	
			if(i==columnTo && j==rowTo)
				isTrue = true;
				
			i=columnFrom, j=rowFrom, i-=2, j+=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			
			i=columnFrom, j=rowFrom, i-=2, j-=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			
			i=columnFrom, j=rowFrom, i+=1, j+=2;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			
			i=columnFrom, j=rowFrom, i+=1, j-=2;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			
			i=columnFrom, j=rowFrom, i-=1, j+=2;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			
			i=columnFrom, j=rowFrom, i-=1, j-=2;
			if(i==columnTo && j==rowTo)
				isTrue = true;
		}
	}
	return isTrue;
}
/******************************************************************************/
bool isThereYourElement(int elementNum, int chessBoard[][8],
						int rowTo, int columnTo)
{
	bool isThere = false;
	
	if(elementNum >= 11 && elementNum <= 66)
	{
		if (chessBoard[rowTo][columnTo]>=11 && chessBoard[rowTo][columnTo]<=66)
			isThere = true;
	}
	else if (elementNum >= 1 && elementNum <= 6)
	{
		if (chessBoard[rowTo][columnTo]>=1 && chessBoard[rowTo][columnTo]<=6)
			isThere = true;
	}
	return isThere;
}
/******************************************************************************/
bool isTrueMoveKing(int columnFrom, int rowFrom, int columnTo, int rowTo)
{
	bool isTrue = false;
	int i = columnFrom, j = rowFrom;

	if (columnFrom == columnTo && rowFrom == rowTo);
	
	else if((columnTo>=0 && columnTo<=7) && (rowTo>=0 && rowTo<=7))
	{
		i=columnFrom, j=rowFrom;
		if((i>=0 && i<=7) && (j>=0 && j<=7))
		{
			i=columnFrom, j=rowFrom;
			j+=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			j-=1;	
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			i+=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			i-=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			i+=1, j+=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			i+=1, j-=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			i-=1, j+=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
			i=columnFrom, j=rowFrom;
			i-=1, j-=1;
			if(i==columnTo && j==rowTo)
				isTrue = true;
		}
	}
	return isTrue;
}
/******************************************************************************/
bool isTrueMovePawn(int elementNum, int chessBoard[][8], int columnFrom, 
					int rowFrom, int columnTo, int rowTo)
{	
	bool isTrue = false;
	int i = columnFrom, j = rowFrom;
	
	if((columnTo>=0 && columnTo<=7) && (rowTo>=0 && rowTo<=7))
	{	
		if(elementNum == 1)
		{
			i = columnFrom, j = rowFrom;
			if(((i+1) == columnTo && (j-1) == rowTo) || 
				((i-1) == columnTo && (j-1) == rowTo))
			{	
				if((!isThereYourElement(elementNum,chessBoard,rowTo,columnTo)) 
										&& (chessBoard[rowTo][columnTo]!=0))
					isTrue = true;
			}
			else if (i == columnTo && (j-1) == rowTo)
				isTrue = true;
			else if ((i == columnTo && (j-2) == rowTo) && 
					 (rowFrom == 6) && (chessBoard[j-1][i] == 0))
				isTrue = true;
		}
		else if (elementNum == 11)
		{
			i = columnFrom, j = rowFrom;
			if(((i+1) == columnTo && (j+1) == rowTo) || 
				((i-1) == columnTo && (j+1) == rowTo))
			{	
				if((!isThereYourElement(elementNum,chessBoard,rowTo,columnTo)) 
										&& (chessBoard[rowTo][columnTo]!=0))
					isTrue = true;
			}
			else if (i == columnTo && (j+1) == rowTo)
				isTrue = true;
			else if ((i == columnTo && (j+2) == rowTo) && 
					 (rowFrom == 1)  && (chessBoard[j+1][i] == 0))
				isTrue = true;
		}
		
	}
	return isTrue;
}	
/******************************************************************************/
bool isTrueMove(int chessBoard[][8], int rowFrom, int columnFrom, 
				int rowTo, int columnTo, int elementNum)
{
	bool isTrue = false, temp = false;

	if (elementNum == 1 || elementNum == 11)
		isTrue = isTrueMovePawn(elementNum, chessBoard, columnFrom,
						rowFrom, columnTo, rowTo);
	else if (elementNum == 2 || elementNum == 22)
		isTrue = isTrueMoveBishop(elementNum, chessBoard, columnFrom,
								rowFrom, columnTo, rowTo);
	else if (elementNum == 3 || elementNum == 33)
		isTrue = isTrueMoveKnight(columnFrom, rowFrom, columnTo, rowTo);
	else if (elementNum == 4 || elementNum == 44)
		isTrue = isTrueMoveRook(elementNum, chessBoard, columnFrom,
								rowFrom, columnTo, rowTo);
	else if (elementNum == 5 || elementNum == 55)
	{
		isTrue = isTrueMoveRook(elementNum, chessBoard, columnFrom,
								rowFrom, columnTo, rowTo);
		temp = isTrueMoveBishop(elementNum, chessBoard, columnFrom,
								rowFrom, columnTo, rowTo);
		if (temp || isTrue)
			isTrue = true;
		else
			isTrue = false;
	}
	else if (elementNum == 6 || elementNum == 66)
		isTrue = isTrueMoveKing(columnFrom, rowFrom, columnTo, rowTo);

	if(isThereYourElement(elementNum, chessBoard, rowTo, columnTo))
		isTrue = false;
		
	return isTrue;
}
/******************************************************************************/
bool isGameOver(int chessBoard[][8])
{
	int count = 0;
	
	for (int i = 0; i < 8; i += 1)
	{
		for (int j = 0; j < 8; j += 1)
		{
			if ((chessBoard[i][j] == 6) || (chessBoard[i][j] == 66))
				++count;
		}
	}
	if (count == 2)
		return false;
	else
		return true;
}
/******************************************************************************/
void generateMove	(int *elementNum, int *columnFrom, int *rowFrom, 
					int *columnTo, int *rowTo, int chessBoard[][8])
{
	bool isTrue;
	srand (time(NULL));
	do
	{
		do
		{
			do
			{
				*elementNum = rand() % 100;
			} while ((*elementNum != 11) && (*elementNum != 22) &&
					(*elementNum != 33) && (*elementNum != 44) &&
					(*elementNum != 55) && (*elementNum != 66));
			do
			{
				*columnFrom = rand() % 10;
			} while (!((*columnFrom >= 0) && (*columnFrom <= 7)));
			do
			{
				*rowFrom = rand() % 10;
			} while (!((*rowFrom >= 0) && (*rowFrom <= 7)));
			do
			{
				*columnTo = rand() % 10;
			} while (!((*columnTo >= 0) && (*columnTo <= 7)));
			do
			{
				*rowTo = rand() % 10;
			} while (!((*rowTo >= 0) && (*rowTo <= 7)));
			isTrue = isTrueMove	(chessBoard, *rowFrom, *columnFrom, *rowTo,
								*columnTo, *elementNum);
		} while (!isTrue);	
	} while ((chessBoard[*rowFrom][*columnFrom] != *elementNum));
}
/******************************************************************************/
bool didUserWin(int chessBoard[][8])
{
	bool isTrue = false;
	for (int i = 0; i < 8; i += 1)
	{
		for (int j = 0; j < 8; j += 1)
		{
			if (chessBoard[i][j] == 6)
				isTrue = true;
		}
	}
	return isTrue;
}
/******************************************************************************/
