/* 
 * File:	SortedSetContainer.h
 * Author:	Doğa Mine Kaba
 *			121044004
 *
 */

#ifndef SORTEDSETCONTAINER_H
#define	SORTEDSETCONTAINER_H

#include "Container.h"
#include <vector>

namespace Dmk
{
	template<class T>
	class SortedSetContainer : public Container <T>
	{
	public:
		// constructor
		SortedSetContainer(const vector<T>& orig);
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

#endif	/* SORTEDSETCONTAINER_H */

