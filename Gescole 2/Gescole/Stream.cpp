#include "Stream.h"



Stream::Stream()
{
	std::string requete = R"(Select * from client;)";
	sql.Select(requete);
	//sql.Display();

}


Stream::~Stream()
{
}
