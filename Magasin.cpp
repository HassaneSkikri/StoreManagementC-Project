#include "entete.h"

//-----------------------------------------------------------------------------

Magasin::Magasin()
{
	this->depot = new Article * [MaxArticle];
    this->size = 0;
}
//-----------------------------------------------------------------------------

Magasin::~Magasin()
{
    for (int i = 0; i < size; i++)
    {
        delete depot[i];
    }
    delete[] depot;
}
//-----------------------------------------------------------------------------

int Magasin::getDepotSize()
{
    return size;
}

void Magasin::setDepotSize(int s)
{
    this->size = s;
}

Article** Magasin::getDepot() const{
    return depot;
}
//-----------------------------------------------------------------------------
//1)


void Magasin::ajouterArticle(Article* article)
{
    if (size < MaxArticle)
    {
        depot[size++] = article;
    }
    else
    {
        cout << "il n a pas d espace, le depot est plein." << endl;
    }
}
//-----------------------------------------------------------------------------
//2)


void Magasin::afficherParCategorie(const string& categorie)
{
    for (int i = 0; i < size; ++i)
    {
        if (depot[i]->getCategorie() == categorie)
        {
            cout << "\n-->Nom : " << depot[i]->getname()
                << " \n-->Marque : " << depot[i]->getmarque()
                << " \n-->Prix unitaire : " << depot[i]->getPU() << endl;
        }
    }
}
//-----------------------------------------------------------------------------
//3)


void Magasin::afficherTous()
{
    for (int i = 0; i < size; ++i)
    {
        cout << "\n-->Nom : " << depot[i]->getname()
            << " \n-->Marque : " << depot[i]->getmarque()
            << " \n-->Prix unitaire : " << depot[i]->getPU() << endl;
    }
}
//-----------------------------------------------------------------------------
//4)

void Magasin::supprimerArticle(string nom)
{
    for (int i = 0; i < size; i++)
    {
        if (depot[i]->getname() == nom)
        {
            delete depot[i];
            for (int j = i; j < size - 1; j++)
            {
                depot[j] = depot[j + 1];
            }
            size--;
            break;
        }
    }
}

//-----------------------------------------------------------------------------
//5)                                    Menu


void Magasin::MenuMagasin(Magasin& magasin)
{
    int besoin;

    do
    {
        cout << "Bonjour dans notre Magasin :" << endl;
        cout << "Menu du Magasin est :" << endl;
        cout << "-->1 - Ajouter un nouvel article" << endl;
        cout << "-->2 - Afficher les articles par categorie" << endl;
        cout << "-->3 - Afficher tous les articles" << endl;
        cout << "-->4 - Supprimer un article" << endl;
        cout << "-->5 - Quitter le programme" << endl;

        cout << "entrer votre choix : ";
        cin >> besoin;

        switch (besoin)
        {
        case 1:
        {
            string nom,
                   marque,
                   categorie;
            double prix_unitaire;

            cout << "<<---------------Aricle----------------->>" << endl;
            cout << "Nom: ";
            cin >> nom;
            cout << "Marque : ";
            cin >> marque;
            cout << "Prix unitaire : ";
            cin >> prix_unitaire;
            cout << "entrer la Categorie :" << endl;
            cout << "A : Alimentaire\nE: Electromenager\nV: Vestimentaire :" << endl;
            cin >> categorie;

            if (categorie == "A")
            {
                int jour, mois, annee;
                cout << "Date d_expiration j/m/a est : ";
                cin >> jour >> mois >> annee;
                const Date date_expiration(jour, mois, annee);
                magasin.ajouterArticle(new Alimentaire(nom, marque, prix_unitaire, date_expiration));
            }
            else if (categorie == "E")
            {
                int puissance;
                cout << "Puissance : ";
                cin >> puissance;
                magasin.ajouterArticle(new Electromenage(nom, marque, prix_unitaire, puissance));
            }
            else if (categorie == "V")
            {
                string taille, couleur;
                cout << "Taille : ";
                cin >> taille;
                cout << "Couleur : ";
                cin >> couleur;
                magasin.ajouterArticle(new Vestimentaire(nom, marque, prix_unitaire, taille, couleur));
            }
            else
            {
                cout << "Categorie n existe pas " << endl;
            }
            break;
        }
        case 2:
        {
            string categorie;
            cout << "entrer la categorie ce que tu veut: ";
            cin >> categorie;
            magasin.afficherParCategorie(categorie);
            break;
        }


        case 3:
        {
            cout << "Afficher tous les articles: ";
            magasin.afficherTous();
            break;
        }
        case 4:
        {
            string nom;
            cout << "entrer le nom de l article a supprimer : ";
            cin >> nom;
            magasin.supprimerArticle(nom);
            break;
        }


        case 5:
        {
            cout << "programme est fini." << endl;
            break;
        }

        default:
            cout << "cette commande est introvable." << endl;
        }
    } while (besoin != 5);
}
