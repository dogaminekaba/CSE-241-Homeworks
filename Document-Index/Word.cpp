/* 
 * File:	Word.cpp
 *			Doğa Mine Kaba
 *			121044004
 * 
 */

#include "Word.h"

namespace Dmk
{
	Word::Word()
	{
		name = "";
		lineArrSize = 1;
		lineNumArr = new int;
		lineNumArr[0] = 0;
	}
	Word::Word(const string name, const int lineNum)
	{
		this->name = name;
		lineArrSize = 1;
		lineNumArr = new int;
		lineNumArr[0] = lineNum;
	}
	Word::Word(const Word& other)
	{
		this->name = other.name;
		lineArrSize = other.lineArrSize;
		lineNumArr = new int[lineArrSize];
		for (int i = 0; i < lineArrSize; i++)
			lineNumArr[i] = other.lineNumArr[i];
	}
	Word::~Word()
	{
		delete[] lineNumArr;
	}
	void Word::operator =(const Word& other)
	{
		delete[] lineNumArr;

		name = other.name;
		lineArrSize = other.lineArrSize;
		lineNumArr = new int[lineArrSize];
		for (int i = 0; i < lineArrSize; i++)
			lineNumArr[i] = other.lineNumArr[i];
	}
	const string Word::getName() const
	{
		return name;
	}
	void Word::addLine(const int lineNum)
	{
		bool exist = false;
		for (int i = 0; i < lineArrSize; i++)
		{
			if(lineNumArr[i] == lineNum)
				exist = true;
		}

		if(!exist)
		{
			++lineArrSize;
			int temp[lineArrSize];

			for (int i = 0; i < lineArrSize-1; i++)
				temp[i] = lineNumArr[i];
			temp[lineArrSize-1] = lineNum;

			delete [] lineNumArr;
			lineNumArr = new int[lineArrSize];

			for (int i = 0; i < lineArrSize; i++)
				lineNumArr[i] = temp[i];
		}
	}
	const string Word::toString() const
	{
		string result;

		result = name;
		result += " ";

		result += intToString(lineNumArr[0]);
		for (int i = 1; i < lineArrSize; i++)
		{
			result += ", ";
			result += intToString(lineNumArr[i]);
		}

		return result;
	}
	const int Word::getSize() const
	{
		return lineArrSize;
	}
	const string Word::intToString(const int num) const
	{
		int temp = num;
		string result;
		char tempCh;

		while (temp != 0) 
		{
			result += (temp%10) + '0';
			temp = temp/10;
		}
		//Reversing string
		for (int i = 0; i < result.length()/2; i++)
		{
			tempCh = result[i];
			result[i] = result[result.length()-i-1];
			result[result.length()-i-1] = tempCh;
		}
		return result;
	}
	int * Word::getLineNums() const
	{
		return lineNumArr;
	}
}//Dmk