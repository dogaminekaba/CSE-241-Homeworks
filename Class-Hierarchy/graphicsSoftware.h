/******************************************************************************/
/*				Header file for GraphicsSoftware class						  */
/******************************************************************************/

#ifndef GRAPHICS
#define GRAPHICS

#include "application.h"

class GraphicsSoftware : public AppSoftware
{
	public:
		GraphicsSoftware();
		GraphicsSoftware(string newName, string newPurpose, string newCompany);
		~GraphicsSoftware ();
		const int getGraphCounter();
		const string getCompany();
		void setCompany(const string newCompany);
		
	private:
		static int graphCounter;
		string company;
};

#endif
