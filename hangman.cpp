#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Maximum number of wrong guesses
const int maxWrongGuesses = 6;

// Word to guess
string word = "PROGRAMMING";
string guessedWord(word.size(), '_');
vector<char> guessedLetters;
int wrongGuesses = 0;

// ASCII art for the hangman stages
void drawHangman(int stage) {
    string hangmanArt[] = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };

    cout << hangmanArt[stage] << endl;
}

// Function to display the current guessed word
void displayGuessedWord() {
    for (char c : guessedWord) {
        cout << c << ' ';
    }
    cout << endl;
}

// Function to check if the letter was already guessed
bool isAlreadyGuessed(char letter) {
    return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
}

// Main game logic
int main() {
    cout << "Welcome to Hangman!" << endl;
    drawHangman(wrongGuesses);

    while (wrongGuesses < maxWrongGuesses && guessedWord != word) {
        displayGuessedWord();
        cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            cout << letter << ' ';
        }
        cout << endl;

        // Get user input
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        guess = toupper(guess);

        if (isAlreadyGuessed(guess)) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        // Check if the guessed letter is in the word
        bool correct = false;
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            wrongGuesses++;
            cout << "Wrong guess!" << endl;
        } else {
            cout << "Correct guess!" << endl;
        }

        drawHangman(wrongGuesses);
    }

    // Game over
    if (guessedWord == word) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "You lost! The word was: " << word << endl;
    }

    return 0;
}

