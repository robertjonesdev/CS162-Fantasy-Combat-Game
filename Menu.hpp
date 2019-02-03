/*********************************************************************
** Program name:  War Game with Dice (Project 3, CS 162-400, Winter 2019)
** Author:        Robert Jones
** Date:          January 20, 2019
** Description:   Menu.hpp, Menu Class Definition
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

class Menu
{
  private:
    bool quit;
    std::string menuTitle;
    std::vector<std::string> menuList;

  public:
    //Constructors and Deconstructor
    Menu();
    Menu(std::string menuTitle, std::vector<std::string> menuList);
    virtual ~Menu();

    //Accessors
    bool getQuit();

    //Modifiers
    void addOption(std::string strOption);
    void rmOption(int option);
    void changeTitle(std::string strTitle);

    //Functions
    void printMenu() const;
    int getChoice();
    int getInt(int min, int max);
};

#endif
