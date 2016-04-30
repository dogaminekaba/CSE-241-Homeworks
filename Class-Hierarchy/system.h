/******************************************************************************/
/*					Header file for System class							  */
/******************************************************************************/

#ifndef SYSTEM
#define SYSTEM

#include "software.h"

class System : public Software
{
	public:
		System();
		System(string newName, bool newIsOpenSource);
		~System();
		void setIsOpenSource(const bool newIsOpenSource);
		const bool getIsOpenSource();
		const int getSystemCounter();
	private:
		static int systemCounter;
		bool isOpenSource;
};

#endif
