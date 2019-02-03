#ifndef DICE_HPP
#define DICE_HPP

#include <ctime>

class Dice
{
    public:
        Dice();
        virtual ~Dice();
        int Roll(int, int);
};
#endif //Dice
