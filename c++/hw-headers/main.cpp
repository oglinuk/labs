#include "main.h" // User header

int main() {
    sayHello();

    return 0;
}

// Notice how we dont need to declare the sayHello function above the main
// or #include <iostream>, this is because it is in main.h
void sayHello() {
    printf("Hello world from the C++ hw-headers example!\n");
}