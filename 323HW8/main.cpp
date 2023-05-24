#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string userInput;
    char currentState, currentRead, pushItems;
    int state, terminal;
    stack<char> currentStack;

    // create parse table
    int parseTable[16][11] = {
        {25, 0, 0, 0, 0, 24, 0, 0, 1, 2, 3},
        {0, 26, 27, 0, 0, 0, 0, 100, 0, 0, 0},
        {0, 33, 33, 28, 29, 0, 33, 33, 0, 0, 0},
        {0, 36, 36, 36, 36, 0, 36, 36, 0, 0, 0},
        {25, 0, 0, 0, 0, 24, 0, 0, 10, 2, 3},
        {0, 38, 38, 38, 38, 0, 38, 38, 0, 0, 0},
        {25, 0, 0, 0, 0, 25, 0, 0, 0, 11, 3},
        {25, 0, 0, 0, 0, 24, 0, 0, 0, 12, 3},
        {25, 0, 0, 0, 0, 24, 0, 0, 0, 0, 13},
        {25, 0, 0, 0, 0, 24, 0, 0, 0, 0, 14},
        {0, 26, 27, 0, 0, 0, 23, 0, 0, 0, 0},
        {0, 31, 31, 28, 29, 0, 31, 31, 0, 0, 0},
        {0, 32, 32, 28, 29, 0, 32, 32, 0, 0, 0},
        {0, 34, 34, 34, 34, 0, 34, 34, 0, 0, 0},
        {0, 35, 35, 35, 35, 0, 35, 35, 0, 0, 0},
        {0, 37, 37, 37, 37, 0, 37, 37, 0, 0, 0},
        };

    // ask user for input and store in variable
    cout << "Enter string with ending with $: " << endl;
    cin >> userInput;

    // check to make sure user gave correct input, and if not throw error
    if (userInput[userInput.length() - 1] == '$') {
        currentStack.push(0);
    } else {
        throw invalid_argument("User input doesnt contain $");
    }

    // loop through the input character by character
    for (int i = 0; i < userInput.length(); i++)
    {
        // store character in variable
        currentRead = userInput[i];
        // store state and then pop
        state = currentStack.top();
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
        currentStack.push(state);
        while (pushItems > 29 || pushItems < 22) {
                pushItems = parseTable[state][terminal];
                switch (pushItems) {
                    // if user input is rejected
                    case 0:
                        cout << "This string is rejected!" << endl;
                        return 0;
                    // for terminal
                    case 1:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 2:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 3:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 10:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 11:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 12:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 13:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    case 14:
                        currentStack.push(terminal);
                        currentStack.push(pushItems);
                        break;
                    // for non-terminal
                    case 24:
                        currentStack.push('(');
                        currentStack.push(4);
                        break;
                    case 25:
                        currentStack.push('i');
                        currentStack.push(5);
                        break;
                    case 26:
                        currentStack.push('+');
                        currentStack.push(6);
                        break;
                    case 27:
                        currentStack.push('-');
                        currentStack.push(7);
                        break;
                    case 28:
                        currentStack.push('*');
                        currentStack.push(8);
                        break;
                    case 29:
                        currentStack.push('/');
                        currentStack.push(9);
                        break;
                    case 23:
                        currentStack.push(')');
                        currentStack.push(15);
                        break;
                    // for row cases
                    case 31:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][8];
                        currentStack.push(state);
                        currentStack.push('E');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 32:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][8];
                        currentStack.push(state);
                        currentStack.push('E');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 33:
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][8];
                        currentStack.push(state);
                        currentStack.push('E');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 34:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][9];
                        currentStack.push(state);
                        currentStack.push('T');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 35:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][9];
                        currentStack.push(state);
                        currentStack.push('T');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 36:
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][9];
                        currentStack.push(state);
                        currentStack.push('T');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 37:
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][10];
                        currentStack.push(state);
                        currentStack.push('F');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    case 38:
                        currentStack.pop();
                        currentStack.pop();
                        state = currentStack.top();
                        currentStack.pop();
                        pushItems = parseTable[state][10];
                        currentStack.push(state);
                        currentStack.push('F');
                        currentStack.push(pushItems);
                        state = currentStack.top();
                        break;
                    // accept case
                    case 100:
                        cout << "This string is accepted" << endl;
                        return 0;
                }
        }
        stack<char> temp = currentStack;
        int stackSize = currentStack.size();
        cout << "Stack content: ";
        for (int j = 0; j < stackSize; j++) {
            if (temp.top() >= 0 && temp.top() < 10){
                char c = temp.top() + '0';
                temp.pop();
                cout << c << " ";
            }
            else if (temp.top() > 9 && temp.top() < 15){
                if (temp.top() == 10) {
                    cout << 10 << " ";
                    temp.pop();
                }
                else if (temp.top() == 11){
                    cout << 11 << " ";
                    temp.pop();
                }
                else if (temp.top() == 12) {
                    cout << 12 << " ";
                    temp.pop();
                }
                else if (temp.top() == 13) {
                    cout << 13 << " ";
                    temp.pop();
                }
                else {
                    cout << 14 << " ";
                    temp.pop();
                }
            }
            else {
                cout << temp.top() << " ";
                temp.pop();
            }
            if (j == stackSize - 1) {
                cout << "\n"
                     << endl;
            }
        }
    }
    return 0;
}