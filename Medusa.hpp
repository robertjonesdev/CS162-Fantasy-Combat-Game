/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Medusa Class definition file.
***************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"
#include <string>

using std::string;

class Medusa : public Character
{
    public:
        Medusa();
        virtual ~Medusa() {};
        virtual int attack(SpecialAbility&);
        virtual void defend(int, SpecialAbility);
        virtual string getType();
};
#endif //Medusa
