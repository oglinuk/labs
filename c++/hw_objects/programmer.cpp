#include "programmer.h"


void Programmer::Speak() const {
    std::cout << "Hi my name is " << this->name << 
                " and I program in " << this->language << std::endl;
}

void Programmer::Cry() const {
    std::cout << "Why won't you work. :*(\n";
}