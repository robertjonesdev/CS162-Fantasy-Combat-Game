
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

Barbarian::~Barbarian()
{

}

/******************************************************************************
** Barbarian::attack()
**
*******************************************************************************/
void Barbarian::attack(Character*& opponent)
{
    int myRoll = myDice.Roll(attackDice, attackSides);
    cout << "The attacker's attack dice roll is: " << myRoll << endl;
    opponent->defend(myRoll);
}

/******************************************************************************
** Barbarian::defend()
**
*******************************************************************************/
void Barbarian::defend(int oppRoll)
{
    int myRoll = myDice.Roll(defendDice, defendSides);
    int myDefense = myRoll + this->amtArmor;
    int myDamage = 0;
    cout << "The defenders's defend dice roll is: " << myRoll << endl;

    if (myDefense > oppRoll)
    {
        myDamage = 0;
    }
    else
    {
        myDamage = oppRoll - myDefense;
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
**
*******************************************************************************/
string Barbarian::getType()
{
    return "Barbarian";
}
