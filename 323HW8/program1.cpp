//-------------------------------------------------------------------------------------------------------------
// Group names: Harboyan, David and Albalas, Emad
// Assignment:  No.8
// Due date:    04/11/2023
// Purpose:     This program traces inputted strings to make sure it
//              follows the given grammer using an LR Parsing Table.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stack>

// Output the elements of the stack
void displayStack(std::stack<std::string> tempStack, std::string& input, int& index) {
    std::cout << "Input string: " << input.substr(index+1, input.length() - index)
                << std::endl;
    std::cout << "Stack contents: ";
    while (!tempStack.empty()) {
        std::string element = tempStack.top();
        tempStack.pop();
        std::cout << element << " ";
    }
    std::cout << "\n\n";
}

int main() {
    std::string userInput;
    char currentRead;
    int state, terminal, pushItems;
    std::stack<std::string> currentStack;

    // create parse table
    int parseTable[16][11] = {
        {25, 0, 0, 0, 0, 24, 0, 0, 1, 2, 3}, {0, 26, 27, 0, 0, 0, 0, 100, 0, 0, 0},
        {0, 33, 33, 28, 29, 0, 33, 33, 0, 0, 0}, {0, 36, 36, 36, 36, 0, 36, 36, 0, 0, 0},
        {25, 0, 0, 0, 0, 24, 0, 0, 10, 2, 3}, {0, 38, 38, 38, 38, 0, 38, 38, 0, 0, 0},
        {25, 0, 0, 0, 0, 25, 0, 0, 0, 11, 3}, {25, 0, 0, 0, 0, 24, 0, 0, 0, 12, 3},
        {25, 0, 0, 0, 0, 24, 0, 0, 0, 0, 13}, {25, 0, 0, 0, 0, 24, 0, 0, 0, 0, 14},
        {0, 26, 27, 0, 0, 0, 23, 0, 0, 0, 0}, {0, 31, 31, 28, 29, 0, 31, 31, 0, 0, 0},
        {0, 32, 32, 28, 29, 0, 32, 32, 0, 0, 0}, {0, 34, 34, 34, 34, 0, 34, 34, 0, 0, 0},
        {0, 35, 35, 35, 35, 0, 35, 35, 0, 0, 0},{0, 37, 37, 37, 37, 0, 37, 37, 0, 0, 0}};

    // ask user for input and store in variable
    std::cout << "Enter string with ending with $: ", std::cin >> userInput;
    std::cout << std::endl;

    // check to make sure user gave correct input, and if not throw error
    if (userInput[userInput.length() - 1] == '$') {
        currentStack.push(std::to_string(0));
    } else {
        throw std::invalid_argument("User input doesn't contain $");
    }

    // loop through the input character by character
    for (int i = 0; i < userInput.length(); i++)
    {
        // store character in variable
        currentRead = userInput[i];
        // store state and then pop
        state = std::stoi(currentStack.top());
        currentStack.pop();
        // reset pushitems to zero
        pushItems = 0;
        // get column index from current input char
        switch (currentRead) {
        case 'i':
            terminal = 0;
            break;
        case '+':
            terminal = 1;
            break;
        case '-':
            terminal = 2;
            break;
        case '*':
            terminal = 3;
            break;
        case '/':
            terminal = 4;
            break;
        case '(':
            terminal = 5;
            break;
        case ')':
            terminal = 6;
            break;
        case '$':
            terminal = 7;
            break;
        case 'E':
            terminal = 8;
            break;
        case 'T':
            terminal = 9;
            break;
        case 'F':
            terminal = 10;
            break;
        }
        currentStack.push(std::to_string(state));
        while (pushItems > 29 || pushItems < 22) {
                pushItems = parseTable[state][terminal];
                switch (pushItems) {
                    // if user input is rejected
                    case 0:
                        std::cout << "Read: " << currentRead << std::endl;
                        displayStack(currentStack, userInput, i);
                        std::cout << "This string is rejected!" << std::endl;
                        return 0;
                    // for terminal
                    case 1:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 2:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 3:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 10:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 11:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 12:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 13:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    case 14:
                        currentStack.push(std::to_string(terminal));
                        currentStack.push(std::to_string(pushItems));
                        break;
                    // for non-terminal
                    case 24:
                        currentStack.push("(");
                        currentStack.push("4");
                        break;
                    case 25:
                        currentStack.push("i");
                        currentStack.push("5");
                        break;
                    case 26:
                        currentStack.push("+");
                        currentStack.push("6");
                        break;
                    case 27:
                        currentStack.push("-");
                        currentStack.push("7");
                        break;
                    case 28:
                        currentStack.push("*");
                        currentStack.push("8");
                        break;
                    case 29:
                        currentStack.push("/");
                        currentStack.push("9");
                        break;
                    case 23:
                        currentStack.push(")");
                        currentStack.push("15");
                        break;
                    // for row cases
                    case 31:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][8];
                        currentStack.push(std::to_string(state));
                        currentStack.push("E");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 32:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][8];
                        currentStack.push(std::to_string(state));
                        currentStack.push("E");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 33:
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][8];
                        currentStack.push(std::to_string(state));
                        currentStack.push("E");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 34:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][9];
                        currentStack.push(std::to_string(state));
                        currentStack.push("T");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 35:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][9];
                        currentStack.push(std::to_string(state));
                        currentStack.push("T");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 36:
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][9];
                        currentStack.push(std::to_string(state));
                        currentStack.push("T");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 37:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][10];
                        currentStack.push(std::to_string(state));
                        currentStack.push("F");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    case 38:
                        currentStack.pop();
                        currentStack.pop();
                        state = std::stoi(currentStack.top());
                        currentStack.pop();
                        pushItems = parseTable[state][10];
                        currentStack.push(std::to_string(state));
                        currentStack.push("F");
                        currentStack.push(std::to_string(pushItems));
                        state = std::stoi(currentStack.top());
                        break;
                    // accept case
                    case 100:
                        std::cout << "Read: " << currentRead << std::endl;
                        displayStack(currentStack, userInput, i);
                        std::cout << "This string is accepted!" << std::endl;
                        return 0;
                }
        }
        // Output info for user.
        std::cout << "Read: " << currentRead << std::endl;
        displayStack(currentStack, userInput, i);
    }
    return 0;
}