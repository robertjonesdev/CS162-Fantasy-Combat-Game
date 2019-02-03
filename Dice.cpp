#include <ctime>
#include <cstdlib>
#include "Dice.hpp"

Dice::Dice()
{

}

Dice::~Dice()
{
    
}

int Dice::Roll(int numDice, int numSides)
{
    int rollTotal = 0;
    for (int i = 0; i < numDice; i++)
    {
        rollTotal += rand() % numSides + 1;
    }
    return rollTotal;
}
