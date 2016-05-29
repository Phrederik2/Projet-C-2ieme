#pragma once
#include "Container.h"

template<class ENTITY>
Container<ENTITY>* Container<ENTITY>::IdOwner = NULL;

template<class ENTITY>
Container<ENTITY> * Container<ENTITY>::operator=(Container<ENTITY> * other)
{
	Duplication(other);
	return this;
}

template<class ENTITY>
Container<ENTITY>::Container(Container<ENTITY> * other)
{
	Duplication(other);
}

template<class ENTITY>
Container<ENTITY>::Container()
{
	if (!IdOwner) IdOwner = this;
}

template<class ENTITY>
Container<ENTITY>::~Container()
{
	Flush();
}

template<class ENTITY>
ENTITY* Container<ENTITY>::Add(ENTITY* other)
{
	if (this != IdOwner) IdOwner->Add(other);
	
	if (!Find(other)) m_Container.push_back(other);
	
	return Last();
}

template<class ENTITY>
ENTITY* Container<ENTITY>::First()
{
	if (!m_Container.size()) return NULL;
	m_It = m_Container.begin();
	return *m_It;
}

template<class ENTITY>
ENTITY* Container<ENTITY>::Previous()
{
	if (!m_Container.size()) return NULL;
	if (m_It == m_Container.begin()) return NULL;
	m_It--;
	return *m_It;
}

template<class ENTITY>
ENTITY* Container<ENTITY>::Next()
{
	if (!m_Container.size()) return NULL;
	if (m_It == m_Container.end()-1) return NULL;
	m_It++;
	return *m_It;
}

template<class ENTITY>
ENTITY* Container<ENTITY>::Last()
{
	if (!m_Container.size()) return NULL;
	m_It = m_Container.end() - 1;
	return *m_It;
}

template<class ENTITY>
size_t Container<ENTITY>::Size()
{
	return m_Container.size();
}

template<class ENTITY>
void Container<ENTITY>::Duplication(Container<ENTITY> * other)
{
	if (this == other) return;
	m_Container = other->m_Container;
	m_It = other->m_It;
}

template<class ENTITY>
ENTITY* Container<ENTITY>::Find(ENTITY * other)
{
	
	for (m_It = m_Container.begin(); m_It != m_Container.end(); m_It++)
	{
		if (*m_It == other) return *m_It;
	}

	return NULL;
}

template<class ENTITY>
void Container<ENTITY>::Flush()
{
	if (this == IdOwner)
	{
		First();

		do
		{
			delete *m_It;
		}
		while (Next());

		IdOwner = NULL;
	}

	m_Container.clear();
	
}

template<class ENTITY>
bool Container<ENTITY>::IsOwner()
{
	if (this == IdOwner) return true;

	return false;
}
