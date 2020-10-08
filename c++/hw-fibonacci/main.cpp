#include <iostream>
#include <unistd.h>

int main()
{
    unsigned long int a, b, c, i;
    a = 0;
    b = 1;
    i = 0;

    while (1) {
        i++;
        std::cout << a << std::endl;
        c = a;
        a = b;
        b = c + a;
        sleep(1);
    }
    return 0;
}