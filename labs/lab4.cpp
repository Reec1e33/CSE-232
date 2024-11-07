#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

std::int64_t LocToDec(std::string const& loc) {
  int output{};
  for (char ch : loc) {
    int num;

    num = ch - 'a';
    output += pow(2, num);
  }
  return output;
}

std::string Abbreviate(std::string const& loc) {
  std::string output{};
  std::string str = loc;
  std::sort(str.begin(), str.end());

  bool repeat = true;
  if (loc == "") {
    repeat = false;
  }
  while (repeat == true) {
    std::string::size_type i = 0;
    output = "";
    while (i < str.size()) {
      std::sort(str.begin(), str.end());
      if (output.find(str.at(i)) == std::string::npos) {
        output += str.at(i);
        ++i;

      } else {
        output.replace(output.find(str.at(i)), 1, 1,
                       static_cast<char>(str.at(i) + 1));
        ++i;
      }
      std::sort(str.begin(), str.end());
    }
    std::sort(output.begin(), output.end());
    char prev{};
    for (char ch : output) {
      if (ch == prev) {
        repeat = true;
        str = output;
        break;
      } else {
        repeat = false;
      }
      prev = ch;
    }
  }
  std::sort(output.begin(), output.end());
  return output;
}

std::string DecToLoc(std::int64_t dec) {
  std::string output{};
  int num{};

  while (num != dec) {
    for (int i = 0; i < dec; i++)
      if (num + pow(2, i) <= dec) {
        output += 'a' + i;
        num = num + pow(2, i);
      }
  }
  return Abbreviate(output);
}

std::int64_t AddLoc(std::string const& loc1, std::string const& loc2) {
  std::string loca1 = Abbreviate(loc1);
  std::string loca2 = Abbreviate(loc2);
  int num1 = LocToDec(loca1);
  int num2 = LocToDec(loca2);
  return num1 + num2;
}

int main() {
  std::string loc;
  int num;
  std::string str1;
  std::string str2;
  std::cout << "Give me a location string:" << std::endl;
  std::cin >> loc;
  std::cout << "Give me an integer:" << std::endl;
  std::cin >> num;
  std::cout << loc << " to dec: " << LocToDec(loc) << std::endl;
  std::cout << loc << " abbreviated: " << Abbreviate(loc) << std::endl;
  std::cout << num << " to loc: " << DecToLoc(num) << std::endl;
  std::cout << "Give me two more location strings:" << std::endl;
  std::cin >> str1;
  std::cin >> str2;
  std::cout << "Sum of " << str1 << " and " << str2
            << " is: " << AddLoc(str1, str2);
}