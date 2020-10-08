#include <iostream>
#include <fstream>
#include <vector>

std::string get_rand_word(std::vector<std::string> words)
{
    std::string word;
    int rand_word_index = rand() % words.size();

    for (int i = 0; i < words.size(); i++) {
        if (i == rand_word_index) {
            word = words.at(i);
            break;
        }
    }

    return word;
}

std::vector<std::string> load_words()
{
    std::string word;
    std::vector<std::string> words;
    std::ifstream word_list("words.txt");

    if (word_list.is_open()) {
        while (word_list >> word) {
            words.push_back(word);
        }
    } else {
        printf("Failed to open words.txt ...\n");
        exit(1);
    }

    return words;
}

int main()
{
    srand(time(NULL));
    std::vector<std::string> words = load_words();
    std::string guess;
    int total = 0;
    int total_correct = 0;
    int time_limit = time(NULL) + 10;

    while (time(NULL) < time_limit) {
        total++;
        std::string rand_word = get_rand_word(words);
        std::cout << rand_word << std::endl;
        std::cin >> guess;
        if (guess == rand_word) {
            total_correct++;
        }
    }

    printf("You got %d out of %d correct!\n", total_correct, total);
    return 0;
}