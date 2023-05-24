//-------------------------------------------------------------------------------------------------------------
// Group names: Albalas, Emad and Harboyan, David
// Assignment:  No.1
// Due date:    02/02/2023
// Purpose:     This program reads an expression in postfix form, evaluates the expression
//              and displays its value.
//-----------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stack>

// Evaluates a postfix expression.
int evaluate_postfix(std::string &expression) {
    
    // Create stack to keep track of the values/integers in the expression.
    std::stack<int> stack;

    // Initialize index counter.
    int index = 0;

    // Loop through each character in the expression until the '$' character.
    while (expression[index] != '$') {

        char ch = expression[index];

        // Have a case for each character in the expression.
        switch (ch) {

            // If the character is a mathematical operator (+, -, *, /),
            // then get and pop the top two values in the stack,
            // and push the result of performing that operation on 
            // those two values.

            case '+': 
                    {
                    int num1 = stack.top();
                    stack.pop();
                    int num2 = stack.top();
                    stack.pop();

                    stack.push(num2 + num1);

                    }
                    break;

            case '-': 
                    {
                    int num1 = stack.top();
                    stack.pop();
                    int num2 = stack.top();
                    stack.pop();

                    stack.push(num2 - num1);

                    }
                    break;

            case '*':
                    {
                    int num1 = stack.top();
                    stack.pop();
                    int num2 = stack.top();
                    stack.pop();

                    stack.push(num2 * num1);

                    }
                    break;
            
            case '/':
                    {
                    int num1 = stack.top();
                    stack.pop();
                    int num2 = stack.top();
                    stack.pop();

                    stack.push(num2 / num1);

                    }
                    break;

            // If the character is a, b, c, or d, then push that
            // character's value (a = 5, b = 7, c = 2, d = 4).

            case 'a':
                    stack.push(5);
                    break;

            case 'b':
                    stack.push(7);
                    break;

            case 'c':
                    stack.push(2);
                    break;

            case 'd':
                    stack.push(4);
                    break;

            // Throw an execption if there is a character within the expression
            // that is not a mathematical operator (+, -, *, /) or the characters
            // a, b, c, or d before the '$' character.

            default: 
                    throw std::invalid_argument("Invalid character within the expression.");

        }

        // Increment the index counter.
        index++;
    }

    // Return the value at the top of the stack, which holds the result of the expression.
    return stack.top();
}

int main() {

    // Keep asking user to enter a postfix expression.
    while (true) {

        // Store the user's expression in a variable.
        std::string expression;
        std::cout << "Enter a postfix expression with $ at the end: ", std::cin >> expression;

        // Store the result of evaluate_postfix in a variable.
        int value = evaluate_postfix(expression);

        // Display the result.
        std::cout << "     Value = " << value << std::endl;

        // Get whether or not the user wants to enter another expression.
        char choice;
        std::cout << "CONTINUE(y/n)? ", std::cin >> choice;

        // If user enters 'n', the program will end.
        if (choice == 'n') {
            break;
        }

    }

    return 0;
}