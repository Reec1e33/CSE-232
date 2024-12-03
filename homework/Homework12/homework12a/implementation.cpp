#include "header.hpp"
#include <iterator>
#include <utility>
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <complex>
#include <valarray>
#include <array>

int SumOfOdd(std::vector<int>::const_iterator left , std::vector<int>::const_iterator right){

    std::vector<int> vec2 = {};
    std::copy_if(left, right, std::back_inserter(vec2), [](int x){return x % 2 != 0;} );
    return std::accumulate(vec2.begin(), vec2.end(), int{0});
}


void MakeComplex(std::valarray<std::complex<int>> & complexArray){

    std::replace_if(std::begin(complexArray), 
    std::begin(complexArray) + complexArray.size(), 
    [](std::complex<int> x){ return x.imag() == 0;},
    std::complex<int>{0, 1});

}


int main() {
	std::vector<int> const numbers = {1, 2, 3, 4, 5, 6, 8, 5, 2, 2, 5, 101};
	std::cout << SumOfOdd(numbers.cbegin(), numbers.cend()) << std::endl;
	std::cout << SumOfOdd(numbers.begin(), numbers.end()) << std::endl;

  std::valarray<std::complex<int>> complex_numbers = {{{1, 2}, {3, 0}, {0, 7}, {-45, -68}}};
  MakeComplex(complex_numbers);
  std::ranges::copy(complex_numbers, std::ostream_iterator<std::complex<int>>(std::cout, " "));
  // (1,2) (0,1) (0,7) (-45,-68)

}
