 #include <vector>
 #include <iostream>
 #include "homework8b.h"
 int main() {
  std::vector<std::vector<bool>> road_map = {
    {false, true, false, false},
    {false, false, true, true},
    {true, false, false, false},
    {false, true, false, false}
  };
  std::cout << AreRoadsBalanced(road_map) << std::endl; // Should be true
  road_map = {
        {false, true, false, true},
            {true, false, false, false},
            {false, true, false, false},
            {false, false, true, false}
  };
  std::cout << AreRoadsBalanced(road_map) << std::endl; // Should be false
}



