//-------------------------------------------------------------------------------------------------------------
// Group names: Harboyan, David and Albalas, Emad
// Assignment:  No.3
// Due date:    02/16/2023
// Purpose:     This program determines whether a user's input string is accepted or rejected by
//              the given grammer.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

int main() {

    while (true) {
        // Store input from the user.
        std::string input;
        std::cout << "Enter a string ending with '$': ", std::cin >> input;

        // Declare and initialize 2D array with values from transition table.
        int Table[4][3] = {{0, 1, 2}, {2, 1, 3},
                            {0, 3, 3}, {1, 3, 2}};
    
        int state = 0, i = 0, col = 0;

        // Loop through each character of the string.
        while (i < input.length()) {
            switch(input[i]) {
                case 'a': col= 0;
                            break;
                case 'b': col = 1;
                            break;
                case 'c': col = 2;
                            break;
                case '$': if (state == 1 || state == 2) { // If true, the string is accepted.
                            std::cout << input << " is accepted\n";
                        } else {
                            std::cout << input << " is rejected\n";
                        }
                        break;
            }
            // Go to the next state.
            state = Table[state][col];
            // Go to the next letter of the string.
            ++i;
        }
        // Get whether or not the user wants to enter another string.
        char choice;
        std::cout << "CONTINUE(y/n)? ", std::cin >> choice;

        // If user enters 'n', the program will end.
        if (choice == 'n') {
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}