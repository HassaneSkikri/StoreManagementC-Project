#include "entete.h"
//---------------------------------------------------------------

Electromenage::Electromenage()
{
	puissance = 0;
}
//---------------------------------------------------------------

Electromenage::Electromenage(string nom, string marque, double prix_unitaire, int puissance) :Article(nom, marque, prix_unitaire)
{
	puissance = puissance;
}
//---------------------------------------------------------------

int Electromenage::getPuissance()
{
	return puissance;
}

void Electromenage::setPuissance(int p)
{
	puissance = p;
}
//---------------------------------------------------------------

string Electromenage::getCategorie()
{
	return "Electromenage";
}
//---------------------------------------------------------------

ostream& operator<<(ostream& flux, const Electromenage& e)
{
	const Article& art = e;
	flux << art << "puissance" << e.puissance << endl;
	return flux;
}
