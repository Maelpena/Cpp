#include "../include/Bulbizarre.h"
#include <iostream>

#include <string>

using namespace std;

Bulbizarre::Bulbizarre(Joueur *joueur) : Pokemon(joueur, "Bulbizarre"){

}
Bulbizarre::Bulbizarre() : Pokemon("Bulbizarre"){

}


void Bulbizarre::charge(Pokemon &cible){
    cout << m_nom << " Attaque charge ! et inflige 20 point de degats !" << endl;
    cible.recevoirDegats(20);
}

void Bulbizarre::trancheHerbe(Pokemon &cible){
    cout << m_nom << " Attaque tranch' herbe ! et inflige 30 point de degats !" << endl;
    cible.recevoirDegats(30);
}

void Bulbizarre::choisirAttaque(Pokemon &cible){
    cout << "Attaque de " << m_nom << " :" << endl;
    cout << "1) Charge" << endl;
    cout << "2) Tranch' Herbe" << endl;
    int choix;
    cin >> choix;
    switch (choix) {
        case 1: charge(cible);
                break;
        case 2: trancheHerbe(cible);
                break;
        default: cout << "Vous devez entrer 1 ou 2" << endl;
                 charge(cible);
                 break;
    }
}