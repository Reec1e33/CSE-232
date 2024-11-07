#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// WRITE YOUR CODE HERE

bool myLinter(std::istream &file) {
  // WRITE YOUR CODE HERE

  std::string line;

  std::string line1;
  bool leadingS;
  bool lineEnd;
  while (std::getline(file >> std::ws, line1)) {
    line += line1;
    if (line1.empty()) {
      continue;
    }
    leadingS = (line1.at(0) == 'S');
    lineEnd = ((line1.at(line1.size() - 1) == ';') ||
               (line1.at(line1.size() - 1) == '{') ||
               (line1.at(line1.size() - 1) == '}') ||
               (line1.at(line1.size() - 1) == '(') ||
               (line1.at(line1.size() - 1) == ')'));

    if ((leadingS == false) || (lineEnd == false)) {
      return false;
    }
  }

  int bracketCount = 0;
  int parenCount = 0;

  for (std::string::size_type i = 0; i < line.size(); ++i) {
    if (line.at(i) == '{') {
      bracketCount += 1;
    } else if (line.at(i) == '(') {
      parenCount += 1;
    } else if (line.at(i) == '}') {
      bracketCount -= 1;
    } else if (line.at(i) == ')') {
      parenCount -= 1;
    }
  }
  if ((bracketCount == 0) && (parenCount == 0)) {
    return true;
  }
  return false;
}

int main() {
  // provided for your testing convenience
  std::string testString1 = "Stest;\n{\n}\nSTest;";
  std::string testString2 =
      "Sinput('What is the first number');\nSinput(\nS'What is the first "
      "number?')\nSif(input==5){\nSprint('The first num is 5')}";
  std::string testString3 = "S(()";

  std::istringstream strStream1(testString1);
  std::istringstream strStream2(testString2);
  std::istringstream strStream3(testString3);

  std::cout << "Testing string: " << testString1 << " -> ";
  std::cout << (myLinter(strStream1) ? "Passed" : "Failed") << std::endl;

  std::cout << "Testing string: " << testString2 << " -> ";
  std::cout << (myLinter(strStream2) ? "Passed" : "Failed") << std::endl;

  std::cout << "Testing string: " << testString3 << " -> ";
  std::cout << (myLinter(strStream3) ? "Passed" : "Failed") << std::endl;

  return 0;
}