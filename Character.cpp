/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Character class implementation file.
**               Includes virtual functions for the character types to
**               inherit from.
***************************************************************/
#include "Character.hpp"
#include "Dice.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Character::Character()
{
    this->dead = false;
}

/******************************************************************************
** Character::attack()
** This is the character's attach method. Will accept arguments of the
** their special ability (if any) so that it can pass back by reference.
** This method returns the attack dice roll as an integer.
** It is a virtual function and can be inherited.
*******************************************************************************/
int Character::attack(SpecialAbility& mySpecial)
{
    int myRoll = myDice.Roll(attackDice, attackSides);
    cout << this->getType() << "'s attack dice " << attackDice << "d" << attackSides << " roll is: " << myRoll << endl;
    return myRoll;
}

/******************************************************************************
** Character::defend()
** This is the character's defense method. Will accept arguments of the
** opponent's roll and their special ability (if any). This method handles
** all damage and possible death.
** It is a virtual function and can be inherited.
*******************************************************************************/
void Character::defend(int oppRoll, SpecialAbility oppSpecial)
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
            cout << this->getType() << "'s defense dice " << defendDice << "d" << defendSides << " roll is: " << myRoll << endl;
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

    cout << "The total inflicted damage is: " << myDamage
         << " and " << this->getType() << " has " << this->amtStrength << " strength points remaining." << endl;

    this->amtStrength -= myDamage;

    if (this->amtStrength <= 0)
    {
       this->dead = true;
    }
}

//Accessors
int Character::getStrength()
{
    return this->amtStrength;
}

int Character::getArmor()
{
    return this->amtArmor;
}

bool Character::isDead()
{
    return this->dead;
}
