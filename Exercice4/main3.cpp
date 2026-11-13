
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StrategieTri {
public:
    virtual void trier(vector<string>& v) = 0;
    virtual ~StrategieTri() {}
};

class TriCroissant : public StrategieTri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end(), greater<string>());
    }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end(),
            [](string a, string b) {
                return a.length() < b.length();
            });
    }
};

class GestionnaireTri {
private:
    StrategieTri* strategie;

public:
    GestionnaireTri(StrategieTri* s) {
        strategie = s;
    }

    void changerStrategie(StrategieTri* s) {
        strategie = s;
    }

    void executerTri(vector<string>& v) {
        strategie->trier(v);
    }
};

int main() {

    vector<string> mots = {"Pomme", "Banane", "Orange", "Limon"};

    TriCroissant croissant;
    TriDecroissant decroissant;
    TriParLongueur longueur;

    GestionnaireTri gestionnaire(&croissant);

    gestionnaire.executerTri(mots);

    cout << "Tri croissant : ";
    for (string m : mots)
        cout << m << " ";
    cout << endl;

    gestionnaire.changerStrategie(&decroissant);
    gestionnaire.executerTri(mots);

    cout << "Tri decroissant : ";
    for (string m : mots)
        cout << m << " ";
    cout << endl;

    gestionnaire.changerStrategie(&longueur);
    gestionnaire.executerTri(mots);

    cout << "Tri par longueur : ";
    for (string m : mots)
        cout << m << " ";
    cout << endl;

    return 0;
}
