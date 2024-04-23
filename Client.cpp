#include "entete.h"

//--------------------------------------------------------------------

Client::Client() {
    this->size = 0;
    this->panier = new Article* [MaxArticle];
}
//--------------------------------------------------------------------

Client::~Client() {
    //for (int i = 0; i < size; ++i) {
    //    delete panier[i];
    //}
    //delete[] panier;
}
//--------------------------------------------------------------------

int Client::getPanierSize()
{
    return size;
}

void Client::setPanierSize(int s)
{
    this->size = s;
}

//--------------------------------------------------------------------
//1)


void Client::AffArDispCategorie(const std::string& categorie, Magasin& magasin) {
    magasin.afficherParCategorie(categorie);
}
//--------------------------------------------------------------------
//2)


void Client::AffTousAr(Magasin& magasin) {
    magasin.afficherTous();
}
//--------------------------------------------------------------------
//3)


void Client::ajouterArticle(Article* article) {
    if (size < MaxArticle) {
        panier[size++] = article;
    }
    else {
        cout << "je suis desole, le Panier est plein." << endl;
    }
}
//--------------------------------------------------------------------
//4)


void Client::supprimerArticle(string  nom) {
    for (int i = 0; i < size; i++) {
        if (panier[i]->getname() == nom) {
            delete panier[i];
            for (int j = i; j < size - 1; j++) {
                panier[j] = panier[j + 1];
            }
            size--;
            break;
        }
    }
}
//--------------------------------------------------------------------
//5)


void Client::viderPanier() {
    for (int i = 0; i < size; ++i) {
        delete panier[i];
    }
    size = 0;
}
//--------------------------------------------------------------------
//6)


double Client::MontantTotal() {
    double montantTotal = 0.0;
    for (int i = 0; i < size; ++i) {
        montantTotal += panier[i]->getPU();
    }
    return montantTotal;
}
//--------------------------------------------------------------------
//7)

void Client::menuClient(Magasin& magasin, Client& client)
{
    int besoin;
    do
    {


        cout << "<<----------------Menu------------------->>" << endl;
        cout << "<<Bonjour>>" << endl;
        cout << "1 - Afficher les articles par categorie" << endl;
        cout << "2 - Afficher tous les articles" << endl;
        cout << "3 - Ajouter un article au panier" << endl;
        cout << "4 - Supprimer un article du panier" << endl;
        cout << "5 - Vider le panier" << endl;
        cout << "6 - Calculer le montant total du panier" << endl;
        cout << "7 - Quitter le programme" << endl;
        cout << "entrer vote besoin : ";
        cin >> besoin;

        switch (besoin)
        {
        case 1:
        {
            string categorie;
            cout << "entrer la categorie ce aue tu veut : ";
            cin >> categorie;
            client.AffArDispCategorie(categorie, magasin);
            break;
        }
        case 2:
            client.AffTousAr(magasin);
            break;
        case 3:
        {
            string nom;
            cout << "entrer le nom de l article a  ajouter au panier : ";
            cin >> nom;

            Article* article = nullptr;
            for (int i = 0; i < magasin.getDepotSize(); i++)
            {
                if (magasin.getDepot()[i]->getname() == nom)
                {
                    article = magasin.getDepot()[i];
                    break;
                }
            }

            if (article)
            {
                client.ajouterArticle(article);
                cout << "Article a ete ajoute au panier." << endl;
            }
            else
            {
                cout << "Article n existe pas." << endl;
            }
            break;
        }
        case 4:
        {
            string nom;
            cout << "entrer le nom de l article a  supprime du panier : ";
            cin >> nom;
            client.supprimerArticle(nom);
            break;
        }
        case 5:
            client.viderPanier();
            break;
        case 6:
        {
            double montantTotal = client.MontantTotal();
            cout << "Montant total du panier : " << montantTotal << endl;
            break;
        }
        case 7:
            cout << "programme est fini." << endl;
            break;
        default:
            cout << "ce commande est introvable." << endl;
        }
    } while (besoin != 7);
}

