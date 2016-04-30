/* 
 * File:   SetContainer.cpp
 * Author:	Doğa Mine Kaba
 *			121044004
 * 
 */

#include "SetContainer.h"

namespace Dmk
{
	template<class T>
	SetContainer<T>::SetContainer(const vector<T>& orig)
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
		listIterator = 0;
	}
	
	template<class T>
	void SetContainer<T>::setVector(const vector<T>& other)	
	{
		for (int i = 0; i < other.size(); i++)
			add(other[i]);
	}
	
	template<class T>
	void SetContainer<T>::add(const T& elem)
	{
		string m;
		m = "SetContainer object must consist of unique elements.\n";
		
		if(isUnique(elem))
		{
			this->list.push_back(elem);
			++this->size;
		}
		else
			throw m;
	}
	
	template<class T>
	void SetContainer<T>::remove(const T& elem)
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
	}
	
	template<class T>
	const T SetContainer<T>::first()
	{
		listIterator = 1;
		return this->list[0];
	}
	
	template<class T>
	const T SetContainer<T>::next()
	{
		string m;
		m = "Iterator is at the end of the container.\n";
		if (listIterator == this-> size)
			throw m;
		return this->list[listIterator++];
	}
	
	template<class T>
	const vector <int> SetContainer<T>::search(const T& elem) const
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
	bool SetContainer<T>::isUnique(const T& elem)
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
	const bool SetContainer<T>::empty() const
	{
		if (this->size == 0)
			return true;
		else
			return false;
	}
}