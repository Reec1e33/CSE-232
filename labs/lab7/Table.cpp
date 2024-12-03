#include "Table.hpp"
#include <random>


Table::Table(size_t width, size_t height, int val)
    : table_(height, row_t(width, val)), 
      width_(width),                    
      height_(height)                   
{}




// WRITE THE DEFINITION FOR Table::PrintTable
void Table::PrintTable(std::ostream &os) const {
    for (size_t i = 0; i < height_; ++i) {
        for (size_t j = 0; j < width_; ++j) {
            os << table_.at(i).at(j); 
            if (j < width_ - 1) {
                os << ", "; 
            }
        }
        os << '\n'; 
    }
}


// WRITE THE DEFINITION FOR Table::FillRandom
void Table::FillRandom(int low, int high, int seed){

  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(low, high);
  for (size_t i = 0; i < height_; ++i) {
    for (size_t j = 0; j < width_; ++j) {
        table_.at(i).at(j) = distribution(generator);
    }
  }
}

// WRITE THE DEFINITION FOR Table::SetValue
bool Table::SetValue(size_t col, size_t row, int val){
    try{
        table_.at(row).at(col) = val;
    }
    catch(const std::out_of_range &){
        return false;
    }
    return true;
    
}

// WRITE THE DEFINITION FOR Table::GetValue
int Table::GetValue(size_t col, size_t row) const{
    try{
        return table_.at(row).at(col);
    }
    catch(const std::out_of_range &){
        throw;
    }
}

