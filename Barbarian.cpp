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
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

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
** Barbarian::attack()
** This is the character's attach method. Will accept arguments of the
** their special ability (if any) so that it can pass back by reference.
** This method returns the attack dice roll as an integer.
*******************************************************************************/
int Barbarian::attack(SpecialAbility& mySpecial)
{
    int myRoll = myDice.Roll(attackDice, attackSides);
    cout << "The Barbarian's attack dice " << attackDice << "d" << attackSides << " roll is: " << myRoll << endl;
    return myRoll;
}

/******************************************************************************
** Barbarian::defend()
** This is the character's defense method. Will accept arguments of the
** opponent's roll and their special ability (if any). This method handles
** all damage and possible death.
*******************************************************************************/
void Barbarian::defend(int oppRoll, SpecialAbility oppSpecial)
{
    int myRoll = myDice.Roll(defendDice, defendSides);
    int myDefense = myRoll + this->amtArmor;
    int myDamage = 0;

    //Account for any special abilities from the attacker.
    switch (oppSpecial)
    {
        case 3: //GLARE
        {
            cout << "Medusa has invoked her Glare ability!\nThe Barbarian is turned in to stone!" << endl;
            myDamage = this->amtStrength;
            break;
        }
        default: //All else.
        {
            cout << "The Barbarian's defense dice " << defendDice << "d" << defendSides << " roll is: " << myRoll << endl;
            if (myDefense > oppRoll)
            {
                myDamage = 0;
            }
            else
            {
                myDamage = oppRoll - myDefense;
            }
            break;
        }
    }

    cout << "The total inflicted damage is: " << myDamage << endl;

    this->amtStrength -= myDamage;

    if (this->amtStrength <= 0)
    {
       this->dead = true;
    }
}

/******************************************************************************
** Barbarian::getType()
** This returns a string of the character's name for the Game class to use.
*******************************************************************************/
string Barbarian::getType()
{
    return "Barbarian";
}
