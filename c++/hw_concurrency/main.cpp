#include <iostream>
#include <thread>
#include <vector>

void printSomething(int i) {
    std::cout << "Hello world from C++ concurrency number " << i << std::endl;
}

// Compile with g++ -o main main.cpp -lpthread
int main() {
   std::vector<std::thread> t;

   for (int i = 0; i < 7; i++) {
       t.push_back(std::thread(printSomething, i));
   }

   for (int i = 0; i < 7; i++) {
       t[i].join();
   }

    return 0;
}
