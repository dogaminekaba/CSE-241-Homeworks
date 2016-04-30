/******************************************************************************/
/*					Header file for Compilers class							  */
/******************************************************************************/

#ifndef COMPILER
#define COMPILER

#include "system.h"

class Compilers : public System
{
	public:
		Compilers();
		Compilers(string newName, bool newIsOpenSource, string newLanguage);
		~Compilers();
		void setLanguage(const string newLanguage);
		const string getLanguage();
		const int getCompCounter();

	private:
		static int compCounter;
		string language;
};


#endif
