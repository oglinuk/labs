#include "cppProgrammer.h"
#include "goProgrammer.h"

int main() {
    // Using default constructor
    cppProgrammer seniorDeveloper;

    seniorDeveloper.setName("Bob");

    seniorDeveloper.Speak();
    seniorDeveloper.Cry();

    // Using constructor with parameters
    goProgrammer juniorDeveloper = goProgrammer("Alice");

    juniorDeveloper.Speak();
    juniorDeveloper.Cry();
    return 0;
}