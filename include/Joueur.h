#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include "Pokemon.h"
#include "Bulbizarre.h"
#include <string>
#include <vector>

class Joueur {
    private:
        std::vector<Bulbizarre*> m_pokemon;
        std::vector<Bulbizarre*> m_equipe;
        std::string m_nom;
        Bulbizarre* m_pokeActu;

    public:

        Joueur(std::string nom);
        void capturerPokemon(Bulbizarre* pokemon);
        void voirPokemon();
        void choisirEquipe();
        void combattre();
        void menu();
        void commencerCombat(Joueur* moi, Bulbizarre* adversaire);

        
        Bulbizarre* getPokemon(int i);
        std::string getNom();
        std::vector<Bulbizarre*> getEquipe();
        void setPokeActu();
};

#endif