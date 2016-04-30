/******************************************************************************/
/*					Header file for Software class							  */
/******************************************************************************/

#ifndef SOFTWARE
#define SOFTWARE

class Software
{
public:
	Software();
	Software(string newName);
	~Software();
	void setName(const string newName);
	const string getName();
	const int getCounter();
private:
	static int swCounter;
	string name;
	bool isLegalName(string newName);
};

#endif
