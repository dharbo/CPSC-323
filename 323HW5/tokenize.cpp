//-------------------------------------------------------------------------------------------------------------
// Group names: Harboyan, David and Albalas, Emad
// Assignment:  No.5
// Due date:    03/02/2023
// Purpose:     This tokenizes a text file, h5.txt. It removes comments, blank lines, and extra spaces
//              and writes the resultant content to a new text file, newh5.txt.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {

    // Read and store tokens from h5.txt.
    std::ifstream file("h5.txt");
    std::vector<std::string> filetokens;

    std::string token;
    while (file >> token) {
        filetokens.push_back(token);
    }
    file.close();

    // Store tokens that are not comments.
    std::vector<std::string> tokens;
    bool comment = false;
    for (std::string token : filetokens) {
        // Flag when there is a comment.
        if (token == "**") {
            if (comment) {
                comment = false;
            } else {
                comment = true;
            }
        }
        // Add to vector when token is not a comment.
        if (!comment && token != "**") {
            tokens.push_back(token);
        }
    }

    // Create and write to newh5.txt.
    std::ofstream newfile("newh5.txt");
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "var" || tokens[i] == "begin") {
            // Write var or begin, and add newline with indent to file.
            newfile << tokens[i] << "\n    ";
        } else if (tokens[i] == "end.") {
            // Write end. to file.
            newfile << tokens[i];
        } else if (tokens[i][tokens[i].size()-1] == ';') {
            if (tokens[i+1] == "var" || tokens[i+1] == "begin" ||tokens[i+1] == "end.") { 
                // Write ;, and add newline to file.
                newfile << tokens[i] << "\n";
            } else { 
                // Write ;, and add newline with indent to file.
                newfile << tokens[i] << "\n    ";
            }
        } else { 
            // Write token with single space to file.
            newfile << tokens[i] << " ";
        }
    }
    newfile.close();
    return 0;
}