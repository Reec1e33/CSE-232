
#include <string>
#include <vector>
#include <iterator>

int Func(int a) 
{
    std::vector<int> b(a);
    std::vector<int>::iterator iter = b.begin();
    
    for (int i = 0; iter != b.end(); ++iter){
        *iter = 12 + i;
        ++i;
    }

    std::vector<int> c(b);
    std::vector<int> vec = {};
    for (size_t i = c.size() - 1; i != 0; --i){
      vec.push_back(c.at(i));
    }
    c = vec;

 

    for (size_t i = 0; i < c.size(); ++i){
      b.at(i) = 2 * c.at(i) + b.at(i);
    }





    
    int count = 0;
    for (size_t i = 2; i < b.size() - 2; ++i){
      if (std::to_string(b.at(i)).find("2") != std::string::npos){
        count += 1;
      }
    }
    return count;
}
