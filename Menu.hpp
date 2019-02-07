/*********************************************************************
** Program name:  Lab 4, CS 162-400, Winter 2019
** Author:        Robert Jones
** Date:          January 29, 2019
** Description:   Menu.hpp, Menu Class Definition
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

using std::string;
using std::vector;

class Menu
{
    private:
        bool quit;
        string menuTitle;
        vector<std::string> menuList;

    public:
        //Constructors and Deconstructor
        Menu();
        Menu(string menuTitle, vector<string> menuList);
        virtual ~Menu();

        //Accessors
        bool getQuit();

        //Modifiers
        void addOption(string strOption);
        void rmOption(int option);
        void changeTitle(string strTitle);

        //Functions
        void printMenu() const;
        int getChoice();
        int getInt(int min, int max);
        double getDouble(double min, double max);
        string getString();
};

#endif
