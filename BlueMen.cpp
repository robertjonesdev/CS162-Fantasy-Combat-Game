/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Blue Men class implementation file. 
**               Inherits from Character class.
***************************************************************/
#include "BlueMen.hpp"
#include "Dice.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

BlueMen::BlueMen(): Character()
{
    this->dead = false;
    this->attackDice = 2;
    this->attackSides = 10;
    this->defendDice = 3;
    this->defendSides = 6;
    this->amtArmor = 3;
    this->amtStrength = 12;
}


/******************************************************************************
** BlueMen::attack()
** This is the character's attach method. Will accept arguments of the
** their special ability (if any) so that it can pass back by reference.
** This method returns the attack dice roll as an integer.
*******************************************************************************/
int BlueMen::attack(SpecialAbility& mySpecial)
{
    int myRoll = myDice.Roll(attackDice, attackSides);
    cout << "The Blue Mens attack dice " << attackDice << "d" << attackSides << " roll is: " << myRoll << endl;
    return myRoll;
}

/******************************************************************************
** BlueMen::defend()
** This is the character's defense method. Will accept arguments of the
** opponent's roll and their special ability (if any). This method handles
** all damage and possible death.
*******************************************************************************/
void BlueMen::defend(int oppRoll, SpecialAbility oppSpecial)
{
    //Mob Special ability
    if (this->amtStrength <= 8 && this->amtStrength > 4)
    {
        defendDice = 2;
    }
    else if (this->amtStrength <= 4)
    {
        defendDice = 1;
    }

    int myRoll = myDice.Roll(defendDice, defendSides);
    int myDefense = myRoll + this->amtArmor;
    int myDamage = 0;

    //Account for any special abilities from the attacker.
    switch (oppSpecial)
    {
        case 3: //GLARE
        {
            cout << "Medusa has invoked her Glare ability!\nThe Blue Men is turned in to stone!" << endl;
            myDamage = this->amtStrength;
            break;
        }
        default: //All else.
        {
            cout << "The Blue Men's defense dice " << defendDice << "d" << defendSides << " roll is: " << myRoll << endl;
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

    this->amtStrength -= myDamage;
    cout << "The total inflicted damage is: " << myDamage
         << " and the Blue Men have " << this->amtStrength << " strength points remaining." << endl;

    if (this->amtStrength <= 0)
    {
       this->dead = true;
    }
}

/******************************************************************************
** BlueMen::getType()
** This returns a string of the character's name for the Game class to use.
*******************************************************************************/
string BlueMen::getType()
{
    return "Blue Men";
}
