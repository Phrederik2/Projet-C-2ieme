#pragma once
#include <string>
#include <fstream>
#include "List.h"

class File
{
private:
	std::ifstream Input;
	std::ofstream Output;
	std::string Line;
	std::string Path;
	std::streamoff Position;

	bool OpenInput(const std::string & path);
	bool OpenOutput(const std::string & path);
	bool OpenOutput(const std::string & path, bool append);
	void CloseInput();
	void CloseOutput();

	unsigned long GetInputLength();
	std::string ReadInput(unsigned long length);
	bool InputIsReadable();

public:
	File(const std::string & path);

	static bool Exists(const std::string & path);
	static bool Remove(const std::string & path);

	std::string Read();
	std::string ReadLine();
	List<std::string> ReadLines();
	bool Write(const std::string & data);
	bool WriteLine(const std::string & line);
	bool WriteLines(List<std::string> & lines);
	bool IsReadable();
	void Rewind();

	static std::string Read(const std::string & path);
	static List<std::string> ReadLines(const std::string & path);
	static bool Write(const std::string & path, const std::string & data);
	static bool WriteLines(const std::string & path, List<std::string> & lines);
	
};