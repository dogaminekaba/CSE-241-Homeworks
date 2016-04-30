/******************************************************************************/
/*					Implementations of AppSoftware class					  */
/******************************************************************************/

#include <iostream>
#include <string>

using namespace std;
#include "application.h"

int AppSoftware::appCounter=0;
AppSoftware::AppSoftware(): purpose("Blank")
{
	setName("Blank");
	++appCounter;
}
AppSoftware::AppSoftware(string newName, string newPurpose)
{
	if (newPurpose != " ")
		purpose = newPurpose;
	else
		purpose = "Blank";
	setName(newName);
	++appCounter;
}
AppSoftware::~AppSoftware()
{
	--appCounter;
}
const string AppSoftware::getPurpose()
{
	return purpose;
}
void AppSoftware::setPurpose(const string newPurpose)
{
	if (newPurpose != " ")
		purpose = newPurpose;
	else
		purpose = "Blank";
}
const int AppSoftware::getAppCounter()
{
	return appCounter;
}


