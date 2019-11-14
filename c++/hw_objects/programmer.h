#pragma once // Only include the header once during compilation
#include <iostream>
#include <string>

class Programmer {
    public:
        /* Getters */
        std::string getName() {
            return this->name;
        }

        std::string getLanguage() {
            return this->language;
        }
        
        /* Setters */
        void setName(std::string n) {
            name = n;
        }

        /* Constructors */
        Programmer(){}
        Programmer(std::string n) {
            this->setName(n);
        }

        virtual void Speak() const;
        virtual void Cry() const;

    protected:
        /* Attributes */
        std::string name;
        std::string language; // Note that this attribute doesn't have a setter
};