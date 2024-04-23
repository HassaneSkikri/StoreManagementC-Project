class Article
{
private:
    string name;
    string marque;
    double PU; // PU: prix unitaire 
public:
    Article();
    Article(string, string, double);
    string getname();
    string getmarque();
    double getPU();
    void setnom(string nom);
    void setmarque(string marque);
    void setPU(double PU);
    virtual string getCategorie();
    friend ostream& operator<<(ostream& flux, const Article& a);
};