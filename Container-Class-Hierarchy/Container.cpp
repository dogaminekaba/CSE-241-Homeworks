 /* 
 * File:	Container.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 * 
 */

#include <vector>
#include "Container.h"

namespace Dmk
{	
	template <class T>
	void Container<T>::addAll(const Container& other)
	{
		for (int i = 0; i < other.size; i++)
			list.push_back(other.toVector()[i]);
		size = list.size();
	}
	
	template<class T>
	void Container<T>::removeAll(const Container& other)
	{
		for (int i = 0; i < other.size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (list[j] == other.list[i])
				{
					list.erase(list.begin() + j);
					--j;
					--size;
				}
			}
		}
	}
	
	template <class T>
	const vector <T> Container<T>::toVector() const
	{
		return list;
	}
	
	template<class T>
	const int Container<T>::getSize() const
	{
		return size;
	}
}