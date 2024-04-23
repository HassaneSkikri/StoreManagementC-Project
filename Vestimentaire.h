class Vestimentaire : public Article
{

private:

    string taille;
    string couleur;

public:

    Vestimentaire();
    Vestimentaire(string nom, string marque, double prix_unitaire,string taille,string couleur);

    friend ostream& operator<<(ostream& flux, const Vestimentaire& v);

    string getCategorie() override;

};
