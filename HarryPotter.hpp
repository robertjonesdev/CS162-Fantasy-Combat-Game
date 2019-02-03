#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"
#include <string>

using std::string;

class HarryPotter : public Character
{
    private:

    protected:

    public:
        HarryPotter();
        virtual ~HarryPotter();
        virtual void attack(Character*&);
        virtual void defend(int);
        virtual string getType();
};
#endif //HarryPotter
