/******************************************************************************/
/*				Implementations of GraphicsSoftware class					  */
/******************************************************************************/

#include<iostream>
#include<string>
using namespace std;
#include "graphicsSoftware.h"

int GraphicsSoftware::graphCounter=0;
GraphicsSoftware::GraphicsSoftware()
{
	setName("Blank");
	setPurpose("Blank");
	company = "Blank";
	++graphCounter;
}
GraphicsSoftware::GraphicsSoftware(string newName, string newPurpose, 
									string newCompany)
{
	setName(newName);
	setPurpose(newPurpose);
	company = newCompany;
	++graphCounter;
}
GraphicsSoftware::~GraphicsSoftware()
{
	--graphCounter;
}
void GraphicsSoftware::setCompany(const string newCompany)
{
	company = newCompany;
}
const string GraphicsSoftware::getCompany()
{
	return company;
}
const int GraphicsSoftware::getGraphCounter()
{
	return graphCounter;
}
