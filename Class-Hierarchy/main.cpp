/******************************************************************************/
/*						Doga Mine Kaba	121044004							  */
/*							  	  HW06		 								  */
/*																			  */
/*	In this homework, my base class is Software and my hierarchy goes like:	  */
/*																			  */
/*	+Software																  */
/*		+Application Software												  */
/*			+Video Games													  */
/*				-Fictional Video Games										  */
/*				-Crossover Video Games										  */
/*			-Graphics Software												  */
/*		+System Software													  */
/*			-Operating System												  */
/*			-Compilers														  */
/*																			  */
/******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

#include "ficGames.h"
#include "crossoverGames.h"
#include "graphicsSoftware.h"
#include "system.h"
#include "operatingSystem.h"
#include "compilers.h"

int main ()
{

/*********************Testing Code for Software Class**************************/

	Software	sw1(" "), 
				sw2("Windows");
	
	string str1, str2;
	
	int count, crossChars;
	
	str1 = sw1.getName();
	str2 = sw2.getName();
	count = sw2.getCounter();
	
	cout << endl;
	cout << "Your softwares are: " << str1 << " and " << str2 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl << endl;

/*******************Testing Code for AppSoftware Class*************************/

	AppSoftware app1("Dreamfall","Entertainment");
	
	str1 = app1.getName();
	count = app1.getCounter();
	cout << "Your application is: " << str1 << endl;
	str1 = app1.getPurpose();
	cout << "Purpose of this application is: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl << endl;

/***********************Testing Code for Games Class***************************/
	
	Games game1("Tomb Raider","Entertainment","Darrell Gallagher");
	
	str1 = game1.getName();
	count = game1.getCounter();
	cout << "Your game is: " << str1 << endl;
	str1 = game1.getPurpose();
	cout << "Purpose of this application is: " << str1 << endl;
	str1 = game1.getDesigner();
	cout << "Designer of this game is: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl << endl;

/*********************Testing Code for FicGames Class**************************/

	FicGames fic1("Dreamfall","Entertainment","Ragnar Tornquist","Fictional");
	
	str1 = fic1.getName();
	count = fic1.getCounter();
	cout << "Your game is: " << str1 << endl;
	str1 = fic1.getPurpose();
	cout << "Purpose of this application is: " << str1 << endl;
	str1 = fic1.getDesigner();
	cout << "Designer of this game is: " << str1 << endl;
	str1 = fic1.getType();
	cout << "Type of this game is: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl;
	count = fic1.getFicCounter();
	cout << "(Number of objects created in FicGames class: "
		 << count << ")" << endl << endl;

/*******************Testing Code for CrossoverGames Class**********************/

	CrossoverGames cross1("Alien vs. Predator","Entertainment","Unknown", 2);
	
	str1 = cross1.getName();
	count = cross1.getCounter();
	cout << "Your game is: " << str1 << endl;
	str1 = cross1.getPurpose();
	cout << "Purpose of this application is: " << str1 << endl;
	str1 = cross1.getDesigner();
	cout << "Designer of this game is: " << str1 << endl;
	crossChars = cross1.getCharNum();
	cout << "Number of characters crossovered in game: " << crossChars << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl;
	count = cross1.getCrossCounter();
	cout << "(Number of objects created in CrossoverGames class: "
		 << count << ")" << endl << endl;

/******************Testing Code for GraphicsSoftware Class*********************/
	
	GraphicsSoftware graph1("Photoshop","Visual Art","Adobe");
	
	str1 = graph1.getName();
	count = graph1.getCounter();
	cout << "Your graphics software is: " << str1 << endl;
	str1 = graph1.getPurpose();
	cout << "Purpose of this application is: " << str1 << endl;
	str1 = graph1.getCompany();
	cout << "Company of this application is: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl;
	count = app1.getAppCounter();
	cout << "(Number of objects created in AppSoftware class: "
		 << count << ")" << endl << endl;

/***********************Testing Code for System Class**************************/
	
	System sys1("Linux",true);
	
	str1 = sys1.getName();
	count = sys1.getCounter();
	cout << "Your system software is: " << str1 << endl;
	if(sys1.getIsOpenSource())
		str1 = "Yes.";
	else
		str1 = "No.";
	cout << "Is this software open source: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl;
	count = sys1.getSystemCounter();
	cout << "(Number of objects created in System class: "
		 << count << ")" << endl << endl;
	
/*******************Testing Code for OperatingSystem Class*********************/
	
	OperatingSystem os1("Windows",false,"PC");
	
	str1 = os1.getName();
	count = os1.getCounter();
	cout << "Your operating system is: " << str1 << endl;
	if(os1.getIsOpenSource())
		str1 = "Yes.";
	else
		str1 = "No.";
	cout << "Is this operating system open source: " << str1 << endl;
	str1 = os1.getPlatform();
	cout << "Platform of this operating system is: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl;
	count = os1.getOperatingCounter();
	cout << "(Number of objects created in OperatingSystem class: "
		 << count << ")" << endl << endl;
		
/**********************Testing Code for Compilers Class************************/

	Compilers comp1("GNU",true,"C++");
	
	str1 = comp1.getName();
	count = comp1.getCounter();
	cout << "Your compiler is: " << str1 << endl;
	if(comp1.getIsOpenSource())
		str1 = "Yes.";
	else
		str1 = "No.";
	cout << "Is this system software open source: " << str1 << endl;
	str1 = comp1.getLanguage();
	cout << "Language of this compiler is: " << str1 << endl;
	cout << "(Number of objects created in Software class: "
		 << count << ")" << endl;
	count = comp1.getCompCounter();
	cout << "(Number of objects created in Compilers class: "
		 << count << ")" << endl << endl;
	
}
