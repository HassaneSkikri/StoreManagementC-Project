#include "entete.h"

//-----------------------------------------------------

Alimentaire::Alimentaire()
{
	this->expiration_date = Date();
}

Alimentaire::Alimentaire(string nom, string marque, double prix_unitaire, const Date& expiration_date)
    : Article(nom, marque, prix_unitaire)
{
    this->expiration_date = expiration_date;
}
//-----------------------------------------------------

string Alimentaire::getCategorie()  {
    return "Alimentaire"; 
}
//-----------------------------------------------------

ostream& operator<<(ostream& flux, const Alimentaire& a)
{
    const Article& art = a;
    flux << art << "Date experation:" << a.expiration_date << endl;
    return flux;
}                      
