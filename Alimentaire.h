class Alimentaire : public Article
{
private:

	Date expiration_date;

public:

	Alimentaire();
	Alimentaire(string nom, string marque, double  prix_unitaire, const Date& date_expiration);

	friend ostream& operator <<(ostream& flux, const Alimentaire& a);

	string getCategorie() override ;

};

