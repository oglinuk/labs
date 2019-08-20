#include <iostream>
#include <time.h>

void play();
int32_t getGuess();
bool again();

int main() {
    bool doAgain;

    while(doAgain == 1){
        system("clear");
        play();
        doAgain = again();
    };

    return 0;
}

void play() {
    srand(time(NULL)); // Setting the seed
    int32_t rngNum = rand() % 10; // Generate random number between 0-10
    int32_t guesses = 0;
    int32_t guess = -1;

     while(guess != rngNum) {
        guess = getGuess();

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
    };
}

int32_t getGuess() {
    int32_t guess = -1;

    std::cout << "Guess: ";
    std::cin >> guess;

    while(std::cin.fail()) {
        std::cout << "Please enter a number ...\n";
        std::cin.clear(); // Unset failbit; see std::cin.fail()

        // https://en.cppreference.com/w/cpp/io/basic_istream/ignore
        std::cin.ignore(256,'\n');
    }

    return guess;
}

bool again() {
    char ans = 'n';
    
    std::cout << "Play again? [y/N]: ";
    std::cin >> ans;

    if(std::tolower(ans) == 'y') {
        return true;
    }
            
    system("clear");
    return false;
}