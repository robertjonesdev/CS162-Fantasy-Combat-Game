/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Dice implementation file
***************************************************************/
#include <ctime>
#include <cstdlib>
#include "Dice.hpp"

int Dice::Roll(int numDice, int numSides)
{
    int rollTotal = 0;
    for (int i = 0; i < numDice; i++)
    {
        rollTotal += rand() % numSides + 1;
    }
    return rollTotal;
}
