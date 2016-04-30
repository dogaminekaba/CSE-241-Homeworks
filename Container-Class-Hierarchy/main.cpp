/* 
 * File:	main.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 * In this program I wrote a set of templated classes in a hierarchy
 */

#include "SortedContainer.cpp"
#include "SetContainer.cpp"
#include "Container.cpp"
#include "SortedSetContainer.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace Dmk;

template <class T>
const int numOfSortedElems(const vector <Container <T> *> cList);

int main()
{
	vector <string> strVec(6);
	strVec[0] = "But";
	strVec[1] = "a";
	strVec[2] = "dream";
	strVec[3] = "within";
	strVec[4] = "a";
	strVec[5] = "dream";
	
	string word;
	
	vector <int> intVec (6);
	intVec[0] = 12;
	intVec[1] = 3;
	intVec[2] = 5;
	intVec[3] = 3;
	intVec[4] = 1;
	intVec[5] = 8;
	
	int num = 0;
	
	// SORTED STRING CONTAINER
	
	SortedContainer <string> sortC(strVec);
	cout << endl;
	cout << "SORTED STRING CONTAINER" << endl << endl;
	cout << "Container elements: " ;
	
	cout << sortC.first() << " ";
	for (int i = 1; i < sortC.getSize(); i++)
		cout << sortC.next() << " ";
	cout << endl;
	
	cout << "Please enter a word to add to container: ";
	cin >> word;
	
	try
	{
		sortC.add(word);
		for (int i = 0; i < sortC.getSize(); i++)
			cout << sortC.toVector()[i] << " ";
		cout << endl;
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	cout << "Please enter a word to remove from the container: ";
	cin >> word;
	
	try
	{
		sortC.remove(word);
		for (int i = 0; i < sortC.getSize(); i++)
			cout << sortC.toVector()[i] << " ";
		cout << endl;
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	cout << "Please enter the word you want to search in the container: ";
	cin >> word;
	
	try
	{
		vector <int> index;
		index = sortC.search(word);
		if (!index.empty())
		{
			cout << "Your element indexes are: ";
			for (int i = 0; i < index.size(); i++)
				cout << index[i] << " ";
			cout << endl;
		}
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	// SET STRING CONTAINER
	
	SetContainer <string> setC(strVec);
	cout << endl;
	cout << "SET STRING CONTAINER" << endl << endl;
	cout << "Container elements: " ;
	
	cout << setC.first() << " ";
	for (int i = 1; i < setC.getSize(); i++)
		cout << setC.next() << " ";
	cout << endl;
	
	cout << "Please enter a word to add to container: ";
	cin >> word;
	
	try
	{
		setC.add(word);
		for (int i = 0; i < setC.getSize(); i++)
			cout << setC.toVector()[i] << " ";
		cout << endl;
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	cout << "Please enter a word to remove from the container: ";
	cin >> word;
	
	try
	{
		setC.remove(word);
		for (int i = 0; i < setC.getSize(); i++)
			cout << setC.toVector()[i] << " ";
		cout << endl;
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	cout << "Please enter the word you want to search in the container: ";
	cin >> word;
	
	try
	{
		vector <int> index;
		index = setC.search(word);
		if (!index.empty())
		{
			cout << "Your element index is: ";
			for (int i = 0; i < index.size(); i++)
				cout << index[i] << " ";
			cout << endl;
		}
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	// SORTED SET INT CONTAINER
	
	SortedSetContainer <int> sortSetC(intVec);
	cout << endl;
	cout << "SORTED SET INT CONTAINER" << endl << endl;
	cout << "Container elements: " ;
	
	for (int i = 0; i < sortSetC.getSize(); i++)
		cout << sortSetC.toVector().at(i) << " ";
	cout << endl;
	
	cout << "Please enter an integer to add to container: ";
	cin >> num;
	
	try
	{
		sortSetC.add(num);
		for (int i = 0; i < sortSetC.getSize(); i++)
			cout << sortSetC.toVector()[i] << " ";
		cout << endl;
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	cout << "Please enter an integer to remove from the container: ";
	cin >> num;
	
	try
	{
		sortSetC.remove(num);
		for (int i = 0; i < sortSetC.getSize(); i++)
			cout << sortSetC.toVector()[i] << " ";
		cout << endl;
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	cout << "Please enter the integer you want to search in the container: ";
	cin >> num;
	
	try
	{
		vector <int> index;
		index = sortSetC.search(num);
		if (!index.empty())
		{
			cout << "Your element index is: ";
			for (int i = 0; i < index.size(); i++)
				cout << index[i] << " ";
			cout << endl;
		}
	}	
	catch (string message)
	{
		cout << message; 
	}
	
	// CONTAINER FUNCTIONS
	
	cout << endl << "CONTAINER FUNCTIONS" << endl;
	
	cout << "addAll function for two strings: " << endl;
	sortC.addAll(setC);
	for (int i = 0; i < sortC.getSize(); i++)
		cout << sortC.toVector()[i] << " ";
	cout << endl;
	
	cout << "removeAll function for two strings: " << endl;
	sortC.removeAll(setC);
	for (int i = 0; i < sortC.getSize(); i++)
		cout << sortC.toVector()[i] << " ";
	cout << endl;
	
	// GLOBAL FUNCTION
	
	vector <Container <string> *> vec;
	
	vec.push_back(&sortC);
	vec.push_back(&setC);
	
	cout << endl << "Number of sorted elements in this program is: ";
	cout << numOfSortedElems(vec) << endl;
	
	return 0;
}

template <class T>
const int numOfSortedElems(const vector <Container <T> *> cList)
{
	int result=0;
	for (int i = 0; i < cList.size(); i++)
	{
		if (SortedContainer<T>*s = dynamic_cast <SortedContainer<T>*>(cList[i]))
		{
			for (int j = 0; j < cList[i]->getSize(); j++)
				++result;
		}
	}
	return result;
}
