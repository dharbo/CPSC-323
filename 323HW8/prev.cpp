int main() {

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

    std::string input;
    std::cout << "Enter a string ending in $: ", std::cin >> input;

    std::stack<std::string> stack;

    if (input[input.length() - 1] == '$') {
        stack.push("0");
    } else {
        throw std::invalid_argument("User input doesnt contain $");
    }


    int i = 0;
    while (i < input.length()){

        // displayStack(stack);

        char read = input[i];
        // std::cout << read << "\n";

        int state = std::stoi(stack.top());
        stack.pop();

        int col;
        // Get the column # for the table based on terminal/non-terminal
        switch (read) {
        case 'i':
            col = 0;            
            break;
        case '+':
            col = 1;
            break;
        case '-':
            col = 2;
            break;
        case '*':
            col = 3;
            break;
        case '/':
            col = 4;
            break;
        case '(':
            col = 5;
            break;
        case ')':
            col = 6;
            break;
        case '$':
            col = 7;
            break;
        case 'E':
            col = 8;
            break;
        case 'T':
            col = 9;
            break;
        case 'F':
            col = 10;
            break;
        }

        // Execute whatever needs to be done based on table.
        bool notDone = true;
        while (notDone) {
            int action = parseTable[state][col];
            switch (action) {
                case 0:

                case 14:
                    stack.push(std::to_string(14));
                    stack.push("F");
                    stack.push(std::to_string(action));
                    // state = stack.pop();
                    break;
                    
                case 25:
                    stack.push(std::to_string(state)); // convert int to string
                    stack.push("i"); // we know this one is i bc of the case
                    stack.push("5"); // hard code, we know it would be S5
                    notDone = false;
                    break;


                case 38:
                    stack.push(std::to_string(state));
                    for (int i = 0; i < 2; ++i) { // pop 2x of rule 8
                        stack.pop();
                    }
                    state = std::stoi(stack.top());
                    stack.pop();
                    col = 10;
                    // stack.push(std::to_string(state));
                    // stack.push(std::to_string(col));
                    // stack.push(std::to_string(parseTable[state][col]));
                    break;
            }
        }


        // parseTable[state][col];

        std::cout << input << std::endl;
        displayStack(stack);
        ++i;
    }




    return 0;
}