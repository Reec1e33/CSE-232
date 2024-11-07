#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::string Two_D_Vector_To_String(std::vector<std::vector<char>> vec){
  std::stringstream os;
  for(int i = 0; i < static_cast<int>(vec.size()); i++){
    for(int j = 0; j < static_cast<int>(vec.at(i).size()); j++){
      os << vec.at(i).at(j) << " ";
    }
    os << "\n";
  }
  return os.str();
}

// WRITE YOUR CODE HERE


std::vector<std::vector<char>> Counting_Spiral(int length) {
    int num = 0;
    int middle = length / 2;  // Start from the middle
    int x = middle, y = middle;

    // Initialize the 2D vector with '0'
    std::vector<std::vector<char>> vec1(length, std::vector<char>(length, '0'));
    vec1.at(y).at(x) = '0' + (num % 10);  // Place the center value
    ++num;

    int step = 1;  // Number of steps to move in one direction
    while (num < length * length) {
        // Move right, then up
        for (int i = 0; i < step && num < length * length; ++i) {
            x += 1;
            vec1.at(y).at(x) = '0' + (num % 10);
            ++num;
        }
        for (int i = 0; i < step && num < length * length; ++i) {
            y -= 1;
            vec1.at(y).at(x) = '0' + (num % 10);
            ++num;
        }

        ++step;  // Increase step size for next round

        // Move left, then down
        for (int i = 0; i < step && num < length * length; ++i) {
            x -= 1;
            vec1.at(y).at(x) = '0' + (num % 10);
            ++num;
        }
        for (int i = 0; i < step && num < length * length; ++i) {
            y += 1;
            vec1.at(y).at(x) = '0' + (num % 10);
            ++num;
        }

        ++step;  // Increase step size for the next round
    }

    return vec1;
}

int main() {
    int input;
    std::cin >> input;
    std::vector<std::vector<char>> input1 = Counting_Spiral(input);
    std::cout << Two_D_Vector_To_String(input1) << std::endl;
}
