#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Usage: ./main <arg1> <arg2> ...\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printf("Arg%d: %s\n", i, argv[i]);
    }

    return 0;
}
