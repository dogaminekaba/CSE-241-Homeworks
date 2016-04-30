/* 
 * File:	SortedSetContainer.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 *
 */

#include "SortedSetContainer.h"

namespace Dmk
{
	template<class T>
	SortedSetContainer<T>::SortedSetContainer(const vector<T>& orig)
	{
		this->size = 0;
		// setVector function updates the size inside
		for (int i = 0; i < orig.size(); i++)
		{
			if(isUnique(orig.at(i)))
			{
				this->list.push_back(orig.at(i));
				++this->size;
			}
		}
		sort(this->list.begin(), this->list.end());
		listIterator = 0;
	}
	
	template<class T>
	void SortedSetContainer<T>::setVector(const vector<T>& other)	
	{
		for (int i = 0; i < other.size(); i++)
			add(other[i]);
	}
	
	template<class T>
	void SortedSetContainer<T>::add(const T& elem)
	{
		string m;
		m = "SortedSetContainer object must consist of unique elements.\n";
		
		if(isUnique(elem))
		{
			this->list.push_back(elem);
			++this->size;
			sort(this->list.begin(), this->list.end());
		}
		else
			throw m;
	}
	
	template<class T>
	void SortedSetContainer<T>::remove(const T& elem)
	{
		string m;
		m = "The element you want to remove is not in the container.\n";
		bool notFound = true;
		
		for (int i = 0; i < this->size; i++)
		{
			if (this->list[i] == elem)
			{
				this->list.erase(this->list.begin()+i);
				--this->size;
				--i;
				notFound = false;
			}
		}
		if (notFound)
			throw m;
		sort(this->list.begin(), this->list.end());
	}
	
	template<class T>
	const T SortedSetContainer<T>::first()
	{
		listIterator = 1;
		return this->list[0];
	}
	
	template<class T>
	const T SortedSetContainer<T>::next()
	{
		string m;
		m = "Iterator is at the end of the container.\n";
		if (listIterator == this-> size)
			throw m;
		return this->list[listIterator++];
	}
	
	template<class T>
	const vector <int> SortedSetContainer<T>::search(const T& elem) const
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
	bool SortedSetContainer<T>::isUnique(const T& elem)
	{
		bool unique = true;
		
		for (int i = 0; i < this->size; i++)
		{
			if (elem == this->list[i])
				unique = false;
		}
		
		return unique;
	}
	
	template<class T>
	const bool SortedSetContainer<T>::empty() const
	{
		if (this->size == 0)
			return true;
		else
			return false;
	}
}
