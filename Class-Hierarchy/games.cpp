/******************************************************************************/
/*						Implementations of Games class						  */
/******************************************************************************/

#include <iostream>
#include <string>

using namespace std;
#include "games.h"
	
int Games::gameCounter=0;
Games::Games()
{
	setName("Blank");
	setPurpose("Blank");
	designer = "Blank";
	++gameCounter;
}
Games::Games(string newName, string newPurpose, string newDesigner)
{
	setName(newName);
	setPurpose(newPurpose);
	designer = newDesigner;
	++gameCounter;
}
Games::~Games()
{
	--gameCounter;
}
void Games::setDesigner(const string newDesigner)
{
	designer = newDesigner;
}
const string Games::getDesigner()
{
	return designer;
}
const int Games::getGameCounter()
{
	return gameCounter;
}
