#pragma once

#include <list>

template <typename T> class List
{
protected:
	static List<T>* Owner;
	std::list<T*> Container;
	typename std::list<T*>::iterator Current;
	static unsigned long Alive;

public:
	List();
	~List();
	List(const List<T> & source);
	List<T> & operator=(List<T> & source);

	void Flush();

	size_t Size() const;

	List<T>* GetOwner() const;

	List<T> & Add(T * element);
	T* GetCurrent();
	T* First();
	T* Last();
	T* Next();
	T* Previous();
};

template <class T>
List<T>* List<T>::Owner = 0;

template <class T>
unsigned long List<T>::Alive = 0;

template <typename T> List<T>::List()
{
	this->Current = this->Container.end();
	if (!this->Owner) this->Owner = this;
	this->Alive++;
}

template <typename T> List<T>::~List()
{
	this->Flush();
	this->Alive--;
	if (this->Owner == this) this->Owner = 0;
}

template<typename T>
List<T>::List(const List<T> & source)
{
	if (!&source) return;
	if (&source == this) return;

	if (!this->Owner) this->Owner = this;
	this->Container = source.Container;
	this->Current = this->Container.begin();
	while (
		this->Current != this->Container.end() &&
		*this->Current != *source.Current
		)
		this->Current++;
	this->Alive++;
}

template<typename T>
List<T> & List<T>::operator=(List<T> & source)
{
	if (&source == this) return *this;
	this->Container = source.Container;
	this->Current = this->Container.begin();
	while (
		this->Current != this->Container.end() &&
		*this->Current != *source.Current
		)
		this->Current++;

	return *this;
}

template <class T>
void List<T>::Flush()
{
	if (this->Owner == this && this->Alive > 1) return;
	while (this->Size())
	{
		if (this->Owner == this)
			delete this->Container.back();
		this->Container.pop_back();
	}
}

template <class T>
size_t List<T>::Size() const
{
	return this->Container.size();
}

template <class T>
List<T>* List<T>::GetOwner() const
{
	return this->Owner;
}

template<typename T>
List<T> & List<T>::Add(T * element)
{
	this->Container.push_back(element);
	this->Current = --this->Container.end();
	return *this;
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



