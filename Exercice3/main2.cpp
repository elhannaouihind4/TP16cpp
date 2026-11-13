
#include <iostream>
#include <vector>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(float valeur) = 0;

    virtual ~Observateur() {}
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float valeur) override {
        cout << "Temperature : " << valeur << " C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float valeur) override {
        cout << "Humidite : " << valeur << " %" << endl;
    }
};

class StationMeteo {
private:
    float temperature;
    float humidite;

    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    void notifierObservateurs() {
        for (Observateur* o : observateurs) {
            o->mettreAJour(temperature);
        }
    }

    void setTemperature(float t) {
        temperature = t;
        notifierObservateurs();
    }
};

int main() {

    StationMeteo station;

    AffichageTemperature affichageT;
    AffichageHumidite affichageH;

    station.ajouterObservateur(&affichageT);
    station.ajouterObservateur(&affichageH);

    station.setTemperature(25);

    return 0;
}


