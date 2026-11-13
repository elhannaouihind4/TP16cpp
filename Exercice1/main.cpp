
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    Configuration() {
        cheminFichier = "config.txt";
        utilisateur = "Hind";
        motDePasse = "6753";
    }

public:
    Configuration(const Configuration&) = delete;

    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void afficherParametres() {
        cout << "Chemin : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

int main() {

    Configuration& c1 = Configuration::getInstance();
    Configuration& c2 = Configuration::getInstance();

    c1.afficherParametres();

    if (&c1 == &c2) {
        cout << "Meme instance !" << endl;
    }

    return 0;
}
