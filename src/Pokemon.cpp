#include "../include/Pokemon.h"
#include "../include/Joueur.h"
#include <iostream>

#include <string>

using namespace std;
        

Pokemon::Pokemon(Joueur *joueur, string nom) : m_nom(nom), m_vie(100), m_attaque(20), m_joueur(joueur), m_isKo(false){
}
Pokemon::Pokemon(string nom) : m_nom(nom), m_vie(100), m_attaque(25), m_joueur(0), m_isKo(false){
}

void Pokemon::attaquer(Pokemon &cible){
    cout << m_nom << " attaque et inflige " << m_attaque << endl;
    cible.recevoirDegats(m_attaque);
}

void Pokemon::recevoirDegats(int degats){
    m_vie -= degats;

    if (m_vie <= 0){
        m_vie = 0;
        m_isKo = true;
        cout << m_nom << " est mort" << endl;
         if (m_joueur != 0){
        m_joueur->setPokeActu();
    }
    }
    else {
        cout << m_nom << " a " << m_vie << " point de vie." << endl;
    }

   
    
}

void Pokemon::choisirAttaque(Pokemon &cible){
    attaquer(cible);
}




string Pokemon::getNom(){
    return m_nom;
}

void Pokemon::setJoueur(Joueur* joueur){
    m_joueur = joueur;
}

Joueur* Pokemon::getJoueur(){
    return m_joueur;
}

bool Pokemon::getKo(){
    return m_isKo;
}

void Pokemon::setKo(bool isKo){
    m_isKo = isKo;
}

int Pokemon::getVie() {
    return m_vie;
}