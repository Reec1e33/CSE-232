#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string line;
    string output;
    while(getline(std::cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i]) && (i == 0 || !isalpha(line[i-1]))) {
                output += line[i];
            }
        }
    
    }
    cout << output << endl;
}


