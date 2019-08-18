#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {    
    std::ofstream hwoFile("hwFiles.txt");
    std::ifstream hwiFile("hwFiles.txt");

    if (hwoFile.is_open()) {
        hwoFile << "Hello world from C++ hw_files!" << std::endl;

        if (hwiFile.is_open()) {
            std::cout << hwiFile.rdbuf();
            hwiFile.close();
        } else {
            std::cout << "Failed to open hwiFile" << std::endl;
        }

        hwoFile.close();
    } else {
        std::cout << "Failed to open hwoFile" << std::endl;
    }

    return 0;
}
