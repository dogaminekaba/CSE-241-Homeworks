/******************************************************************************/
/*					Header file for AppSoftware class						  */
/******************************************************************************/

#ifndef APPLICATION
#define APPLICATION

#include "software.h"

class AppSoftware : public Software
{
	public:
		AppSoftware ();
		AppSoftware (string newName, string newPurpose);
		~AppSoftware ();
		void setPurpose(const string newPurpose);
		const string getPurpose();
		const int getAppCounter();
	private:
		string purpose;
		static int appCounter;
};

#endif
