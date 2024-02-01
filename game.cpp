#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "game.hpp"
#include "keyboard-event.hpp"

// Ceci est le squelette d'un jeu où un caractère se déplace sur un board.
// Le code est ici volontairement très simple, moche et pas structuré du tout (des variables globales !)
// Tout ceci devra naturellement être repensé, étendu, organisé en classes...

// MESSAGE
// pour parler au joueur
std::string message = "Welcome to our super game !";

void draw_message()
{
}

// BOARD

// taille du board
int rows = 10;
int columns = 20;

// board
// ici simplement un vecteur de char qui initialement contient des '.'
std::vector<char> board = std::vector<char>(rows * columns, '.');
// ensuite le board pourra être un vecteur d'objets plus évolués que des char

// on ré-initialise le board (ici on le re-remplit de '.')
void reset_board()
{
    for (int i = 0; i < board.size(); i++)
        board[i] = '.';
}

// HERO
// position du hero
int x_hero = 2;
int y_hero = 7;
int life = 3;
int health = 20;

// ajouter le hero sur le board
void add_hero_to_board()
{
    // super moche avec ses variables globales
    board.at(x_hero * columns + y_hero) = '@';
}

int random(int n)
// c random generation of a integer between 0 and n.
{
    return rand() % n;
}

// on téléporte le hero (pour montrer random)
void teleport_hero()
{
    x_hero = random(rows);
    y_hero = random(columns);
}

// AUTRES AFFICHAGES

void draw_action()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "'q' to quit" << std::endl;
    std::cout << "'i' up 'k' down 'l' right 'j' left" << std::endl;
    std::cout << "'t' teleport" << std::endl;
}

// on dessine le board avec les messages
void draw_board()
{
    // message
    std::cout << message << std::endl;

    // board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
            std::cout << board.at(r * columns + c);
        std::cout << std::endl;
    }

    // état/position du héro
    std::cout << "life: " << life << " health: " << health;
    // ou si on a besoin d'une string
    std::string pos = " position " + std::to_string(x_hero) + ", " + std::to_string(y_hero);
    std::cout << pos << std::endl;
}

// cette fonction devra être une méthode d'une classe (Game par exemple)
void play_game()
{

    // le jeu est une boucle sans fin qui (par exemple, ici):
    //    - efface tout ce qu'il y a sur le board
    //    - ajoute le joueur sur le board
    //    - dessine le board
    //    - attend que le joueur entre une action
    //    - et fait l'action demandée

    // l'action est un caractère entré au clavier
    char key = 'l';

    while (true)
    {
        // on efface tout
        backgroundClear();

        // on ré-initialise le board
        reset_board();

        // on écrit le hero dans le board
        add_hero_to_board();

        // on dessine le board
        // qui contient donc le hero

        // on met un message inutile...
        draw_board();
        // on attend qu'un caractère soit entré
        if (keyEventBlocking())
        {
            std::cin >> key;

            // on traite les clés

            if (key == 'i' || key == 'k' || key == 'j' || key == 'l')
            {
                message = "moving hero";
                if (key == 'l')
                {
                    // avec cette clé, on veut - par exemple - déplacer le hero
                    // d'un coup vers la droite
                    y_hero++;
                }
                else if (key == 'i') // vers le haut
                {
                    x_hero--;
                }
                // les autres mouvements...
                else if (key == 'k') // vers le bas
                {
                    x_hero++;
                }
                else if (key == 'j') // vers la gauche
                {
                    y_hero--;
                }
            }
            else if (key == 'm')
            {
                message = "le hero mange une pomme";
                health += 5; // le héro reprend des forces
            }
            else if (key == 't') // les autres clés ...
            {
                teleport_hero();
                message = "teleporting hero";
                health--; // le héro se fatigue
            }
            else if (key == 'q') // on quitte la partie
            {
                backgroundClear();
                std::cout << "see you soon !" << std::endl;
                exit(1);
            }
            else
            {
                message = "unknown key command";
            }
            health--; // le héro se fatigue
        }
    }
}