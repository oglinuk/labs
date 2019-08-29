#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

void printSomething(int i) {
    // Not thread-safe to use printf
    // Also see https://en.wikipedia.org/wiki/Race_condition 
    std::cout << "Printing " << i << std::endl << std::endl;
}

void spawnThreads(int j) {
    std::vector<std::thread> t;

    for(int i = 0; i < j; i++) {
        int k = i; // See what happens when i is used in place of k
        t.push_back(std::thread(printSomething, k));
    }

    for(int i = 0; i < j; i++) {
        t[i].join();
    }
}

// Question: How many times will spawnThreads be called?
int main() {
    fork();
    fork();
    spawnThreads(3);
    
    return 0;
}
