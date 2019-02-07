/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Game class implementation file. 
***************************************************************/
#include <iostream>         //Console output
#include <iomanip>          //Console output formating
#include "Menu.hpp"         //Input validation
#include "Game.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::right;

/******************************************************************************
** Deconstructor
** Necessary to delete the dynamically allocated memory in playGame()
*******************************************************************************/
Game::~Game()
{
    delete player1;
    delete player2;
}

/******************************************************************************
** playGame()
** This is the main public function of the Game class. Will be called from int main(int argc, char const *argv[]) {
** after object is created.
*******************************************************************************/
void Game::playGame()
{

    /******************************************************************************
    ** In game menu to select character types for Player 1 or Player 2
    *******************************************************************************/
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
    cout << "\nSelect the second character to fight." << endl;
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
    /******************************************************************************
    ** Game loop. Will run until either player1 or player 2 is dead.
    *******************************************************************************/
    while(!player1->isDead() && !player2->isDead())
    {
        int p1Roll = 0;
        int p2Roll = 0;
        SpecialAbility p1Special = NONE;
        SpecialAbility p2Special = NONE;
        cout << "\n\t    ------------\n"
             << "\t     Round: " << setw(3) << roundCounter << "\n"
             << "\t    ------------\n\n"
             << "---------------------------------------\n"
             << "Stats     " << setw(10) << "Player 1" << "\t" << "Player 2\n"
             << "Type:     " << setw(10) << player1->getType() << "\t" << player2->getType() << "\n"
             << "Armor:    " << setw(10) << player1->getArmor() << "\t" << player2->getArmor() << "\n"
             << "Strength: " << setw(10) << player1->getStrength() << "\t" << player2->getStrength() << "\n"
             << "---------------------------------------" << endl;


        cout << "\n*** Player 1 attacks Player 2 ***" << endl
             << "Player 1: ";
        p1Roll = player1->attack(p1Special);

        cout << "Player 2: ";
        player2->defend(p1Roll, p1Special);
        if (player2->isDead())
        {
            cout << "\nPlayer 2 is dead. Player 1 is the winner!" << endl;
        }
        else
        {
            cout << "\n*** Player 2 attacks Player 1 ***" << endl
                 << "Player 2: ";
            p2Roll = player2->attack(p2Special);
            cout << "Player 1: ";
            player1->defend(p2Roll, p2Special);
        }

        if (player1->isDead())
        {
            cout << "\nPlayer 1 is dead. Player 2 is the winner!" << endl;
        }
        roundCounter++;
    }
}

/******************************************************************************
**PrintMenu for character options. will be called twice.
*******************************************************************************/
void Game::printMenu()
{
    cout << "1. Barbarian\n"
         << "2. Blue Men\n"
         << "3. Harry Potter\n"
         << "4. Medusa\n"
         << "5. Vampire\n"
         << "Enter character to fight: ";
}
