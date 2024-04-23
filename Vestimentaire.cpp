#include "entete.h"

//-------------------------------------------------------

Vestimentaire::Vestimentaire()
{
	this->couleur = "";
	this->taille = "";
}
//-------------------------------------------------------

Vestimentaire::Vestimentaire(string nom, string marque, double prix_unitaire, string taille, string couleur) : Article(nom,marque,prix_unitaire )
{
	this->couleur = couleur;
	this->taille = taille;
}
//-------------------------------------------------------

string Vestimentaire::getCategorie()
{
	return "Vestimentaire";
}
//-------------------------------------------------------

ostream& operator<<(ostream& flux, const Vestimentaire& v)
{
	const Article& art = v;
	flux << art << "couleur" << v.couleur << "taille" << v.taille<< endl;
	return flux;
}
