#include <iostream>
#include <fstream>

int main()
{    
    std::ofstream hwoFile("hwFiles.txt");
    std::ifstream hwiFile("hwFiles.txt");

    if (hwoFile.is_open()) {
        hwoFile << "Hello world from the C++ hw-files example!\n";

        if (hwiFile.is_open()) {
            std::cout << hwiFile.rdbuf();
            hwiFile.close();
        } else {
            printf("Failed to open hwiFile ...\n");
        }

        hwoFile.close();
    } else {
        printf("Failed to open hwoFile ...\n");
    }

    return 0;
}
