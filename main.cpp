/*********************************************************************
** Program name:  Project 3 CS 162-400, Winter 2019)
** Author:        Robert Jones
** Date:          February 2, 2019
** Description:   main.cpp, Main Class Implementation
**********************************************************************/

#include <iostream>
#include <vector>         //For the menu
#include <string>         //Menu title
#include "Menu.hpp"       //Menu object

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    //Create the menu.
    string menuTitle = "\n\tProject 3: ";
    vector<string> menuList;
    menuList.push_back("");
    menuList.push_back("");
    menuList.push_back("");
    Menu menu(menuTitle, menuList);

    //Loop the menu until user quits.
    while (!menu.getQuit())
    {
        menu.printMenu();
        switch(menu.getChoice())
        {
            case 1:
            {

                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
        }
    }
  return 0;
}
