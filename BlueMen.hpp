/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  BlueMen class definition file.
***************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"
#include <string>

using std::string;

class BlueMen : public Character
{
    public:
        BlueMen();
        virtual ~BlueMen() {};
        virtual void defend(int, SpecialAbility);
        virtual string getType();
};
#endif //BlueMen
