/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Character abstract class definition file
***************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Dice.hpp"

using std::string;

enum SpecialAbility {NONE, CHARM, MOB, GLARE, HOGWARTS};

class Character
{
    protected:
        Dice myDice;
        bool dead;
        int attackDice;
        int attackSides;
        int defendDice;
        int defendSides;
        int amtArmor;
        int amtStrength;

    public:
        Character();
        virtual ~Character() {};

        //Accessors
        int getStrength();
        int getArmor();
        virtual bool isDead();
        virtual string getType() = 0;
        
        //functions
        virtual int attack(SpecialAbility&);
        virtual void defend(int, SpecialAbility);
};
#endif //Character
