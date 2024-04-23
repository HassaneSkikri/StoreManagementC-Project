#include "entete.h"
//--------------------------------------------------------
Article::Article()
{
	name = "";
	marque = "";
	PU = 0;
}
//--------------------------------------------------------
Article::Article(string n, string m, double pu) {
	this->name = n;
	this->marque = m;
	this->PU = pu;
}
//--------------------------------------------------------
string Article::getname()
{
	return this->name;
}
string Article::getmarque()
{
	return this->marque;
}
double Article::getPU()
{
	return this->PU;
}
void Article::setnom(string nom)
{
	this->name = nom;
}
void Article::setmarque(string marque)
{
	this->marque = marque;
}
void Article::setPU(double PU)
{
	this->PU = PU;
}
//--------------------------------------------------------
string Article::getCategorie()
{
	return "NULL";
}
ostream& operator<<(ostream& flux, const Article& a)
{
	flux << "nom:" << a.name << "marque:" << a.marque << "prix unitaire:" << a.PU << endl;
	return flux;
}
