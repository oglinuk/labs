#include <iostream>
#include <fstream>

int main() {    
    std::ofstream hwoFile("hwFiles.txt");
    std::ifstream hwiFile("hwFiles.txt");

    if (hwoFile.is_open()) {
        hwoFile << "Hello world from C++ hw_files!\n";

        if (hwiFile.is_open()) {
            std::cout << hwiFile.rdbuf();
            hwiFile.close();
        } else {
            std::cout << "Failed to open hwiFile ...\n";
        }

        hwoFile.close();
    } else {
        std::cout << "Failed to open hwoFile ...\n";
    }

    return 0;
}
