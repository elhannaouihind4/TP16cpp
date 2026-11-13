
#include <iostream>
using namespace std;

class Forme {
public:
    virtual void afficher() = 0;

    virtual ~Forme() {}
};

class Cercle : public Forme {
public:
    void afficher() override {
        cout << "Je suis un Cercle" << endl;
    }
};

class Carre : public Forme {
public:
    void afficher() override {
        cout << "Je suis un Carre" << endl;
    }
};

class Triangle : public Forme {
public:
    void afficher() override {
        cout << "Je suis un Triangle" << endl;
    }
};

class FabriqueForme {
public:
    static Forme* creerForme(string type) {

        if (type == "cercle") {
            return new Cercle();
        }
        else if (type == "carre") {
            return new Carre();
        }
        else if (type == "triangle") {
            return new Triangle();
        }
        else {
            return nullptr;
        }
    }
};

int main() {

    Forme* f1 = FabriqueForme::creerForme("cercle");
    Forme* f2 = FabriqueForme::creerForme("carre");
    Forme* f3 = FabriqueForme::creerForme("triangle");

    if (f1 != nullptr) f1->afficher();
    if (f2 != nullptr) f2->afficher();
    if (f3 != nullptr) f3->afficher();

    delete f1;
    delete f2;
    delete f3;

    return 0;
}



