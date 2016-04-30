/******************************************************************************/
/*						Header file for FicGames class						  */
/******************************************************************************/

#ifndef	FICTION
#define	FICTION

#include "games.h"

class FicGames : public Games
{
	public:
		FicGames();
		FicGames (string newName, string newPurpose,
				string newDesigner, string newType);
		~FicGames ();
		void setType(const string newType);
		const string getType();
		const int getFicCounter();
	private:
		static int ficCounter;
		string type;
};

#endif
