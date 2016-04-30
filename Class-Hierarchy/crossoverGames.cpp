/******************************************************************************/
/*				Implementations of CrossoverGames class						  */
/******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#include "crossoverGames.h"

int CrossoverGames::crossCounter=0;
CrossoverGames::CrossoverGames()
{
	setName("Blank");
	setPurpose("Blank");
	setDesigner("Blank");
	charNum = 0;
	++crossCounter;
}
CrossoverGames::CrossoverGames(string newName, string newPurpose,
								string newDesigner, int newCharNum)
{
	setName(newName);
	setPurpose(newPurpose);
	setDesigner(newDesigner);
	charNum = newCharNum;
	++crossCounter;
}
CrossoverGames::~CrossoverGames()
{
	--crossCounter;
}
void CrossoverGames::setCharNum(const int newCharNum)
{
	charNum = newCharNum;
}
const int CrossoverGames::getCharNum()
{
	return charNum;
}
const int CrossoverGames::getCrossCounter()
{
	return crossCounter;
}




