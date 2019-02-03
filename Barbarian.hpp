#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
#include <string>

using std::string;

class Barbarian: public Character
{
    private:

    protected:

    public:
        Barbarian();
        virtual ~Barbarian();
        virtual void attack(Character*&);
        virtual void defend(int);
        virtual string getType();
};
#endif //Barbarian
