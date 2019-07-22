#include <iostream>
#include <time.h>

using namespace std;

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
        cout << "Guess: ";
        cin >> guess;

        if (guess != rngNum) {
            if (guess > rngNum) {
                cout << "Guess was too high!\n";
            } else {
                cout << "Guess was too low!\n";
            }
            guesses++;
        } else {
            guesses++;
            cout << "You win! It took you " << guesses << " guesses.\n";
        }
    } while (guess != rngNum);
}

bool Again() {
    char ans = 'n';
    
    cout << "Play again? [y/N]: ";
    cin >> ans;

    if (ans == 'y') {
        return true;
    }
            
    system("clear");
    return false;
}