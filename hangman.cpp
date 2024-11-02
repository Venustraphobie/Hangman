#include <iostream>
#include <string>
#include <vector>


void displayHangman(int wrongGuesses){
    switch (wrongGuesses)
    {
    case 0:
        std::cout << "   _______     " << std::endl;
        std::cout << "  |       |    " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << " _|_           " << std::endl << std::endl;
        break;

    case 1:
        std::cout << "   _______     " << std::endl;
        std::cout << "  |       |    " << std::endl;
        std::cout << "  |       O    " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << "  |            " << std::endl;
        std::cout << " _|_           " << std::endl << std::endl;
        break;
        
    case 2:
        std::cout << "   _______     \n" << std::endl;
        std::cout << "  |       |    \n" << std::endl;
        std::cout << "  |       O    \n" << std::endl;
        std::cout << "  |      /|    \n" << std::endl;
        std::cout << "  |            \n" << std::endl;
        std::cout << "  |            \n" << std::endl;
        std::cout << " _|_           " << std::endl << std::endl;
        break;

    case 3:
        cout << "   _______     \n";
        cout << "  |       |    \n";
        cout << "  |       O    \n";
        cout << "  |      /|    \n";
        cout << "  |            \n";
        cout << "  |            \n";
        cout << " _|_           \n\n";
        break;

    case 4:
        cout << "   _______     \n";
        cout << "  |       |    \n";
        cout << "  |       O    \n";
        cout << "  |      /|\\  \n";
        cout << "  |            \n";
        cout << "  |            \n";
        cout << " _|_           \n\n";
        break;

    case 5:
        cout << "   _______     \n";
        cout << "  |       |    \n";
        cout << "  |       O    \n";
        cout << "  |      /|\\  \n";
        cout << "  |      /     \n";
        cout << "  |            \n";
        cout << " _|_           \n\n";
        break;

    case 6:
        cout << "   _______     ";
        cout << "  |       |    ";
        cout << "  |       O    ";
        cout << "  |      /|\\  ";
        cout << "  |      / \\  ";
        cout << "  |            ";
        cout << " _|_           ";
        break;

    
    default:
        break;
    }
}

int main() {
    const std::vector<std::string> wordList = {"Venustraphobia", "Chromophobia", "Apple", "River", "Feather", "Mirror", "Spark", "Clock", "Sapphire", "Phoenix"};
    int attempts = 10;

    // Select a random word from the list
    std::string chosenWord = wordList[rand() % wordList.size()];

    while (attempts > 0) {
        std::cout << "*****HANGMAN******" << std::endl;
        std::cout << "Guess the word by entering a letter." << std::endl;
        std::cout << "You have " << attempts << " attempts left" << std::endl;
        std::vector<char> guessedWord(chosenWord.length(), '_');
        std::cin >> chosenWord;

        for (char c : guessedWord) {
            std::cout << c << ' ';
        }
        

        std::cout << "*****************" << std::endl;
    }

    // Additional code for handling the end of the game (e.g., win or lose)

    return 0;
}
