#include "Text.h"
#include<iostream>
#include<cstring>
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

ostream &  operator<<(ostream& COUT, Text & other)
{
	COUT << other.getText();
	return COUT;
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
