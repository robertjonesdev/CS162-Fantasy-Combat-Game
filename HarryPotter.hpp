/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  HarryPotter Class definition file.
***************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"
#include <string>

using std::string;

class HarryPotter : public Character
{
    private:
        bool hasHogwarts;

    public:
        HarryPotter();
        virtual ~HarryPotter() {};
        virtual void defend(int, SpecialAbility);
        virtual string getType();
};
#endif //HarryPotter
