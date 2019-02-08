/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Vampire Class definition file.
***************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"
#include <string>

using std::string;

class Vampire: public Character
{
    public:
        Vampire();
        virtual ~Vampire() {};
        virtual void defend(int, SpecialAbility);
        virtual string getType();
};
#endif //Vampire
