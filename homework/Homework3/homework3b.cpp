#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    string output;
    int value;
    
    while (getline(cin, line)) {
        output = "";  // Start with an empty output string.
        output += line[0];  // Always output the first character.
        value = static_cast<int>(line[0]);  // ASCII value of the first character.
        
        for (int i = 1; i < line.size(); i++) {
            if (static_cast<int>(line[i]) > value) {
                output += line[i];  // Append character if its ASCII value is larger.
                value = static_cast<int>(line[i]);  // Update the value to the new character's ASCII value.
            } else if ( line[i] == ' ') {
                output += "_";
            } else {
                output += "_";  // Replace with underscore if less than or equal.
                value = static_cast<int>(line[i]);  // Update the value even for underscores.
            }
        }
        
        cout << output << endl;  // Output the processed line.
    }

    return 0;
}
