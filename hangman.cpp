#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// function to display the hangman figure
void displayHangman(int wrongGuesses) {
    switch (wrongGuesses) {
    case 0:
        std::cout << "   _______     \n";
        std::cout << "  |       |    \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << " _|_           \n\n";
        break;

    case 1:
        std::cout << "   _______     \n";
        std::cout << "  |       |    \n";
        std::cout << "  |       O    \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << " _|_           \n\n";
        break;

    case 2:
        std::cout << "   _______     \n";
        std::cout << "  |       |    \n";
        std::cout << "  |       O    \n";
        std::cout << "  |      /|    \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << " _|_           \n\n";
        break;

    case 3:
        std::cout << "   _______     \n";
        std::cout << "  |       |    \n";
        std::cout << "  |       O    \n";
        std::cout << "  |      /|\\  \n";
        std::cout << "  |            \n";
        std::cout << "  |            \n";
        std::cout << " _|_           \n\n";
        break;

    case 4:
        std::cout << "   _______     \n";
        std::cout << "  |       |    \n";
        std::cout << "  |       O    \n";
        std::cout << "  |      /|\\  \n";
        std::cout << "  |      /     \n";
        std::cout << "  |            \n";
        std::cout << " _|_           \n\n";
        break;

    case 5:
        std::cout << "   _______     \n";
        std::cout << "  |       |    \n";
        std::cout << "  |       O    \n";
        std::cout << "  |      /|\\  \n";
        std::cout << "  |      / \\  \n";
        std::cout << "  |            \n";
        std::cout << " _|_           \n\n";
        break;
    }
}


// displays state of the word 
void displayWord(const std::string& word, const std::vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            std::cout << word[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main() {
    const std::vector<std::string> wordList = {"Ant", "Hawk", "Tiger", "Sigma", "Pig", "Rabbit", "River", "Sugar", "Goose", "Fish", "Turkey", "Toad", "Snake", "Zebra", "Iron", "Dirt", "Gold", "School", "Crow", "Spider"};
    srand(time(0));
    std::string word = wordList[rand() % wordList.size()];  // Selects a word from the list
    std::vector<bool> guessed(word.length(), false);
    int wrongGuesses = 0;
    const int maxGuesses = 6;

    std::cout << "HANGMAN" << std::endl;

    while (wrongGuesses < maxGuesses) {
        displayHangman(wrongGuesses);
        displayWord(word, guessed);

        std::cout << "Enter a letter: ";
        char guess;
        std::cin >> guess;

        bool correctGuess = false;
        for (size_t i = 0; i < word.length(); i++) {
            if (tolower(word[i]) == tolower(guess) && !guessed[i]) {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            wrongGuesses++;
            std::cout << "Wrong! You've got " << maxGuesses - wrongGuesses << " guesses left." << std::endl;
        }

        bool wordComplete = true;
        for (bool letterGuessed : guessed) {
            if (!letterGuessed) {
                wordComplete = false;
                break;
            }
        }
        if (wordComplete) {
            displayWord(word, guessed);
            std::cout << "Congrats! You've guessed the word!" << std::endl;
            break;
        }
    }

    if (wrongGuesses == maxGuesses) {
        displayHangman(wrongGuesses);
        std::cout << "Sorry, you've lost. The word was: " << word << std::endl;
    }

    return 0;
}
