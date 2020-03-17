#ifndef DEF_BULBIZARRE
#define DEF_BULBIZARRE

#include <iostream>
#include "Pokemon.h"

class Bulbizarre : public Pokemon {
    private:
    public :
        Bulbizarre(Joueur *joueur);
        Bulbizarre(); 
        void charge(Pokemon &cible);
        void trancheHerbe(Pokemon &cible);
        void choisirAttaque(Pokemon &cible);
};

#endif