#pragma once
template<class ENTITY>
class PrimaryKey
{
	static unsigned long Alive;
	static unsigned long Compter;
	unsigned long ID;

public:
	PrimaryKey();
	~PrimaryKey();
	
	void setPrimaryKey(unsigned long primarykey);
	unsigned long getPrimaryKey();
	unsigned long getAlive();
	unsigned long getCompter();
};
template<class ENTITY>
unsigned long PrimaryKey<ENTITY>::Alive = 0;
template<class ENTITY>
unsigned long PrimaryKey<ENTITY>::Compter = 0;

template<class ENTITY>
PrimaryKey<ENTITY>::PrimaryKey()
{
	Alive++;
	Compter++;
	ID = Compter;
}

template<class ENTITY>
PrimaryKey<ENTITY>::~PrimaryKey()
{
	Alive--;
}

template<class ENTITY>
void PrimaryKey<ENTITY>::setPrimaryKey(unsigned long primarykey)
{
	ID = primarykey;
}

template<class ENTITY>
unsigned long PrimaryKey<ENTITY>::getPrimaryKey()
{
	return ID;
}

template<class ENTITY>
unsigned long PrimaryKey<ENTITY>::getAlive()
{
	return Alive;
}

template<class ENTITY>
unsigned long PrimaryKey<ENTITY>::getCompter()
{
	return Compter;
}
