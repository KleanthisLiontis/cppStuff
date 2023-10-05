#include <iostream>
#include "ufo_functions.hpp"


using std::string;

int main() {

    const string codeword {"codeacademy"};
    string answer {""};
    int misses = 0;
    std::vector<char> incorrect;
    bool guess {false};
    char letter;

    greet();
    while(misses < 7 && answer!= codeword) {
        
        display_status(incorrect,answer);
        display_misses(misses);
        std::cout << "\n\nPlease enter your guess: ";
        std::cin >> letter;

        end_game(answer,codeword);
        misses++;
    }
}
