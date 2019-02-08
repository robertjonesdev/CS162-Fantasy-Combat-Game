/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Dice implementation file
**
**               int Roll(int, int): returns an integer value representing
**               the sum roll of a number of dice with a certain number of sides.
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
