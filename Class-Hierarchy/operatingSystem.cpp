/******************************************************************************/
/*					Implementations of Software class						  */
/******************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#include "operatingSystem.h"

int OperatingSystem::operatingCounter=0;
OperatingSystem::OperatingSystem()
{
	setName("Blank");
	setIsOpenSource(true);
	platform = "Blank";
	++operatingCounter;
}
OperatingSystem::OperatingSystem(string newName, bool newIsOpenSource, 
								string newPlatform)
{
	setName(newName);
	setIsOpenSource(newIsOpenSource);
	platform = newPlatform;
	++operatingCounter;
}
OperatingSystem::~OperatingSystem()
{
	--operatingCounter;
}
void OperatingSystem::setPlatform(const string newPlatform)
{
	platform = newPlatform;
}
const string OperatingSystem::getPlatform()
{
	return platform;
}
const int OperatingSystem::getOperatingCounter()
{
	return operatingCounter;
}

