#include "programmer.h"

class cppProgrammer: public Programmer
{
    public:
        cppProgrammer() : Programmer()
        {
            this->language = "C++";
        };
        cppProgrammer(std::string n) : Programmer(n)
        {
            this->language = "C++";
            this->setName(n);
        };

        void Cry() const override; // Normal programmer cry
};