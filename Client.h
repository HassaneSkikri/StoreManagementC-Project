class Client {
public:

    Client();
    ~Client();

    int getPanierSize();
    void setPanierSize(int s);

    void AffArDispCategorie(const string& categorie, Magasin& magasin);
    void AffTousAr(Magasin& magasin);

    void ajouterArticle(Article* article);
    void supprimerArticle(string nom);

    void viderPanier();
    double MontantTotal();
    void menuClient(Magasin& magasin, Client& client);
private:

    Article** panier;
    int size;
};