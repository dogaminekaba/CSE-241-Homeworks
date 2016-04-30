/* 
 * File:	Word.h
 *			Doğa Mine Kaba
 *			121044004
 * 
 */

#ifndef WORD_H
#define	WORD_H

#include <string>
#include <algorithm>

using namespace std;

namespace Dmk
{
	class Word {
	public:
		Word();
		Word(const string name, const int lineNum);
		Word(const Word& other);
		virtual ~Word();
		void operator = (const Word& other);
		const string getName() const;
		const int getSize() const;
		int * getLineNums() const;
		// adds a new line number to line number array
		void addLine(const int lineNum);
		// converts word and line numbers to string to print easily
		const string toString() const;
	private:
		string name;
		int lineArrSize;
		int* lineNumArr;
		const string intToString(const int num)const;
	};
}//Dmk
#endif	/* WORD_H */

