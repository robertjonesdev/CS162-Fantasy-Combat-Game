
#include "HarryPotter.hpp"

HarryPotter::HarryPotter(): Character()
{
    this->dead = false;
    this->attackDice = 2;
    this->attackSides = 6;
    this->defendDice = 2;
    this->defendSides = 6;
    this->amtArmor = 0;
    this->amtStrength = 10;
}

HarryPotter::~HarryPotter()
{

}

/******************************************************************************
** HarryPotter::attack()
**
*******************************************************************************/
void HarryPotter::attack(Character*& opponent)
{

}

/******************************************************************************
** HarryPotter::defend()
**
*******************************************************************************/
void HarryPotter::defend(int oppRoll)
{

}

/******************************************************************************
** HarryPotter::getType()
**
*******************************************************************************/
string HarryPotter::getType()
{
    return "HarryPotter";
}
