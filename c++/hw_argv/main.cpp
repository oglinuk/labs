#include <iostream>

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: ./main <arg1> <arg2> ...\n");
        return -1;
    }

    for (int i = 0; i < argc; i++) {
        std::cout << "Arg" << i << ": " << argv[i] << std::endl;
    }

    return 0;
}