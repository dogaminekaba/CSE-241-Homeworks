/******************************************************************************/
/*						Header file for Games class							  */
/******************************************************************************/

#ifndef	GAMES
#define	GAMES

#include "application.h"

class Games : public AppSoftware
{
	public:
		Games();
		Games(string newName, string newPurpose, string newDesigner);
		~Games();
		void setDesigner(const string newDesigner);
		const string getDesigner();
		const int getGameCounter();
	private:
		static int gameCounter;
		string designer;
};

#endif
