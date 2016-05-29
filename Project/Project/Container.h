#pragma once
#include<vector>
using namespace std;

template<class ENTITY>
class Container
{
protected:
	static Container<ENTITY>* IdOwner;
	typename vector<ENTITY*> m_Container;
	typename vector<ENTITY*>::iterator m_It;

public:
	Container<ENTITY>* operator=(Container<ENTITY>* other);
	Container(Container<ENTITY>* other);
	Container();
	~Container();
	ENTITY* Add(ENTITY* other);
	ENTITY* First();
	ENTITY* Previous();
	ENTITY* Next();
	ENTITY* Last();
	size_t Size();
	void Duplication(Container<ENTITY>* other);
	ENTITY* Find(ENTITY* other);
	void Flush();
	bool IsOwner();
};

