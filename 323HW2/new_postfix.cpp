//-------------------------------------------------------------------------------------------------------------
// Group names: Harboyan, David and Albalas, Emad
// Assignment:  No.2
// Due date:    02/09/2023
// Purpose:     This program reads an expression in postfix form, evaluates the expression
//              and displays its value. The expression may contain variables in addition to integers.
//-----------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

// Set of all letters, lowercase and uppercase.
const std::unordered_set<char> L = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
                                'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z'};
    
// Char representing the underscore character.
const char U = '_';

// Set of all digits, 0 - 9.
const std::unordered_set<int> D = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Evaluates a postfix expression that may contain variables and/or integers.
int evaluate(std::vector<std::string>& tokens) {

    // Create stack.
    std::stack<int> stack;

    // Loop through all token of the postfix expression.
    for (std::string token : tokens) {
        if (token[0] == U || L.find(token[0]) != L.end()) { // Token is a variable name.
            int input_value;
            std::cout << "  Enter the value of " << token << ": ", std::cin >> input_value;

            stack.push(input_value);
        } else if (D.find(token[0]) != D.end()) { // Token is an integer.
            int value = stoi(token);

            stack.push(value);
        } else if (token[0] == '+') { // Perform addition on top 2 elements of the stack.
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();

            stack.push(num2 + num1);
        } else if (token[0] == '-') { // Perform subtraction on top 2 elements of the stack.
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();

            stack.push(num2 - num1);
        } else if (token[0] == '/') { // Perform division on top 2 elements of the stack.
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();

            stack.push(num2 / num1);
        } else if (token[0] == '*') { // Perform multiplication on top 2 elements of the stack.
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();

            stack.push(num2 * num1);
        }
    }
    // Return the value at the top of the stack, which holds the result of the expression.
    return stack.top();
}

int main() {

    // Keep asking user to enter a postfix expression.
    while (true) {

        // Store the user's expression in a variable.
        std::string expression;
        std::cout << "Enter a postfix expression with $ at the end: \n";
        getline(std::cin, expression, '$');

        // Tokenize the expression, and store the tokens into a vector.
        std::stringstream sstream(expression);
        std::vector<std::string> tokens;
        std::string curr_string;
        while (getline(sstream, curr_string, ' ')) {
            tokens.push_back(curr_string);
        }

        // Call evaluate and store the result.
        int result = evaluate(tokens);

        // Display the result to the user.
        std::cout << "      Expression's value is " << result << std::endl;

        // Get whether or not the user wants to enter another expression.
        char choice;
        std::cout << "CONTINUE(y/n)? ", std::cin >> choice;
        std::cin.ignore();

        // If user enters 'n', the program will end.
        if (choice == 'n') {
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}