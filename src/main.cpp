#include "../include/Pokemon.h"
#include "../include/Joueur.h"

#include <iostream>
#include <string>



int main(int argc, char *argv[]) {
	Joueur mael("mael");
	std::cout << mael.getNom() << std::endl;
	std::cout << mael.getPokemon(0) << std::endl;
	mael.menu();

	return 0;
}
