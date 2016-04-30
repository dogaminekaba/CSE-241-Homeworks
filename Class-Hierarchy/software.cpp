/******************************************************************************/
/*					Implementations of Software class						  */
/******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#include "software.h"

Software::Software(): name("Blank")
{
	++swCounter;	// counts the number of objects alive
}
Software::Software(string newName)
{	
	if (isLegalName(newName))
		name = newName;
	else
		name = "Blank";
	++swCounter;
}
Software::~Software()
{
	--swCounter;
}
const string Software::getName()
{
	return name;
}
void Software::setName(const string newName)
{
	name = newName;
}
int Software::swCounter=0;	//sets counter 0 for counting objects

const int Software::getCounter()
{
	return swCounter;
}
/*			Controls if the name consists of a space character				*/
/*			(This control can be specialized later)							*/
bool Software::isLegalName(string newName)
{
	if (newName == " ")
	{
		cout << "Error. Your software name doesn't exist." << endl;
		return false;
	}
	else
		return true;
}
