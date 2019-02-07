/***************************************************************
** Program name: Project 3 Fantasy Combate Game (CS162 Winter 2019)
** Author:       Robert Jones
** Date:         February 6, 2019
** Description:  Game class definition file
***************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "Character.hpp"

class Game
{
    private:
        Menu gameMenu;
        Character* player1;
        Character* player2;

    public:
        Game() {};
        virtual ~Game();
        void playGame();
        void printMenu();
};
#endif //Game
