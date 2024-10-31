#include <iostream>
#include <string>
#include <vector>

int main() {
    const std::vector<std::string> wordList = {"Venustraphobia", "Chromophobia", "Apple", "River", "Feather", "Mirror", "Spark", "Clock", "Sapphire", "Phoenix"};
    int attempts = 10;

    while (attempts > 0) {
        std::string chosenWord = wordList[rand() % wordList.size()]; // Choose a random word from the list
        std::cout << "*****HANGMAN******" << std::endl;
        std::cout << "Guess the word by entering a letter." << std::endl;
        std::cout << "You have " << attempts << " attempts left" << std::endl;
        std::cin >> chosenWord;
        std::vector<char> guessedWord(chosenWord.length(), '_');

        for (char c : guessedWord) {
            std::cout << c << ' ';
        }
        std::cout << std::endl;

        std::cout << "*****************" << std::endl;
    }

    // Additional code for handling the end of the game (e.g., win or lose)

    return 0;
}
