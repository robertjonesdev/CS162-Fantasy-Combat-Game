
#include "Vampire.hpp"
#include <string>

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

Vampire::~Vampire()
{

}

/******************************************************************************
** Vampire::attack()
**
*******************************************************************************/
void Vampire::attack(Character*& opponent)
{
}

/******************************************************************************
** Vampire::defend()
**
*******************************************************************************/
void Vampire::defend(int oppRoll)
{

}

/******************************************************************************
** Vampire::getType()
**
*******************************************************************************/
string Vampire::getType()
{
    return "Vampire";
}
