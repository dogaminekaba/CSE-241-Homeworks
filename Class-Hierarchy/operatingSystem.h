/******************************************************************************/
/*				Header file for OperatingSystem class						  */
/******************************************************************************/

#ifndef OPERATING
#define OPERATING

#include "system.h"

class OperatingSystem : public System
{
	public:
		OperatingSystem();
		OperatingSystem(string newName, bool newIsOpenSource, 
						string newPlatform);
		~OperatingSystem();
		void setPlatform(const string newPlatform);
		const string getPlatform();
		const int getOperatingCounter();

	private:
		string platform;
		static int operatingCounter;
};

#endif
