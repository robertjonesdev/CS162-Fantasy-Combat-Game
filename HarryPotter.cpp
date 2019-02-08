/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Harry Potter class implementation file.
**               Inherits from Character class.
***************************************************************/
#include "HarryPotter.hpp"
#include "Dice.hpp"
#include <iostream>

using std::cout;
using std::endl;

HarryPotter::HarryPotter(): Character()
{
    this->dead = false;
    this->attackDice = 2;
    this->attackSides = 6;
    this->defendDice = 2;
    this->defendSides = 6;
    this->amtArmor = 0;
    this->amtStrength = 10;
    this->hasHogwarts = true;
}

/******************************************************************************
** HarryPotter::defend()
** This is the character's defense method. Will accept arguments of the
** opponent's roll and their special ability (if any). This method handles
** all damage and possible death.
** IMPLEMENTS HOGWARTS
*******************************************************************************/
void HarryPotter::defend(int oppRoll, SpecialAbility oppSpecial)
{
    int myRoll = myDice.Roll(defendDice, defendSides);
    int myDefense = myRoll + this->amtArmor;
    int myDamage = 0;

    //Account for any special abilities from the attacker.
    switch (oppSpecial)
    {
        case 3: //GLARE
        {
            cout << "Medusa has invoked her Glare ability!\nHarry Potter is turned in to stone!" << endl;
            myDamage = this->amtStrength;
            break;
        }
        default: //All else.
        {
            cout << "Harry Potter's defense dice " << defendDice << "d" << defendSides << " roll is: " << myRoll << endl;
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

    //Assess the damage to the character
    this->amtStrength -= myDamage;
    cout << "The total inflicted damage is: " << myDamage
         << " and Harry Potter has " << this->amtStrength << " strength points remaining." << endl;

    //Test to see if the character should be dead.
    if (this->amtStrength <= 0)
    {
        //Implement Hogwarts special ability
        if (this->hasHogwarts)
        {
            this->amtStrength = 20;
            this->hasHogwarts = false;
            cout << "Harry Potter has invoked Hogwarts! He recovers and his total strength is now 20!" << endl;
        }
        else
        {
            this->dead = true;
        }
    }
}

/******************************************************************************
** HarryPotter::getType()
** This returns a string of the character's name for the Game class to use.
*******************************************************************************/
string HarryPotter::getType()
{
    return "HarryPotter";
}
