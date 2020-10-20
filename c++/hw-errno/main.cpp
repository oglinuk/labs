#include <cerrno>
#include <cstring>
#include <iostream>
#include <fstream>

int main()
{
    FILE *f;
    std::ifstream fail("doesnt_exist.txt");

    if (fail.is_open()) {
        // *Should* never happen ...
    } else {
        fprintf(stderr, "Failed to open file: %s\n", std::strerror(errno));
    }
    return 0;
}