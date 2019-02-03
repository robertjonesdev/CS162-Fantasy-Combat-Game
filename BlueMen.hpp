#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"
#include <string>

using std::string;

class BlueMen : public Character
{
    private:

    protected:

    public:
        BlueMen();
        virtual ~BlueMen();
        virtual void attack(Character*&);
        virtual void defend(int);
        virtual string getType();
};
#endif //BlueMen
