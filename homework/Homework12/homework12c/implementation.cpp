#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

// WRITE YOUR CODE HER
std::vector<int> SampleWithReplacement(std::vector<int> const & population, int n, std::uint64_t seed){
    std::mt19937_64 eng(seed);
    std::vector<int> output{};
    std::uniform_int_distribution dist(0,static_cast<int>(population.size()-1));

    for(int i = 0; i < n; ++i){
        output.push_back(population.at(dist(eng)));
    }
    return output;
}



int main() {
	std::vector<int> const population = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5};
	std::vector<int> sample = SampleWithReplacement(population, 20, 123);
  std::ranges::copy(sample, std::ostream_iterator<int>(std::cout, " "));
  // 4 5 5 5 2 2 5 3 5 5 3 5 1 5 5 5 5 5 4 5 

}