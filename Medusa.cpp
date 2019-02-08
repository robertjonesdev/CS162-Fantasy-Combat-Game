/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Medusa class implementation file.
**               Inherits from Character class.
***************************************************************/
#include "Medusa.hpp"
#include "Dice.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

Medusa::Medusa(): Character()
{
    this->dead = false;
    this->attackDice = 2;
    this->attackSides = 6;
    this->defendDice = 1;
    this->defendSides = 6;
    this->amtArmor = 3;
    this->amtStrength = 8;
}

/******************************************************************************
** Medusa::attack()
** This is the character's attach method. Will accept arguments of the
** their special ability (if any) so that it can pass back by reference.
** This method returns the attack dice roll as an integer.
** IMPLEMENTS GLARE
*******************************************************************************/
int Medusa::attack(SpecialAbility& mySpecial)
{
    int myRoll = myDice.Roll(attackDice, attackSides);
    cout << "Medusa's attack dice " << attackDice << "d" << attackSides << " roll is: " << myRoll << endl;

    //Implement Medusa's special ability of she rolls a 12.
    //mySpecial is passed by reference back to the Game class.
    if (myRoll == 12)
    {
        mySpecial = GLARE;
    }
    return myRoll;
}

/******************************************************************************
** Medusa::getType()
** This returns a string of the character's name for the Game class to use.
*******************************************************************************/
string Medusa::getType()
{
    return "Medusa";
}
