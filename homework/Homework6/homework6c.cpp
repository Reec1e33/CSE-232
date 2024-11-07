#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> makePair(const std::string &s) {
  std::string x, y;
  std::string::size_type comma = s.find(',');
  std::vector<int> output;
  for (std::string::size_type i = 0; i < s.size() - 1; ++i) {
    bool inFirstNum((i > 0) && (i < comma) && (s.at(i) != '('));
    bool inSecondNum((inFirstNum == false) && (s.at(i) != ',') &&
                     (s.at(i) != ')'));

    if (inFirstNum) {
      x += s.at(i);

    } else if (inSecondNum && (s.at(i) != '(') && (s.at(i) != ')')) {
      y += s.at(i);
    }
  }
  if ((x != "") && (y != "")) {
    output.push_back(std::stoi(x));
    output.push_back(std::stoi(y));
  }
  return output;
}

int GetPrice(std::vector<std::vector<int>> vec2, int x, int y) {
  int xcoord = x;
  int ycoord = 9 - y;
  int price = 55 + (5 * y);
  for (std::vector<int> vec1 : vec2) {
    if ((vec1.at(0) == xcoord) && (vec1.at(1) == ycoord)) {
      return -10;
    }
    if (((vec1.at(0) == xcoord + 1) && (vec1.at(1) == ycoord)) ||
        ((vec1.at(0) == xcoord - 1) &&
         (vec1.at(1) ==
          ycoord))) {  // if the x,y point is within 1 x value east or west
      price -= 40;
    } else if (((vec1.at(0) == xcoord) && (vec1.at(1) == ycoord + 1)) ||
               ((vec1.at(0) == xcoord) &&
                (vec1.at(1) == ycoord - 1))) {  // if the x,y point is within 1
                                                // y value north or south
      price -= 40;

    } else if (((vec1.at(0) == xcoord + 2) && (vec1.at(1) == ycoord)) ||
               ((vec1.at(0) == xcoord - 2) &&
                (vec1.at(1) == ycoord))) {  // if the x,y point is within 2 x
                                            // value north or south
      price -= 20;
    } else if (((vec1.at(0) == xcoord) && (vec1.at(1) == ycoord + 2)) ||
               ((vec1.at(0) == xcoord) &&
                (vec1.at(1) == ycoord - 2))) {  // if the x,y point is within 2
                                                // y value north or south
      price -= 20;

    } else if (((vec1.at(0) == xcoord + 1) && (vec1.at(1) == ycoord + 1)) ||
               ((vec1.at(0) == xcoord - 1) &&
                (vec1.at(1) ==
                 ycoord - 1))) {  // if the x,y point is within diagonal x + 1
                                  // and y + 1 or x - 1 and y - 1
      price -= 20;
    } else if (((vec1.at(0) == xcoord + 1) && (vec1.at(1) == ycoord - 1)) ||
               ((vec1.at(0) == xcoord - 1) &&
                (vec1.at(1) ==
                 ycoord + 1))) {  // if the x,y point is within diagonal x + 1
                                  // and y - 1 or x - 1 and y + 1;
      price -= 20;
    }
  }
  return price;
}

int main() {
  int length = 20;
  int width = 10;
  int value = 100;
  int iteration = 0;
  std::string input{};
  std::vector<std::string> vec1;
  std::vector<std::vector<int>> vec2;

  while (std::getline(std::cin, input)) {
    vec1.push_back(input);
  }

  for (std::string s : vec1) {
    vec2.push_back(makePair(s));
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 20; ++j) {
      int price = GetPrice(vec2, j, i);
      if (price == -10) {
        std::cout << std::setw(4) << "*" << ",";
      } else {
        std::cout << std::setw(4) << price << ",";
      }
    }
    std::cout << std::endl;
  }
}