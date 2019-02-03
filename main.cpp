/*********************************************************************
** Program name:  Project 3 CS 162-400, Winter 2019)
** Author:        Robert Jones
** Date:          February 2, 2019
** Description:   main.cpp, Main Class Implementation
**********************************************************************/

#include <iostream>
#include <vector>         //For the menu
#include <string>         //Menu title
#include <ctime>
#include "Menu.hpp"       //Menu object
#include "Game.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));

    //Create the menu & menu options.
    string menuTitle = "\n\tProject 3: Fantasy Combat Game\n\t------------------------------";
    vector<string> menuList;
    menuList.push_back("Play again");
    Menu menu(menuTitle, menuList);

    Game myGame;

    //Loop the menu until user quits.
    while (!menu.getQuit())
    {
        myGame.playGame();
        menu.printMenu();
        switch(menu.getChoice())
        {
            case 1:
            {
                myGame.playGame();
                break;
            }
        }
    }
  return 0;
}
