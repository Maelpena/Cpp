#ifndef DEF_POKEMON
#define DEF_POKEMON

#include <iostream>
class Joueur;
class Pokemon {
    protected:
        Joueur* m_joueur;
        std::string m_nom;
        int m_vie;
        int m_attaque;
        bool m_isKo;

    public:
        Pokemon(Joueur *joueur, std::string nom);
        Pokemon(std::string nom);
        void attaquer(Pokemon &cible);
        void recevoirDegats(int degats);
        std::string getNom();
        int getVie();
        void setJoueur(Joueur* joueur);
        bool getKo();
        void setKo(bool isko);
        Joueur* getJoueur();
        void choisirAttaque(Pokemon &cible);

};

#endif
