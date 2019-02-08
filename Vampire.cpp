/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:   Vampire class implementation file.
**               Inherits from Character class.
***************************************************************/
#include "Vampire.hpp"
#include <string>
#include "Dice.hpp"
#include <iostream>

using std::cout;
using std::endl;

Vampire::Vampire(): Character()
{
    this->dead = false;
    this->attackDice = 1;
    this->attackSides = 12;
    this->defendDice = 1;
    this->defendSides = 6;
    this->amtArmor = 1;
    this->amtStrength = 18;
}

/******************************************************************************
** Vampire::defend()
** This is the character's defense method. Will accept arguments of the
** opponent's roll and their special ability (if any). This method handles
** all damage and possible death.
** IMPLEMENTS CHARM
*******************************************************************************/
void Vampire::defend(int oppRoll, SpecialAbility oppSpecial)
{
    int myRoll = myDice.Roll(defendDice, defendSides);
    int myDefense = myRoll + this->amtArmor;
    int myDamage = 0;

    //Account for any special abilities from the attacker.
    switch (oppSpecial)
    {
        case 3: //GLARE
        {
            cout << "Medusa has invoked her Glare ability!\nThe Vampire is turned in to stone!" << endl;
            myDamage = this->amtStrength;
            break;
        }
        default: //All else.
        {
            //implement the Vampire's Glare defense ability at 50% probability.
            if (rand () % 2 == 1)
            {
                cout << "The Vampire's defense dice " << defendDice << "d" << defendSides << " roll is: " << myRoll << endl;
                if (myDefense > oppRoll)
                {
                    myDamage = 0;
                }
                else
                {
                    myDamage = oppRoll - myDefense;
                }
            }
            else
            {
                cout << "The Vampire has charmed its opponent in to not attacking them!" << endl;
            }
            break;
        }
    }

    //Assess the damage to the character
    this->amtStrength -= myDamage;
    cout << "The total inflicted damage is: " << myDamage
         << " and the Vampire has " << this->amtStrength << " strength points remaining." << endl;

    //Test to see if the character should be dead.
    if (this->amtStrength <= 0)
    {
       this->dead = true;
    }
}

/******************************************************************************
** Vampire::getType()
** This returns a string of the character's name for the Game class to use.
*******************************************************************************/
string Vampire::getType()
{
    return "Vampire";
}
