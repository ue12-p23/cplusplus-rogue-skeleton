#include <iostream>
#include <stdexcept>
#include "game.hpp"

// Afin que vous ayez un petit point de départ, voici le squelette c++ d'un jeu
// où le caractère '@' se déplace sur un board vide

// Le code est volontairement simple, moche et non-structuré
// (des variables/fonctions globales !)

// Tout ceci devra naturellement être repensé, étendu, organisé en classes...

// N'oubliez pas de vous mettre en gestion de version git et de faire des commits !
// afin de revenir facilement à la version qui "marchait"... ou du moins qui compilait.

int main()
{
  try
  {
    play_game();
  }
  // Cette exception ne devrait pas arriver !
  // Le jeu devrait tester tous les cas d'erreur.
  catch (const std::out_of_range &e)
  {
    std::cerr << "catching exception: " << e.what() << std::endl
              << std::endl;
    std::cerr << "Oups ! some tests are clearly missing..." << std::endl;
  }
  return 0;
}
