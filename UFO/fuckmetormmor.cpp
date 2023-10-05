#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to check if the player has guessed the entire word
bool isWordGuessed(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
            return false;
        }
    }
    return true;
}

// Function to display the current status of the word
void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to get a random codeword from a list
string getRandomCodeword() {
    vector<string> codewords = {
        "ASTRONAUT",
        "SPACESHIP",
        "GALAXY",
        "ALIEN",
        "PLANET",
        "TELESCOPE",
        "LUNAR",
        "INTERGALACTIC",
        "COMET",
        "ASTEROID"
    };

    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % codewords.size();
    return codewords[index];
}

int main() {
    cout << "Welcome to the Space Abduction Codeword Game!" << endl;
    cout << "=============================================" << endl;

    string codeword = getRandomCodeword();
    int maxAttempts = 7;
    vector<char> guessedLetters;

    while (maxAttempts > 0) {
        cout << "Codeword: ";
        displayWord(codeword, guessedLetters);

        if (isWordGuessed(codeword, guessedLetters)) {
            cout << "Congratulations! You've stopped the abduction!" << endl;
            break;
        }

        cout << "Attempts left: " << maxAttempts << endl;
        cout << "Guess a letter: ";
        char guess;
        cin >> guess;
        guess = toupper(guess);

        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You've already guessed this letter." << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (codeword.find(guess) == string::npos) {
            cout << "Incorrect guess! The aliens have abducted one more human." << endl;
            maxAttempts--;
        } else {
            cout << "Correct guess! You've saved a human!" << endl;
        }
    }

    if (!isWordGuessed(codeword, guessedLetters)) {
        cout << "Oh no! The aliens have abducted the last human. Earth is doomed!" << endl;
        cout << "The codeword was: " << codeword << endl;
    }

    return 0;
}
