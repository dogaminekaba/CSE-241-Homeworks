/* 
 * File:	Container.h
 * Author:	Doğa Mine Kaba
 *			121044004
 *
 */

#ifndef CONTAINER_H
#define	CONTAINER_H
#include <iostream>
#include <vector>

using namespace std;

namespace Dmk
{
	template <class T>
	class Container
	{
	public:
		// pure virtual functions
		virtual void add(const T& elem)=0;
		virtual void remove(const T& elem)=0;
		virtual const vector<int> search(const T& elem) const =0;
		virtual const T first()=0;
		virtual const T next()=0;
		virtual const bool empty() const =0;
		// concrete functions
		void addAll(const Container& other);
		void removeAll(const Container& other);
		const vector <T> toVector() const;
		const int getSize() const;
		
	protected:
		vector <T> list;
		int size;
	};
}
#endif	/* CONTAINER_H */

