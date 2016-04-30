/* 
 * File:	main.cpp
 *			Doğa Mine Kaba
 *			121044004
 *	This program takes a document file name as input 
 *	and it will form the document index and save it to another file.
 */

#include <iostream>
#include <string>
#include "Word.h"
#include "DocumentIndex.h"

using namespace std;
using namespace Dmk;

int main()
{
	DocumentIndex index1("source");
	DocumentIndex index2("source2");
	DocumentIndex index3("source3");
	
	cout << "DOCUMENT INDEX 1" << endl << endl;
	index1.printToScreen();
	index1.writeToFile("output1");
	index2 += index1;
	index2.writeToFile("output2");
	index3 = index1 + index3;
	index3.writeToFile("output3");
	
	cout << "Please enter a word and its line number: " << endl;
	cin >> index3;
	cout << endl << "DOCUMENT INDEX 3" << endl << endl;
	cout << index3;
	
	return 0;
}