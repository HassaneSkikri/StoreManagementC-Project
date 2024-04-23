class Date
{
private:
	int jour;
	int mois;
	int annee;
public:
	Date();
	Date(const Date& d);
	Date(int h, int m, int annee);
	void Affichage();
	int getjour();
	int getmois();
	int getannee();
	void Setjour(int);
	void Setmois(int);
	void Setannee(int);
	Date& operator= (const Date& d);
	friend ostream& operator <<(ostream& flux, const Date& x);
	friend istream& operator>>(istream& flux, Date& x);
};

