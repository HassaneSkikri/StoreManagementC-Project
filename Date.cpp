#include "entete.h"
//1) constructor withour parameter
Date::Date()
{
	this->jour = 1;
	this->mois = 1;
	this->annee = 2000;
}
//constructor with parameter
Date::Date(int j, int m, int a) {
	this->jour = j;
	this->mois = m;
	this->annee = a;
}
// constructeur de copie
Date::Date(const Date& d)
{
	this->jour = d.jour;
	this->mois = d.mois;
	this->annee = d.annee;
}
//affichage
void Date::Affichage() {
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}
//seter and geter
int Date::getjour()
{
	return this->jour;
}

int Date::getmois()
{
	return this->mois;
}

int Date::getannee()
{
	return this->annee;
}

void Date::Setjour(int jour)
{
	this->jour = jour;
}

void Date::Setmois(int mois)
{
	this->mois = mois;
}

void Date::Setannee(int annee)
{
	this->annee = annee;
}

//l'affectation

Date& Date::operator=(const Date& d)
{	
	this->jour = d.jour;
	this->mois= d.mois;
	this->annee= d.annee;
	return *this;
}

//ostream and istream

ostream& operator <<(ostream& flux, const Date& x) {
	flux << x.jour << "/" << x.mois << "/" << x.annee << endl;
	return flux;
}

istream& operator>>(istream& flux, Date& x)
{
	flux >> x.jour >> x.mois >> x.annee;
	return flux;
}
