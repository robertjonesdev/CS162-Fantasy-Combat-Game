#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Dice.hpp"

using std::string;

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
        virtual ~Character();

        //Accessors
        virtual string getType() = 0;
        int getStrength();
        int getArmor();
        virtual bool isDead();


        //functions
        virtual void attack(Character*&) = 0;
        virtual void defend(int) = 0;
};
#endif //Character
