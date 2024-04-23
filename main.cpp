#include "entete.h"


int main()
{
    Magasin magasin;
    Client client;

    magasin.ajouterArticle(new Alimentaire("hassane", "MarqueA", 2.5, Date(1, 1, 2003)));
    magasin.ajouterArticle(new Vestimentaire("skikri", "MarqueB", 59.0, "M", "Noir"));
    magasin.ajouterArticle(new Electromenage("mohamed", "MarqueC", 999.99, 99));

    int utilisateur;
    cout << "etes-vous : \n-->le gerant : 1\n-->un client : 2"<<endl;
    cin >> utilisateur;

    if (utilisateur == 1)
    {
        magasin.MenuMagasin(magasin);
    }
    else if (utilisateur == 2)
    {
        client.menuClient(magasin, client);
    }
    else
    {
        cout << "Choix invalide." << endl;
    }
}