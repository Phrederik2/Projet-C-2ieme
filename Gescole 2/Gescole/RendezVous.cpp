#include "RendezVous.h"
#include"ZoneSaisie.h"



RendezVous::RendezVous()
{
	setTitle("Rendez-vous");
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

void RendezVous::setID(int id)
{
	ID.setPrimaryKey(id);
}

void RendezVous::setDateDebut(int day, int month, int year)
{
	DateDebut.setDay(day);
	DateDebut.setMonth(month);
	DateDebut.setYear(year);
	setDateFin(day, month, year);
}

void RendezVous::setDateDebutYear(int year)
{
	DateDebut.setYear(year);
}

void RendezVous::setDateDebutMonth(int month)
{
	DateDebut.setMonth(month);
}

void RendezVous::setDateDebutDay(int day)
{
	DateDebut.setDay(day);
}

void RendezVous::setDateDebut(const char * date)
{
}

void RendezVous::setDateFin(int day, int month, int year)
{
	DateFin.setDay(day);
	DateFin.setMonth(month);
	DateFin.setYear(year);
}

void RendezVous::setDateFinYear(int year)
{
	DateFin.setYear(year);
}

void RendezVous::setDateFinMonth(int month)
{
	DateFin.setMonth(month);
}

void RendezVous::setDateFinDay(int day)
{
	DateFin.setDay(day);
}

void RendezVous::setDateFin(const char * date)
{
}

Date* RendezVous::setDateDebut()
{
	return DateDebut.setDate();
}

Date* RendezVous::setDateFin()
{
	return DateFin.setDate();
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

int RendezVous::getDateDebutYear()
{
	return DateDebut.getYear();
}

int RendezVous::getDateDebutMonth()
{
	return DateDebut.getMonth();
}

int RendezVous::getDateDebutDay()
{
	return DateDebut.getDay();
}

const char * RendezVous::getDateFin()
{
	return DateFin.getDate();
}

int RendezVous::getDateFinYear()
{
	return DateFin.getYear();
}

int RendezVous::getDateFinMonth()
{
	return DateFin.getMonth();
}

int RendezVous::getDateFinDay()
{
	return DateFin.getDay();
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
