
#include "DropdownList.h"
class Livraison :
	public DropdownList
{
protected:
	PrimaryKey<Livraison> ID;
public:
	Livraison();
	~Livraison();
};
