/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Barbarian class implementation file.
**               Inherits from Character class.
***************************************************************/
#include "Barbarian.hpp"
#include "Dice.hpp"
#include <iostream>

using std::cout;
using std::endl;

Barbarian::Barbarian() : Character()
{
    this->dead = false;
    this->attackDice = 2;
    this->attackSides = 6;
    this->defendDice = 2;
    this->defendSides = 6;
    this->amtArmor = 0;
    this->amtStrength = 12;
}

/******************************************************************************
** Barbarian::getType()
** This returns a string of the character's name for the Game class to use.
*******************************************************************************/
string Barbarian::getType()
{
    return "Barbarian";
}
