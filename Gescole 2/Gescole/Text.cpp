#include "Text.h"
#include<iostream>
#include<string>
using namespace std;

Text::Text(size_t size)
{
	setSize(size);
	m_Text = new char[getSize()];
	memset(m_Text, 0, size * sizeof(char));
	setText("INCONNU");
}

Text::Text(Text& other)
{
	*this = other;
}


Text& Text::operator=(Text& other)
{
	if (&other == this) return *this;
	setSize(other.getSize());
	setText(other.getText());
	return *this;
}

Text & Text::operator=(const char * text)
{
	setText(text);
	return *this;
}

ostream &  operator<<(ostream& COUT, Text & other)
{
	COUT << other.getText();
	return COUT;
}

Text & Text::operator+(const char * other)
{
	strcat(m_Text, other);
	return *this;
}

Text & Text::operator+(unsigned int other)
{
	char text[100];
	sprintf(text,"%d", other);
	*this + text;
	return *this;
}

Text::~Text()
{
	delete m_Text;
}

void Text::setText(const char * text)
{
	strncpy(m_Text, text, getSize());
}

const char * Text::getText()
{
	return m_Text;
}

void Text::setSize(size_t size)
{
	m_Size = size;
}

size_t Text::getSize()
{
	return m_Size;
}
