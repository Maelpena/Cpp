#include "../include/Joueur.h"
#include "../include/Pokemon.h"
#include "../include/Bulbizarre.h"
#include <algorithm>

#include <iostream>

#include <string>

using namespace std;

Joueur::Joueur(string nom){
    m_nom = nom;
    Bulbizarre* premierPokemon = new Bulbizarre(this);
    Bulbizarre* deuxiemePokemon = new Bulbizarre(this);
    m_equipe.push_back(premierPokemon);
    m_pokemon.push_back(premierPokemon);
    m_pokemon.push_back(deuxiemePokemon);
    m_pokeActu = m_equipe[0];
}

void Joueur::capturerPokemon(Bulbizarre* pokemon){
    m_pokemon.push_back(pokemon);
    pokemon->setJoueur(this);
    cout << "Vous avez capture " << pokemon->getNom() << " !" << endl;


}

void Joueur::voirPokemon(){
    cout << "Voici vos pokemon : " << endl;
    for (int i = 0; i < m_pokemon.size(); i++)
    {
        cout << i << ") ";
        cout << m_pokemon[i]->getNom() << endl;
    }
    menu();
}

void Joueur::choisirEquipe(){
    cout << "Vous avez : " << endl;
    for (int i = 0; i < m_pokemon.size(); i++)
    {
        cout << i << ") ";
        cout << m_pokemon[i]->getNom() << endl;
    }
    while (m_equipe.size() < 6) {
        int numero;

        cout << "Tapez le numero d'un pokemon pour l'ajouter à votre equipe, tapez 99 pour sauvegarder" << endl;
        cin >> numero;
        if (numero == 99){
            break;
        }
        if (find(m_equipe.begin(), m_equipe.end(), m_pokemon[numero] ) != m_equipe.end()){
            cout << "Vous avez deja ce pokemon dans votre equipe" << endl;
        }
        else {
            m_equipe.push_back(m_pokemon[numero]);

            cout << m_pokemon[numero]->getNom() << " vient d'etre ajoute a votre equipe !" << endl;
        }
    
    }
    cout << "voici votre equipe :" << endl;
    for (int i = 0; i < m_equipe.size(); i++)
    {
        cout << m_equipe[i]->getNom() << " " << m_equipe[i]->getVie() << " HP" << endl;
    }
    menu();

}

void Joueur::combattre(){
    Bulbizarre* adversaire = new Bulbizarre();
    commencerCombat(this, adversaire);
    menu();
}

void Joueur::menu(){
    int choix;
    cout << "1) Voir vos pokemon" << endl;
    cout << "2) Choisir votre equipe" << endl;
    cout << "3) Faire un combat" << endl;
    cin >> choix;
    switch (choix) {
        case 1: voirPokemon();
                break;
        case 2: choisirEquipe();
                break;
        case 3: combattre();
                break;
        default: cout << "Vous devez entrer 1, 2 ou 3" << endl;
                 menu();
                 break;
    }
    
}



string Joueur::getNom() {
    return m_nom;
}

Bulbizarre* Joueur::getPokemon(int i){
    return m_equipe[i];
}

vector<Bulbizarre*> Joueur::getEquipe(){
    return m_equipe;
}

void Joueur::setPokeActu(){

    cout << "voici votre equipe :" << endl;
    for (int i = 0; i < m_equipe.size(); i++)
    {
        cout << i << ") ";
        if (m_equipe[i]->getKo()){
            cout << m_equipe[i]->getNom() << " (ko)" << endl;
        }
        else {
            cout << m_equipe[i]->getNom() << " " << m_equipe[i]->getVie() << " HP" << endl;
        }

    }
    cout << "Tapez le numero du pokemon que vous souhaitez faire attaquer " << endl;
    int numero;
    cin >> numero;
    m_pokeActu = m_equipe[numero];
     
}

void Joueur::commencerCombat(Joueur* moi, Bulbizarre* adversaire){
    while (adversaire->getKo() == false && adversaire->getJoueur()==0){
        adversaire->attaquer(*m_pokeActu);

        int choix;
        cout << "1) Attaquer le pokemon adverse" << endl;
        cout << "2) Lancer une pokeball pour capturer le pokemon adverse" << endl;
        cout << "3) Changer de pokemon" << endl;
        cin >> choix;
        switch (choix) {
            case 1: m_pokeActu->choisirAttaque(*adversaire);
                    break;
            case 2: capturerPokemon(adversaire);
                    break;
            case 3: setPokeActu();
                    break;
            default: cout << "Vous devez entrer 1, 2 ou 3" << endl;
                    m_pokeActu->attaquer(*adversaire);
                    break;
        }
    }
}

