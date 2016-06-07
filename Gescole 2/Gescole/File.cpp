#include <fstream>
#include <ios>
#include "File.h"

File::File(const std::string & path)
{
	this->Path = path;
	this->Position = 0;
}

bool File::OpenInput(const std::string & path)
{
	this->Input.open(path);
	return this->Input.good();
}

bool File::OpenOutput(const std::string & path)
{
	this->Output.open(path);
	return this->Output.good();
}

bool File::OpenOutput(const std::string & path, bool append)
{
	if (append)
		this->Output.open(path, std::fstream::app);
	else
		return this->OpenOutput(path);
	return this->Output.good();
}

void File::CloseInput()
{
	if (!this->Input.is_open()) return;
	this->Input.close();
}

void File::CloseOutput()
{
	if (!this->Output.is_open()) return;
	this->Output.close();
}

unsigned long File::GetInputLength()
{
	this->Input.seekg(0, this->Input.end);
	unsigned long length = (unsigned long)this->Input.tellg();
	this->Input.seekg(0, this->Input.beg);
	return length;
}

std::string File::ReadInput(unsigned long length)
{
	char * buffer = new char[length + 1];
	memset(buffer, 0, length + 1);

	this->Input.read(buffer, length);
	std::string data(buffer);

	delete[] buffer;

	return data;

}

bool File::Exists(const std::string & path)
{
	struct stat buffer;
	return (!stat(path.c_str(), &buffer));
}

bool File::Remove(const std::string & path)
{
	bool fileExists = File::Exists(path);
	if (fileExists) std::remove(path.c_str());

	return fileExists;
}

std::string File::Read()
{
	std::string data;

	if (this->OpenInput(this->Path))
		data = this->ReadInput(this->GetInputLength());

	this->CloseInput();
	return data;

}

std::string File::ReadLine()
{
	if (!OpenInput(this->Path)) return std::string();
	this->Input.seekg(this->Position);
	if (!this->IsReadable())
	{
		this->CloseInput();
		return std::string();
	}
	std::getline(this->Input, this->Line);
	this->Position = this->Input.tellg();

	this->CloseInput();
	return this->Line;
}

List<std::string> File::ReadLines()
{
	List<std::string> lines;
	std::string line;

	if (this->OpenInput(this->Path))
		while (std::getline(this->Input, line))
			lines.Add(new std::string(line));

	this->CloseInput();
	return lines;
}

bool File::Write(const std::string & data)
{
	bool openSuccess = this->OpenOutput(this->Path);

	if (openSuccess)
		this->Output.write(data.c_str(), data.length());

	this->CloseOutput();
	return openSuccess;
}

bool File::WriteLine(const std::string & line)
{
	if (!OpenOutput(this->Path, true)) return false;
	this->Output.write(line.c_str(), line.length());
	this->Output.write("\n", 1);
	this->CloseOutput();
	return true;
}

bool File::WriteLines(List<std::string> & lines)
{
	if (!OpenOutput(this->Path)) return false;

	std::string * line = lines.First();
	while (line)
	{
		this->Output.write(line->c_str(), line->length());
		this->Output.write("\n", 1);
		line = lines.Next();
	}

	this->CloseOutput();
	return true;
}

bool File::InputIsReadable() 
{
	return this->Position != -1;
}

void File::Rewind()
{
	this->Position = 0;
}

bool File::IsReadable() {
	return this->InputIsReadable();
}

std::string File::Read(const std::string & path)
{
	File file(path);
	return file.Read();
}

List<std::string> File::ReadLines(const std::string & path)
{
	File file(path);
	return file.ReadLines();
}

bool File::Write(const std::string & path, const std::string & data)
{
	File file(path);
	return file.Write(data);
}

bool File::WriteLines(const std::string & path, List<std::string> & lines)
{
	File file(path);
	return file.WriteLines(lines);
}
