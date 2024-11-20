#include "Generic.hpp"

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>

void PassOrFail(std::vector<std::pair<std::string, int>> &v){
        sort(v.begin(), v.end());

    std::stable_partition(v.begin(), v.end(), [](std::pair<std::string,int> pair1){ return pair1.second > 600;});
}

void ShiftRange(std::vector<int> &v, int left, int right){
    sort(v.begin(), v.end());
    std::stable_partition(v.begin(), v.end(), [left, right](int x){ return !((x >= left) && (x <= right));});


}

int Factorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    else{
        return Factorial(n-1) + Factorial(n-2);
    }
}
std::vector<int> Fibonacci(int n){
    std::vector<int> output(n);

    std::iota(output.begin(), output.end(), 1);
    std::for_each(output.begin(), output.end(), [output](int x){return x = Factorial(x);});
    
    return output;
}

int BinaryToInt(const std::string &binary_str){
    std::accumulate(binary_str.begin(), binary_str.end(), [](char ch, int total){return total * 2 + (ch - '0');});
}