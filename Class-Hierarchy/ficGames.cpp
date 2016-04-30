/******************************************************************************/
/*					Implementations of FicGames class						  */
/******************************************************************************/

#include <iostream>
#include <string>

using namespace std;
#include "ficGames.h"

int FicGames::ficCounter=0;
FicGames::FicGames()
{
	setName("Blank");
	setPurpose("Blank");
	setDesigner("Blank");
	type = "Blank";
	++ficCounter;
}
FicGames::FicGames (string newName, string newPurpose, 
				 string newDesigner, string newType)
{
	setName(newName);
	setPurpose(newPurpose);
	setDesigner(newDesigner);
	type = newType;
	++ficCounter;
}
FicGames::~FicGames()
{
	--ficCounter;
}
void FicGames::setType(const string newType)
{
	type = newType;
}
const string FicGames::getType()
{
	return type;
}
const int FicGames::getFicCounter()
{
	return ficCounter;
}
