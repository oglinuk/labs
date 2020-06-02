#include "programmer.h"

class goProgrammer: public Programmer
{
    public:
        goProgrammer() : Programmer()
        {
            this->language = "Go";
        };
        goProgrammer(std::string n) : Programmer(n)
        {
            this->language = "Go";
            this->setName(n);
        };

        void Cry() const override; // Happy tears kinda cry
};