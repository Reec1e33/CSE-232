#include <iostream>
#include "homework8d.h"
#include <sstream>
int main() {
    std::ostringstream oss;
    Price p;
    std::istringstream iss("$7.45");
    iss >> p;
    Price p2 = p + p;
    Price p3 = p2 - 1.5;
    oss << p3 << " ";
    Price p4 = p3 -= p; 
    p4 += 5.4;
    oss << p << " " << p2 << " " << p3 << " " << p4 << " ";
    std::cout << oss.str() << std::endl;

}