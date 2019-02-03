#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"
#include <string>

using std::string;

class Medusa : public Character
{
    private:

    protected:

    public:
        Medusa();
        virtual ~Medusa();
        virtual void attack(Character*&);
        virtual void defend(int);
        virtual string getType();
};
#endif //Medusa
