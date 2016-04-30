/******************************************************************************/
/*					Header file for CrossoverGames class					  */
/******************************************************************************/

#ifndef CROSSOVER
#define CROSSOVER

#include "games.h"

class CrossoverGames : public Games
{
	public:
		CrossoverGames ();
		CrossoverGames (string newName, string newPurpose,
						string newDesigner, int newCharNum);
		~CrossoverGames ();
		const int getCharNum();
		void setCharNum(const int newCharNum);
		const int getCrossCounter();
	private:
		static int crossCounter;
		int charNum; // number of characters in crossover game
};

#endif
