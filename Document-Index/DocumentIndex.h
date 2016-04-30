/* 
 * File:	DocumentIndex.h
 *			Doğa Mine Kaba
 *			121044004
 * 
 */

#ifndef DOCUMENTINDEX_H
#define	DOCUMENTINDEX_H

#include "Word.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

namespace Dmk
{
	class DocumentIndex {
	public:
		DocumentIndex(const string fileName);
		DocumentIndex(const DocumentIndex& other);
		virtual ~DocumentIndex();
		void writeToFile(const string fileName) const;
		void printToScreen() const;
			//Operator Overloadings
		void operator = (const DocumentIndex& other);
		void operator += (const DocumentIndex& other);
		int* operator[](const string word) const;
		const string operator[](const int lineNum) const;
		friend ostream& operator << (ostream& out, const DocumentIndex& document);
		friend istream& operator >> (istream& in, DocumentIndex& document);
		friend const DocumentIndex operator + (const DocumentIndex& first,
												const DocumentIndex& second);
	private:
		int wordListSize;
		Word* wordList;
		void readFile(const string fileName);
		void addWord(const string name, const int lineNum);
		void sortWords();
		const int greatest(const Word* base, const int size) const;
		void addWord(const Word& w);
	};
}//Dmk

#endif	/* DOCUMENTINDEX_H */

