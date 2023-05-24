//-------------------------------------------------------------------------------------------------------------
// Group names: Harboyan, David and Albalas, Emad
// Assignment:  No.7
// Due date:    03/23/2023
// Purpose:     This program traces inputted strings to make sure it follows the given grammer.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string userInput;
    char currentState, currentRead;
    int state, terminal, pushItems;
    stack<char> currentStack;
    
    // create parse table
    int parseTable[5][8] = {
        {100, 0, 0, 0, 0, 100, 0, 0},
        {0, 101, 102, 0, 0, 1, 500, 500},
        {200, 3, 3, 0, 0, 200, 0, 2},
        {1, 500, 500, 201, 202, 1, 500, 500},
        {400, 0, 0, 3, 3, 300, 0, 2}
    };

    // ask user for input and store in variable
    cout << "Enter string with ending with $: " << endl;
    cin >> userInput;
    
    // check to make sure user gave correct input, and if not throw error
    if (userInput[userInput.length() - 1] == '$') {
        currentStack.push('$');
        currentStack.push('E');
    } else {
        throw invalid_argument("User input doesnt contain $");
    }

    // loop through the input character by character
    for (int i = 0; i < userInput.length(); i++) {
        // store character in variable
        currentRead = userInput[i];
        // store current currentState and then pop
        currentState = currentStack.top();
        currentStack.pop();
        // use while loop to search through table until you find currentRead == currentState
        while (currentRead != currentState) {
            switch(currentRead) {
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
            }
            switch(currentState) {
                case 'E':
                    state = 0;
                    break;
                case 'Q':
                    state = 1;
                    break;
                case 'T':
                    state = 2;
                    break;
                case 'R':
                     state = 3;
                     break;
                case 'F':
                    state = 4;
                    break;
            }
            // store value from table using the state and terminal and perform necessary actions
            pushItems = parseTable[state][terminal];
            switch (pushItems) {
                // if user input is rejected
                case 0:
                    cout << "This string is rejected!" << endl;
                    return 0;
                // if user input is missing operator
                case 1:
                    cout << "Operator missing!" << endl;
                    return 0;
                // if user input is missing parantheses
                case 2:
                    cout << "Parantheses missing!" << endl;
                    return 0;
                case 3:
                    cout << "Too many operators!" << endl;
                    return 0;
                case 100:
                    currentStack.push('Q');
                    currentStack.push('T');
                    break;
                case 101:
                    currentStack.push('Q');
                    currentStack.push('T');
                    currentStack.push('+');
                    break;
                case 102:
                    currentStack.push('Q');
                    currentStack.push('T');
                    currentStack.push('-');
                    break;
                case 200:
                    currentStack.push('R');
                    currentStack.push('F');
                    break;
                case 201:
                    currentStack.push('R');
                    currentStack.push('F');
                    currentStack.push('*');
                    break;
                case 202:
                    currentStack.push('R');
                    currentStack.push('F');
                    currentStack.push('/');
                    break;
                case 300:
                    currentStack.push(')');
                    currentStack.push('E');
                    currentStack.push('(');
                    break;
                case 400:
                    currentStack.push('i');
                    break;
                // if lambda then dont do anything since we pop the currentStack earlier
                case 500:
                    break;
            }
            // grab new current state and pop
            currentState = currentStack.top();
            currentStack.pop();
            // check if current state and current read are equal. if so then print current currentStack
            if (currentState == currentRead) {
                cout << "Match found for: " << currentRead << endl;
                stack<char> temp = currentStack;
                int stackSize = currentStack.size();
                string content[stackSize];
                for (int i = 0; i < stackSize; i++) {
                    content[i] = temp.top();
                    temp.pop();
                }
                cout << "Stack content: ";
                for (int j = 0; j < stackSize; j++) {
                    cout << content[j] << " ";
                    if (j == stackSize - 1) {
                        cout << "\n" << endl;
                    }
                }
                if (content->empty()) {
                    cout << "\n" << "This string is accepted!" << endl;
                }
            }
        }
    }  
    return 0;
}