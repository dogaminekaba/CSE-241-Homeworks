/* 
 * File:	DocumentIndex.cpp
 *			Doğa Mine Kaba
 *			121044004
 * 
 */

#include "DocumentIndex.h"
namespace Dmk
{
	DocumentIndex::DocumentIndex(const string fileName)
	{
		readFile(fileName);
		sortWords();
	}

	DocumentIndex::DocumentIndex(const DocumentIndex& other)
	{
		wordListSize = other.wordListSize;
		wordList = new Word[wordListSize];

		for (int i = 0; i < wordListSize; i++)
			wordList[i] = other.wordList[i];
	}

	DocumentIndex::~DocumentIndex()
	{		
		delete[] wordList;
	}

	void DocumentIndex::readFile(const string fileName)
	{
		ifstream sourceFile;
		string line, newWord;

		int currentLine = 1;
		wordListSize = 0;

		sourceFile.open((fileName + ".txt").c_str());

		while (getline(sourceFile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				while ((line[i] >= 'a' && line[i] <= 'z')
						|| (line[i] >= 'A' && line[i] <= 'Z'))
				{
					newWord += line[i];
					++i;
				}
				if(newWord != "")
					addWord(newWord, currentLine);
				newWord = "";
			}
			++currentLine;
		}
		sourceFile.close();
	}
	void DocumentIndex::addWord(const string name, const int lineNum)
	{
		bool exist = false;
		int i;
		string lcName; // lowercase word

		lcName = name;
		transform	(lcName.begin(), lcName.end(), 
					lcName.begin(),(int (*)(int))tolower);

		for (i = 0; i < wordListSize; i++)
		{
			if (lcName == wordList[i].getName())
			{
				exist = true;
				break;
			}
		}
		if (exist)
			wordList[i].addLine(lineNum);
		else if (wordListSize == 0)
		{
			wordListSize = 1;
			wordList = new Word(lcName, lineNum);
		}
		else
		{	
			Word temp[wordListSize+1];

			for (i = 0; i < wordListSize; i++)
				temp[i] = wordList[i];
			temp[i] = Word(lcName, lineNum);

			if (wordListSize == 1) 
				delete wordList;
			else
				delete [] wordList;

			wordListSize += 1;
			wordList = new Word[wordListSize];

			for (i = 0; i < wordListSize; i++)
				wordList[i]	= temp[i];
		}
	}
	void DocumentIndex::addWord(const Word& w)
	{
		for (int i = 0; i < w.getSize(); i++)
			addWord(w.getName(), w.getLineNums()[i]);
	}
	void DocumentIndex::sortWords()
	{
		Word temp;
		int index=0;

		for (int i = 0; i < wordListSize; i++)
		{
			index = greatest(wordList+i, wordListSize-i);
			temp = wordList[i];
			wordList[i] = wordList[index+i];
			wordList[index+i] = temp;
		}
	}
	const int DocumentIndex::greatest(const Word* base, const int size) const
	{
		int index=0;
		string first = "z";

		for (int i = 0; i < size; i++) 
		{
			if(first.compare(base[i].getName()) >= 0)
			{
				index = i;
				first = base[i].getName();
			}
		}
		return index;
	}
	void DocumentIndex::printToScreen() const
	{
		bool title = false;
		for (char i = 'a'; i <= 'z'; ++i) 
		{
			for (int j = 0; j < wordListSize; ++j)
			{
				if (i == wordList[j].getName()[0])
				{
					if(!title)
					{
						cout << static_cast<char>(toupper(i)) << endl;
						title = true;
					}
					cout << wordList[j].toString() << endl;
				}
			}
			cout << endl;
			title = false;
		}
	}
	void DocumentIndex::writeToFile(const string fileName) const
	{
		ofstream outFile;

		outFile.open((fileName + ".txt").c_str());

		bool title = false;
		for (char i = 'a'; i <= 'z'; ++i) 
		{
			for (int j = 0; j < wordListSize; ++j)
			{
				if (i == wordList[j].getName()[0])
				{
					if(!title)
					{
						outFile << static_cast<char>(toupper(i)) << endl;
						title = true;
					}
					outFile << wordList[j].toString() << endl;
				}
			}
			outFile << endl;
			title = false;
		}
		outFile.close();
	}
	void DocumentIndex::operator =(const DocumentIndex& other)
	{
		delete [] wordList;

		wordListSize = other.wordListSize;
		wordList = new Word[wordListSize];

		for (int i = 0; i < wordListSize; i++)
			wordList[i] = other.wordList[i];
	}
	int * DocumentIndex::operator [](const string word) const
	{
		for (int i = 0; i < wordListSize; i++)
		{
			if (wordList[i].getName() == word)
				return wordList[i].getLineNums();
		}
		return NULL;
	}
	const string DocumentIndex::operator [](const int lineNum) const
	{
		string result;

		for (int i = 0; i < wordListSize; i++)
		{
			for (int j = 0; j < wordList[i].getSize(); j++)
			{
				if(lineNum == wordList[i].getLineNums()[j])
				{
					result += wordList[i].getName();
					result += " ";
				}
			}
		}
		return result;
	}
	void DocumentIndex::operator +=(const DocumentIndex& other)
	{
		for (int i = 0; i < other.wordListSize; i++)
			addWord(other.wordList[i]);
		sortWords();
	}
	const DocumentIndex operator + (const DocumentIndex& first,
									const DocumentIndex& second)
	{
		DocumentIndex result(first);
		result += second;
		return result;
	}
	ostream& operator << (ostream& out, const DocumentIndex& document)
	{
		bool title = false;
		for (char i = 'a'; i <= 'z'; ++i) 
		{
			for (int j = 0; j < document.wordListSize; ++j)
			{
				if (i == document.wordList[j].getName()[0])
				{
					if(!title)
					{
						out << static_cast<char>(toupper(i)) << endl;
						title = true;
					}
					out << document.wordList[j].toString() << endl;
				}
			}
			out << endl;
			title = false;
		}
		return out;
	}
	istream& operator >> (istream& in, DocumentIndex& document)
	{
		string word;
		int lineNum;
		in >> word >> lineNum;
		document.addWord(word, lineNum);
		return in;
	}
}//Dmk