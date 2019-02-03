
#include "Medusa.hpp"

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

Medusa::~Medusa()
{

}

/******************************************************************************
** Medusa::attack()
**
*******************************************************************************/
void Medusa::attack(Character*& opponent)
{

}

/******************************************************************************
** Medusa::defend()
**
*******************************************************************************/
void Medusa::defend(int oppRoll)
{

}

/******************************************************************************
** Medusa::getType()
**
*******************************************************************************/
string Medusa::getType()
{
    return "Medusa";
}
