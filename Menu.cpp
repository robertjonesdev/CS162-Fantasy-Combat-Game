/*********************************************************************
** Program name:  Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:        Robert Jones
** Date:          February 6, 2019
** Description:   Menu.cpp Menu class implementation
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Menu.hpp"

//Constructors & Deconstructor
Menu::Menu()
{
    this->quit = false;
}

Menu::Menu(std::string strTitle, std::vector<std::string> vecList)
{
    this->menuTitle = strTitle;
    this->menuList = vecList;
    this->quit = false;
}

Menu::~Menu() { }

//Accessors
bool Menu::getQuit()
{
    return this->quit;
}

//Modifiers
void Menu::addOption(std::string strOption)
{
    this->menuList.push_back(strOption);
}

void Menu::rmOption(int option)
{
    this->menuList.erase(this->menuList.begin() + option - 1);
}

void Menu::changeTitle(std::string strTitle)
{
    this->menuTitle = strTitle;
}

//Functions
void Menu::printMenu() const
{
    std::cout << '\n' << this->menuTitle << '\n';
    for (int i = 1; i <= this->menuList.size(); i++)
    {
      std::cout << i << ". " << this->menuList[i-1] << '\n';
    }
    std::cout << (this->menuList.size() + 1) << ". Exit Program\n";
}

int Menu::getChoice()
{
    //SOURCE CITATION: Adapted from the following tutorial:
    //Lesson 17: Data validation / Type checking with StringStream
    //http://beginnerscpp.com/lesson-17-data-validation-type-checking-with-stringstream/
    std::cout << "Enter choice: ";
    std::string strInput = "";
    int choice = 0;
    bool isValid = false;
    while (!isValid)
    {
        getline(std::cin, strInput);
        std::stringstream ss(strInput);
        if (strInput.find_first_not_of("0123456789") == string::npos && ss >> choice //Implemented from Piazza post #254
            && choice >= 1 && choice <= (this->menuList.size() + 1))
        {
            isValid = true;
        }
        else
        {
            std::cout << "Invalid input. Re-enter choice: ";
        }
    }
    if (choice == this->menuList.size()+1)
    {
        this->quit = true;
    }
    return choice;
}

int Menu::getInt(int min, int max)
{
    //SOURCE CITATION: Adapted from the following tutorial:
    //Lesson 17: Data validation / Type checking with StringStream
    //http://beginnerscpp.com/lesson-17-data-validation-type-checking-with-stringstream/
    std::string strInput = "";
    int choice = 0;
    bool isValid = false;
    while (!isValid)
    {
        getline(std::cin, strInput);
        std::stringstream ss(strInput);
        if (strInput.find_first_not_of("0123456789") == string::npos //Implemented from Piazza post #254
            && ss >> choice && choice >= min && choice <= max)
        {
            isValid = true;
        }
        else
        {
           std::cout << "Invalid input. Re-enter choice (" << min << " - " << max << "): ";
        }
    }
    return choice;
}

double Menu::getDouble(double min, double max)
{
    //SOURCE CITATION: Adapted from the following tutorial:
    //Lesson 17: Data validation / Type checking with StringStream
    //http://beginnerscpp.com/lesson-17-data-validation-type-checking-with-stringstream/
    std::string strInput = "";
    double input = 0;
    bool isValid = false;
    while (!isValid)
    {
        getline(std::cin, strInput);
        std::stringstream ss(strInput);
        if (strInput.find_first_not_of("0123456789.") == string::npos
            && ss >> input && input >= min && input <= max)
        {
            isValid = true;
        }
        else
        {
            std::cout << "Invalid input. Re-enter choice (" << min << " - " << max << "): ";
        }
    }
    return input;
}

std::string Menu::getString()
{
    std::string strInput = "";
    getline(std::cin, strInput);
    std::stringstream ss(strInput);
    return ss.str();
}
