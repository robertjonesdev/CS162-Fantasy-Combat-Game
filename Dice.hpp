/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Dice Class definition file.
***************************************************************/
#ifndef DICE_HPP
#define DICE_HPP

class Dice
{
    public:
        Dice() {};;
        virtual ~Dice() {};
        int Roll(int, int);
};
#endif //Dice
