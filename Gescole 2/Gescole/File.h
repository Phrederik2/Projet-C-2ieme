#pragma once
#include <string>
#include<fstream>
#include"List.h"

using namespace std;

class File
{
protected:
	string Path;
	streamoff Position;
	streamoff EndOfFile;
	string CurrentLine;
	ifstream Input;
	ofstream Output;
	

protected:
	bool OpenIN();
	bool OpenOUT();
	void LastPosition();
	void RegisterCurrentPosition();
	void Close();
	void Initialize(string path);

public:
	File(string path = "");
	File(File& other);
	File& operator= (File& other);

	string Read();
	bool RecoverNextLine();
	string getCurrentLine();
	void WriteLine(string line);
	void Empty();

	static List<string>& ReadLines(string path = "");
	static void Write(List<string>& list, bool emptyfile = false, string path = "");

	
};

