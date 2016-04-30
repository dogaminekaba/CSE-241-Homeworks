/******************************************************************************/
/*					Implementations of Software class						  */
/******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
#include "compilers.h"

int Compilers::compCounter=0;
Compilers::Compilers()
{
	setName("Blank");
	setIsOpenSource(true);
	language = "Blank";
	++compCounter;
}
Compilers::Compilers(string newName, bool newIsOpenSource, string newLanguage)
{
	setName(newName);
	setIsOpenSource(newIsOpenSource);
	language = newLanguage;
	++compCounter;
}
Compilers::~Compilers()
{
	--compCounter;
}
void Compilers::setLanguage(const string newLanguage)
{
	language = newLanguage;
}
const string Compilers::getLanguage()
{
	return language;
}
const int Compilers::getCompCounter()
{
	return compCounter;
}
