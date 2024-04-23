class Electromenage :public Article
{
private:

	int puissance;

public:

	Electromenage();
	Electromenage(string nom, string marque,double prix_unitaire, int puissance);
	
	int  getPuissance();
	void setPuissance(int p);

	friend ostream& operator << (ostream& flux, const Electromenage& e);

	string getCategorie() override;

};

