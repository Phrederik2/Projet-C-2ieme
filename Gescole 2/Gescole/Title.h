#pragma once
#include<iostream>

template <class ENTITY>
class Title
{
protected:
	static char m_Title[100];
public:
	Title();
	~Title();
	void setTitle(const char* title);
	const char* getTitle();
};

template <class ENTITY>
char Title<ENTITY>::m_Title[100] = "Adresse";

template <class ENTITY>
Title<ENTITY>::Title()
{
}

template <class ENTITY>
Title<ENTITY>::~Title()
{
}

template<class ENTITY>
 void Title<ENTITY>::setTitle(const char * title)
{
	strncpy_s(m_Title, title, 100);
}

template<class ENTITY>
const char * Title<ENTITY>::getTitle()
{
	return m_Title;
}
