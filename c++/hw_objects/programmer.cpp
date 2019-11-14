#include "programmer.h"


void Programmer::Speak() const {
    printf("Hi my name is %s and I program in %s\n", this->name, this->language);
}

void Programmer::Cry() const {
    printf("Why won't you work. :*(\n");
}