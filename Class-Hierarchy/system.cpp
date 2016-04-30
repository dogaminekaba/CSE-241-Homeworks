/******************************************************************************/
/*						Implementations of System class						  */
/******************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#include "system.h"

int System::systemCounter=0;
System::System()
{
	setName("Blank");
	isOpenSource = true;
	++systemCounter;
}
System::System(string newName, bool newIsOpenSource)
{
	setName(newName);
	isOpenSource = newIsOpenSource;
	++systemCounter;
}
System::~System()
{
	--systemCounter;
}
void System::setIsOpenSource(const bool newIsOpenSource)
{
	isOpenSource = newIsOpenSource;
}
const bool System::getIsOpenSource()
{
	return isOpenSource;
}
const int System::getSystemCounter()
{
	return systemCounter;
}
