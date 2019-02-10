/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  This is a Fantasy Combat Game that contains characters
**               of Vampire, Barbarian, Blue Men, Medusa, and Harry Potter.
**               The characters also have their own characteristics as well
**               as special abilities.
**
**              Two characters will be chosen by the user and they will
**              enter in combat with each other.
**
**              Combat will consist of rounds until one player dies.
**              Each round consists of consists of an attack roll and
**              defend roll from each player which determines how much damage
**              is taken by the players.
***************************************************************/
#include <iostream>       //Console input and output
#include <vector>         //For the menu
#include <string>         //Menu title
#include <ctime>          //Random
#include "Menu.hpp"       //Menu object
#include "Game.hpp"

using std::string;
using std::vector;

int main()
{
    //Seed the random function for the Dice class.
    srand(time(NULL));

    //Create the menu & menu options.
    string menuTitle = "\n\tProject 3: Fantasy Combat Game\n\t------------------------------";
    vector<string> menuList;
    menuList.push_back("Play again");
    Menu menu(menuTitle, menuList);

    std::cout << menuTitle << std::endl;
    
    //Loop the menu until user quits.
    while (!menu.getQuit())
    {
        //Instantiate a Game object and run playGame.
        Game myGame;
        myGame.playGame();

        menu.printMenu();
        menu.getChoice();

        //The game will deconstruct and allocated memory will be deleted.
    }
    return 0;
}
