/* 
 * File:   SetContainer.h
 * Author:	Doğa Mine Kaba
 *			121044004
 * 
 */

#ifndef SETCONTAINER_H
#define	SETCONTAINER_H
#include "Container.h"
#include <vector>

namespace Dmk
{
	template<class T>
	class SetContainer : public Container <T>
	{
	public:
		// constructor
		SetContainer(const vector<T>& orig);
		// setter - getters
		void setVector(const vector<T>& other);
		// other functions
		void add(const T& elem);
		void remove(const T& elem);
		const vector <int> search(const T& elem) const;
		const T first();
		const T next();
		const bool empty() const;
	private:
		int listIterator;
		bool isUnique(const T& elem);
	};
}
#endif	/* SETCONTAINER_H */

