#include "Character.hpp"

Character::Character()
{
    this->dead = false;
}

Character::~Character()
{

}

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
