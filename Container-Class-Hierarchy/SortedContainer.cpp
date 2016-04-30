/* 
 * File:	SortedContainer.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 * 
 */

#include "SortedContainer.h"
#include <algorithm>
#include <vector>
using namespace std;

namespace Dmk
{
	template<class T>
	SortedContainer<T>::SortedContainer(const vector<T>& orig)
	{
		this->list = orig;
		this->size = orig.size();
		sort(this->list.begin(), this->list.end());
		listIterator = 0;
	}

	template<class T>
	void SortedContainer<T>::setVector(const vector<T>& other)
	{
		this->list = other;
		this->size = other.size();
		sort(this->list.begin(), this->list.end());
		listIterator = 0;
	}
	
	template<class T>
	void SortedContainer<T>::add(const T& elem)
	{
		this->list.push_back(elem);
		sort(this->list.begin(), this->list.end());
		++this->size;
	}
	
	template<class T>
	const T SortedContainer<T>::first()
	{
		listIterator = 1;
		return this->list[0];
	}

	template<class T>
	const T SortedContainer<T>::next()
	{
		string m;
		m = "Iterator is at the end of the container.\n";
		if (listIterator == this-> size)
			throw m;
		return this->list[listIterator++];
	}

	template<class T>
	void SortedContainer<T>::remove(const T& elem)
	{
		string m;
		m = "The element you want to remove is not in the container.\n";
		bool notFound = true;
		
		for (int i = 0; i < this->size; i++)
		{
			if (this->list[i] == elem)
			{
				this->list.erase(this->list.begin()+i);
				--(this->size);
				--i;
				notFound = false;
			}
		}
		if (notFound)
			throw m;
		sort(this->list.begin(), this->list.end());
	}

	template<class T>
	const vector <int> SortedContainer<T>::search(const T& elem) const
	{
		string m;
		m = "Element you search in the container doesn't exist.\n";
		vector <int> result;
		
		for (int i = 0; i < this->size; i++)
		{
			if (this->list[i] == elem)
				result.push_back(i);
		}
		if (result.empty())
			throw m;
		
		return result;
	}
	
	template<class T>
	const bool SortedContainer<T>::empty() const
	{
		if (this->size == 0)
			return true;
		else
			return false;
	}

}

