#include <iostream>
#include <string>
#include <cstdlib> // For system("pause")

int main() {
    // Title Screen
    std::cout << "Welcome to Alice in Wonderland Text Adventure!" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // ASCII art for Alice
    std::cout << R"(
               .--.
              |  |
           .--|  |.--.
           |  |  |  |  |
           |  |--|  |--|
           |  |__|__|__|
           `--'       )";
    std::cout << std::endl;

    std::cout << "You are Alice, a young girl who fell down a rabbit hole into Wonderland." << std::endl;
    std::cout << "Your goal is to find your way back home, but first, you need to explore this magical world." << std::endl;
    std::cout << "Let's begin the adventure!" << std::endl;

    // Initialize variables
    int drinkMe = 0;
    int eatMe = 0;
    bool drinkPotion = false;
    bool shrink = false;
    bool grow = false;
    bool hasKey = false;
    bool hasCake = false;

    // Start of the adventure
    std::cout << "\nYou find yourself in a beautiful garden. In front of you, there is a small door." << std::endl;
    std::cout << "What would you like to do?" << std::endl;

    while (!hasKey) {
        std::string choice;
        std::cout << "\nOptions:\n1. Try to open the small door.\n2. Look around for a key.\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") {
            if (hasKey) {
                std::cout << "\nYou use the key to open the small door, and it leads to a beautiful meadow." << std::endl;
                break;
            } else {
                std::cout << "\nThe door is locked. You need to find a key to open it." << std::endl;
            }
        } else if (choice == "2") {
            std::cout << "\nYou search the area and find a small key hidden behind a bush." << std::endl;
            hasKey = true;
        } else {
            std::cout << "\nInvalid choice. Please select again." << std::endl;
        }
    }

    // ASCII art for the beautiful meadow
    std::cout << R"(
           _.---._    /\\
        ./'       "--`\//
      ./              o \
     /./\  )______   \__ \
    ./  / /\ \   | \ \  \ \
       / /  \ \  | |\ \  \7
        "     "    "  "   ")";
    std::cout << std::endl;

    // Continue the adventure
    std::cout << "\nYou enter the beautiful meadow and see a tiny glass bottle labeled 'Drink Me' and a small cake labeled 'Eat Me'." << std::endl;

    while (!drinkPotion) {
        std::string choice;
        std::cout << "\nOptions:\n1. Drink from the 'Drink Me' bottle.\n2. Eat the 'Eat Me' cake.\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") {
            if (drinkMe < 3) {
                drinkMe++;
                std::cout << "\nYou drink from the 'Drink Me' bottle and shrink!" << std::endl;
                shrink = true;
            } else {
                std::cout << "\nThe bottle is empty. You have already drunk enough." << std::endl;
            }
        } else if (choice == "2") {
            if (eatMe < 3) {
                eatMe++;
                std::cout << "\nYou eat the 'Eat Me' cake and grow!" << std::endl;
                grow = true;
            } else {
                std::cout << "\nThe cake is gone. You have already eaten enough." << std::endl;
            }
        } else {
            std::cout << "\nInvalid choice. Please select again." << std::endl;
        }

        if (shrink && grow) {
            std::cout << "\nUh oh! You've both shrunk and grown at the same time! You are now back to your original size." << std::endl;
            shrink = false;
            grow = false;
        }

        if (shrink) {
            std::cout << "\nYou are now small enough to fit through a small hole in the hedge." << std::endl;
        }

        if (grow) {
            std::cout << "\nYou are now tall enough to reach a high branch in a tree." << std::endl;
        }

        if (shrink && hasCake) {
            std::cout << "\nYou are small enough to enter a small door on the side of the meadow." << std::endl;
            std::cout << "You use the key to unlock it, and it leads to a dark room." << std::endl;
            break;
        }
    }

    // ASCII art for the dark room
    std::cout << R"(
      .   +   .        .       .   . .  +  .
  .           .     .       .     . .       .  .
        .  .    .    .      .   .      .
 .  .       .    .   .      .   .     .     .
           +         .  .     .     .         .
   .     +    .      .      .       .    .  +    .
       .     .  .       .    .      .     .     .
..   .. +..  ..  .. +..  ..  .. +..  ..  .. +..  ..)";
    std::cout << std::endl;

    // Continue the adventure
    std::cout << "\nYou find yourself in a dark room. There are two doors in front of you." << std::endl;
    std::cout << "One door is labeled 'Drink Me,' and the other is labeled 'Eat Me.'" << std::endl;

    while (true) {
        std::string choice;
        std::cout << "\nOptions:\n1. Drink from the 'Drink Me' bottle.\n2. Eat the 'Eat Me' cake.\nYour choice: ";
        std::cin >> choice;

        if (choice == "1") {
            std::cout << "\nYou drink from the 'Drink Me' bottle and suddenly grow tall!" << std::endl;
            grow = true;
            break;
        } else if (choice == "2") {
            std::cout << "\nYou eat the 'Eat Me' cake and suddenly shrink!" << std::endl;
            shrink = true;
            break;
        } else {
            std::cout << "\nInvalid choice. Please select again." << std::endl;
        }
    }

    if (shrink) {
        // ASCII art for the beautiful garden with the small door
        std::cout << R"(
      .       .  .     .      .      .  .
    .     .       .    .   .     .    .
  .     .  .       .   .    .  .       .
  .      .   .  __..--''"`--..__  .      .
      .     .  `-._  /\  _.-'  .    .
 .       .  .   `-'/  \'-'  .  .  .     .
      .    .  .    /  :  \    .  .    .
    .     .  .   .'   .   `.   .  .     .
            .     . .     .     .    .
  .       .     .   .    .     .     .  .
.           .      . .  .     .       .
        .     .    .    .   .     .    .
    .       .  .     . . .    .  .      .
                      )";
        std::cout << std::endl;
        std::cout << "\nYou are small enough to fit through the small door. You use the key to open it." << std::endl;
        std::cout << "The door leads to a beautiful garden with colorful flowers." << std::endl;
    } else if (grow) {
        // ASCII art for the tree with the high branch
        std::cout << R"(
      +      .      .      .    .
  .          .      .     .     .      .
       .       .     .    .    .
    .     .  +       .       .       .
      .  .     .    .      .     .
 .           .       .     .        .
   .  .  +  .     .   .   .    .  )";
        std::cout << std::endl;
        std::cout << "\nYou are tall enough to reach a high branch in a tree." << std::endl;
        std::cout << "You climb up the tree and find a magical portal." << std::endl;
        std::cout << "You step through the portal and find yourself back in the real world." << std::endl;
    }

    std::cout << "\nCongratulations! You've successfully completed the Alice in Wonderland Text Adventure!" << std::endl;
    std::cout << "Thank you for playing!" << std::endl;

    // Pause the program to see the final message
    system("pause");
    return 0;
}
