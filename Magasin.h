class Magasin
{
private:

    Article** depot;
    int size;

public:

    Magasin();
    ~Magasin();

    int getDepotSize();
    void setDepotSize(int s);


    Article** getDepot() const;

    void ajouterArticle(Article* article);

    void afficherParCategorie(const string& categorie);
    void afficherTous();

    void supprimerArticle(string name);

    void MenuMagasin(Magasin& magasin);
};

