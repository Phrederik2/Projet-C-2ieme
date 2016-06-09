#pragma once
#include <list>

template <typename T> class List
{
protected:
	std::list<T*> Container;
	typename std::list<T*>::iterator Current;
public:
	List();
	~List();

	void Add(T* element);
	T* GetCurrent();
	T* First();
	T* Last();
	T* Next();
	T* Previous();
};

template <typename T> List<T>::List()
{
}

template <typename T> List<T>::~List()
{
	while (!this->Container.empty())
	{
		delete this->Container.back();		//suppression de l'élément
		this->Container.pop_back();			//suppression du pointeur vers l'élément
	}
}

template<typename T> void List<T>::Add(T * element)
{
	if (!element) return;
	this->Container.push_back(element); 
	this->Current = --this->Container.end();
}

template<typename T> T* List<T>::GetCurrent()
{
	if (this->Container.empty()) return NULL;
	return *this->Current;
}

template<typename T> T* List<T>::First()
{
	if (this->Container.empty()) return NULL;
	this->Current = this->Container.begin();
	return this->GetCurrent();
}

template<typename T> T* List<T>::Last()
{
	if (this->Container.empty()) return NULL;
	this->Current = --this->Container.end();
	return this->GetCurrent();
}

template<typename T> T* List<T>::Next()
{
	if (this->Container.empty()) return NULL;
	if (this->Current == --this->Container.end()) return NULL;
	this->Current++;
	return this->GetCurrent();
}

template<typename T> T* List<T>::Previous()
{
	if (this->Container.empty()) return NULL;
	if (this->Current == this->Container.begin()) return NULL;
	this->Current--;
	return this->GetCurrent();
}

