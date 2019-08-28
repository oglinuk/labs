#include <iostream>
#include <string>

int main() {
    std::string name;

    printf("Enter your name: ");
    
    std::cin >> name;

    printf("Hello %s from the C++ hw_input example!\n", name);

    return 0;
}