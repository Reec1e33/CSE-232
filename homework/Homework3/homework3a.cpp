#include <iostream>
using namespace std;

int sum(int value) {
    int sum = 0;
    while (value > 0) {
        sum += value % 100;
        value /= 100;
        }
    return sum;
}

void additivePersistence(int value) {
    
    int numPersistence = 0;
    while (value >= 100) {
        value = sum(value);
        ++numPersistence;

    }
    cout << numPersistence << endl;
}

int main() {
	int value{0};
	while (std::cin >> value) {

        // WRITE YOUR CODE HERE
        if (value < 0) {
        break;
        }
        additivePersistence(value);
    }
    return 0;
}

        

            

            
            
        
		
