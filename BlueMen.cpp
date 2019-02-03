
#include "BlueMen.hpp"

BlueMen::BlueMen(): Character()
{
    this->dead = false;
    this->attackDice = 2;
    this->attackSides = 10;
    this->defendDice = 1;
    this->defendSides = 6;
    this->amtArmor = 3;
    this->amtStrength = 8;
}

BlueMen::~BlueMen()
{

}

/******************************************************************************
** BlueMen::attack()
**
*******************************************************************************/
void BlueMen::attack(Character*& opponent)
{

}

/******************************************************************************
** BlueMen::defend()
**
*******************************************************************************/
void BlueMen::defend(int oppRoll)
{

}

/******************************************************************************
** BlueMen::getType()
**
*******************************************************************************/
string BlueMen::getType()
{
    return "BlueMen";
}
