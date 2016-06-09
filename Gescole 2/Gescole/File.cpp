#include "File.h"
#include<iostream>

using namespace std;

bool File::OpenIN()
{
	
	bool Value = 0;
	Input.open(this->Path);

	if (!Input.good())
	{
		cout << "Le fichier '" << this->Path << "' n'existe pas!" << endl;
		cout << "Aucune fonction de lecture ne peux etre utilisee" << endl;

		std::cout << " good()=" << Input.good() << endl;
		std::cout << " eof()=" << Input.eof() << endl;
		std::cout << " fail()=" << Input.fail() << endl;
		std::cout << " bad()=" << Input.bad() << endl;
		return Value;
	}
	Value = Input.good();
	Input.clear();
	return Value;

}
bool File::OpenOUT()
{
	bool Value=0;
	
	Output.open(Path, ios_base::app);
	if (!Output.good())
	{
		cout << "Le fichier '" << Path << "' ne peux pas etre cree!" << endl;
		cout << "Aucune fonction d'ecriture ne peux etre utilisee" << endl;
		return Value;
	}

	Value = Output.good();
	Output.clear();
	return Value;
}
void File::Empty()
{
	if (Output.good())
	{
		Output.open(Path, ios_base::trunc);
		if (!Output.good())
		{
			return;
		}

		Output.clear();
		Close();
	}
	
}
void File::LastPosition()
{
	Input.seekg(ios_base::beg + this->Position);
}
void File::RegisterCurrentPosition()
{
	this->Position = Input.tellg();
	if (this->Position == -1) this->Position = this->EndOfFile;
}
void File::Close()
{
	Input.close();
	Output.close();
}
void File::Initialize(string path)
{
	this->Position = 0;
	this->Path = path;
	OpenIN();
	Input.seekg(0, ios_base::end);
	this->EndOfFile = Input.tellg();
	Close();
	OpenOUT();
	Close();
}
File::File(string path)
{
	
	if (path.size()) Initialize(path);
	else
	{
		string path;
		int begin = 0, end = 0;
		getline(cin, path);
		begin = path.find_first_of('\"') + 1;
		end = path.find_last_of('\"') - 1;
		cout << "Path:" << endl;
		cout << path.substr(begin, end) << endl;

		Initialize(path.substr(begin, end));
	}
	
}
File::File(File & other)
{
	*this = other;
}
File & File::operator=(File & other)
{
	if (this == &other) return *this;

	this->Position = other.Position;
	this->EndOfFile = other.EndOfFile;
	this->CurrentLine = other.CurrentLine;

	return *this;
}
string File::Read()
{
	char* buffeur = new char[this->EndOfFile + 1];
	memset(buffeur, 0, sizeof buffeur);
	OpenIN();

	Input.read(buffeur, this->EndOfFile);

	Close();
	string data(buffeur);
	delete[] buffeur;
	return data;
}
bool File::RecoverNextLine()
{
	if (OpenIN() && (this->Position < this->EndOfFile))
	{
		LastPosition();
		getline(Input, this->CurrentLine);
		RegisterCurrentPosition();
		
		Close();
		return true;
	}
	
	return false;
}
string File::getCurrentLine()
{
	return this->CurrentLine;
}
void File::WriteLine(string line)
{
	if (Output.good())
	{
		OpenOUT();
		Output << line << endl;
		Close();
	}
}
List<string>& File::ReadLines(string path)
{
	File file(path);
	List<string>* list;
	list = new List<string>;

	while (file.RecoverNextLine())
	{
		list->Add(new string(file.getCurrentLine()));
	}

	return *list;
}
void File::Write(List<string>& list, bool emptyfile, string path)
{
	File file(path);

	if (emptyfile) file.Empty();

	list.First();

	do
	{
		file.WriteLine(*list.GetCurrent());
	} while (list.Next());


}
