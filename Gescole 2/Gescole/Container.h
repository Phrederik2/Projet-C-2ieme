#pragma once

#include<vector>
#include<iostream>
using namespace std;

template<class ENTITY>
class Container
{
public:
	const Container<ENTITY>& operator=(const Container<ENTITY>& other);
	Container();
	Container(const Container<ENTITY>& other);
	~Container();
	ENTITY* Add(ENTITY* other);
	ENTITY* First();
	ENTITY* Last();
	ENTITY* Next();
	ENTITY* Previous();
	Container<ENTITY>& Duplication(const Container<ENTITY>& other);
	bool Flush();
	size_t Size() const;
	bool isOwner();
	Container<ENTITY>* getOwner();
	void setMaster();
	void setOwner();

protected:
	ENTITY* Find(ENTITY* other);
	

protected:
	static double inLife;
	static Container<ENTITY>* idOwner;
	typename vector<ENTITY*> m_container;
	typename vector<ENTITY*>::iterator m_it;

};


template<class ENTITY>
Container<ENTITY>* Container<ENTITY>::idOwner = NULL;
template<class ENTITY>
double Container<ENTITY>::inLife = 0;

template<class ENTITY>
const Container<ENTITY>& Container<ENTITY>::operator=(const Container<ENTITY> & other)
{
	return Duplication(other);
}

template<class ENTITY>
Container<ENTITY>::Container()
{
	if (!idOwner) idOwner = this;
	inLife++;
}

template<class ENTITY>
Container<ENTITY>::Container(const Container<ENTITY> & other)
{
	Duplication(other);
	inLife++;
}


template<class ENTITY>
Container<ENTITY>::~Container()
{
	Flush();
	inLife--;
}

template<class ENTITY>
ENTITY * Container<ENTITY>::Add(ENTITY * other)
{
	if (!other)return 0;
	if (!idOwner) idOwner = this;
	if (!isOwner()) idOwner->Add(other);
	if (!Find(other))
	{
		m_container.push_back(other);
		m_it = m_container.end();
		m_it--;
	}

	return (*m_it);
}

template<class ENTITY>
ENTITY * Container<ENTITY>::First()
{
	if (idOwner)
	{
		if (!m_container.size() && !idOwner)return 0;
		m_it = m_container.begin();
	}

	return (*m_it);

}

template<class ENTITY>
ENTITY * Container<ENTITY>::Last()
{
	if (idOwner)
	{
		if (!m_container.size() && !idOwner)return 0;
		m_it = m_container.end();
		m_it--;
	}

	return (*m_it);
}

template<class ENTITY>
ENTITY * Container<ENTITY>::Next()
{
	if (idOwner)
	{
		if (!m_container.size() && !idOwner)return 0;
		if (m_it == m_container.end() - 1)return 0;
		m_it++;
	}

	return (*m_it);
}

template<class ENTITY>
ENTITY * Container<ENTITY>::Previous()
{
	if (idOwner)
	{
		if (!m_container.size() && !idOwner)return 0;
		if (m_it == m_container.begin())return 0;
		m_it--;
	}

	return (*m_it);
}

template<class ENTITY>
Container<ENTITY>& Container<ENTITY>::Duplication(const Container<ENTITY>& other)
{
	if (this == &other) return *this;
	if (!other.Size()) return *this;
	m_container = other.m_container;
	m_it = m_container.begin();

	while ((*m_it != *other.m_it) && (m_it != other.m_container.end())) m_it++;

	m_it = other.m_it;
	return *this;
}

template<class ENTITY>
bool Container<ENTITY>::Flush()
{

	if (idOwner == this && inLife == 1)
	{
		for (m_it = m_container.begin(); m_it != m_container.end(); m_it++)
		{
			delete *m_it;
		}
		idOwner = NULL;

		m_container.clear();
	}

	if (idOwner != this) m_container.clear();

	return (true);
}

template<class ENTITY>
size_t Container<ENTITY>::Size() const
{
	if (!idOwner) return 0;
	return m_container.size();
}

template<class ENTITY>
bool Container<ENTITY>::isOwner()
{
	return (idOwner == this);
}

template<class ENTITY>
Container<ENTITY> * Container<ENTITY>::getOwner()
{
	return idOwner;
}

template<class ENTITY>
void Container<ENTITY>::setMaster()
{
}

template<class ENTITY>
void Container<ENTITY>::setOwner()
{
	if (!idOwner || (idOwner && (Size() >= idOwner->Size()))) idOwner = this;
}

template<class ENTITY>
ENTITY* Container<ENTITY>::Find(ENTITY * other)
{

	for (m_it = m_container.begin(); m_it != m_container.end(); m_it++)
	{
		if (*m_it == other) return *m_it;
	}

	return NULL;
}

