#include <iostream>
#include <time.h>

void Play();
bool Again();

int main() {
    bool doAgain;

    do {
        system("clear");
        Play();
        doAgain = Again();
    } while (doAgain == 1);

    return 0;
}

void Play() {
    srand(time(NULL)); // Setting the seed
    int rngNum = rand() % 10; // Generate random number between 0-10
    int guesses = 0;
    int guess = -1;

    do {
        std::cout << "Guess: ";
        std::cin >> guess;

        if (guess != rngNum) {
            if (guess > rngNum) {
                std::cout << "Guess was too high!\n";
            } else {
                std::cout << "Guess was too low!\n";
            }
            guesses++;
        } else {
            guesses++;
            std::cout << "You win! It took you " << guesses << " guesses.\n";
        }
    } while (guess != rngNum);
}

bool Again() {
    char ans = 'n';
    
    std::cout << "Play again? [y/N]: ";
    std::cin >> ans;

    if (ans == 'y') {
        return true;
    }
            
    system("clear");
    return false;
}