#include "RendezVous.h"
#include"ZoneSaisie.h"



RendezVous::RendezVous()
{
}

RendezVous::RendezVous(RendezVous & other)
{
}


RendezVous::~RendezVous()
{
}

void RendezVous::setTitle(const char * title)
{
	m_Title.setTitle(title);
}

void RendezVous::setDateDebut(int day, int month, int year)
{
	DateDebut.setDay(day);
	DateDebut.setMonth(month);
	DateDebut.setYear(year);
}

void RendezVous::setDateFin(int day, int month, int year)
{
	DateFin.setDay(day);
	DateFin.setMonth(month);
	DateFin.setYear(year);
}

void RendezVous::setRemark(const char * remark)
{
	Remark = remark;
}

const char * RendezVous::getTitle()
{
	return m_Title.getTitle();
}

const char * RendezVous::getDateDebut()
{
	return DateDebut.getDate();
}

const char * RendezVous::getDateFin()
{
	return DateFin.getDate();
}

const char * RendezVous::getRemark()
{
	return Remark.getText();
}

unsigned long RendezVous::getID()
{
	return ID.getPrimaryKey();
}

unsigned long RendezVous::getAlive()
{
	return ID.getAlive();
}

void RendezVous::Display(std::ostream & stream)
{
	stream << "ID:" << getID() << endl;
	stream << "Date de debut: " << getDateDebut() << endl;
	stream << "Date de fin: " << getDateFin() << endl;
	stream << "Requarque: " << getRemark() << endl;
}

void RendezVous::Encode()
{
	ZoneSaisie zs;
	cout << "ID:" << getID() << endl;
	cout << "Date de debut: " << endl;
	DateDebut.Encode();
	cout << "Date de fin: " << endl;
	DateFin.Encode();
	cout << "Requarque: " << endl;
	if (zs.Ask()) Remark.setText(zs.ValString());
}

RendezVous & RendezVous::operator=(RendezVous & other)
{
	if (this == &other) return *this;
	DateDebut = other.DateDebut;
	DateFin = other.DateFin;
	Remark = other.Remark;
	return *this;
}

ostream & operator<<(ostream & stream, RendezVous & other)
{
	other.Display(stream);
	return stream;
}
