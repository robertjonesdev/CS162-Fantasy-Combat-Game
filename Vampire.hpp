#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"
#include <string>

using std::string;

class Vampire: public Character
{
    private:

    protected:

    public:
        Vampire();
        virtual ~Vampire();
        virtual void attack(Character*&);
        virtual void defend(int);
        virtual string getType();
};
#endif //Vampire
