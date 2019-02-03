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
    protected:

    public:
        Game();
        virtual ~Game();
        void playGame();
        void printMenu();
};
#endif //Game
