
#include <iostream>
#include <iomanip>
#include "Game.hpp"
#include "Menu.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

using std::cout;
using std::endl;
using std::string;
using std::setw;

Game::Game()
{

}

Game::~Game()
{
    delete player1;
    delete player2;
}

void Game::playGame()
{
    cout << "\nSelect the first character to fight." << endl;
    printMenu();
    switch (gameMenu.getInt(1, 5))
    {
        case 1: player1 = new Barbarian;
                break;
        case 2: player1 = new BlueMen;
                break;
        case 3: player1 = new HarryPotter;
                break;
        case 4: player1 = new Medusa;
                break;
        case 5: player1 = new Vampire;
                break;
    }
    cout << "Select the second character to fight." << endl;
    printMenu();
    switch (gameMenu.getInt(1, 5))
    {
        case 1: player2 = new Barbarian;
                break;
        case 2: player2 = new BlueMen;
                break;
        case 3: player2 = new HarryPotter;
                break;
        case 4: player2 = new Medusa;
                break;
        case 5: player2 = new Vampire;
                break;
    }

    int roundCounter = 1;
    while(!player1->isDead() && !player2->isDead())
    {
        cout << "\t------------\n\n"
             << "\n\t Round: " << setw(3) << roundCounter << "\n"
             << "\t------------\n\n"
             << "\tInformation"
             << "\n--------------------------------\n"
             << "             Player 1\tPlayer 2\n"
             << "Type:     " << setw(11) << player1->getType() << "\t" << player2->getType() << "\n"
             << "Armor:    " << setw(11) << player1->getArmor() << "\t" << player2->getArmor() << "\n"
             << "Strength: " << setw(11) << player1->getStrength() << "\t" << player2->getStrength() << "\n"
             << "----------------------------------\n";

        cout << "\nPlayer 1 attacks Player 2.\n";
        player1->attack(player2);

        cout << "\nPlayer 2 attacks Player 1.\n\n";
        player2->attack(player1);

        roundCounter++;
    }

}

void Game::printMenu()
{
    cout << "1. Barbarian\n"
         << "2. Blue Men\n"
         << "3. Harry Potter\n"
         << "4. Medusa\n"
         << "5. Vampire\n"
         << "Enter character to fight: ";
}
