/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Barbarian class definition file.
***************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
#include <string>

using std::string;

class Barbarian: public Character
{
    public:
        Barbarian();
        virtual ~Barbarian() {};
        virtual string getType();
};
#endif //Barbarian
