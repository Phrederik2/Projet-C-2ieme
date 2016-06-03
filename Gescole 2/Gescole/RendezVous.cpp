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

RendezVous & RendezVous::operator=(RendezVous & other)
{
	if (this == &other) return *this;
	DateDebut = other.DateDebut;
	DateFin = other.DateFin;
	Remark = other.Remark;
	return *this;
}
