#pragma once

#include <vector>

template <typename T>
class Matrix {
private:
  using row_t = std::vector<T>;
  std::vector< row_t > matrix;

public:
  // Default constructor makes and empty Matrix
  Matrix() { }

  // Constructor can specify size, and (optional) default value
  Matrix(size_t rows, size_t cols, T init_val=T{})
    : matrix(rows, std::vector<T>(cols, init_val))
  { }

  // Copy constructor should copy everything directly, so default works
  Matrix(const Matrix<T> &) = default;

  // Assignment Operator
  Matrix<T>& operator=(const Matrix<T> &) = default;

  // Size acessors allow us to retrieve the Width or Height
  size_t GetWidth() const { 
    if (matrix.empty()) {
      return 0;
    } else {
      return matrix[0].size(); 
    }
  }
  size_t GetHeight() const { return matrix.size(); }

  // Data accessors allow us to access values at specific rows and columns
  T & GetValue(size_t row, size_t col) { return matrix[row][col]; }  
  T GetValue(size_t row, size_t col) const { return matrix[row][col]; }

  // WRITE THE IsSameSize MEMBER FUNCTION.
  // SOME NOTES, HINTS, and things to CONSIDER:
  // * One Argument should be another Matrix.
  // * Return value should be true or false (what type do you use?)
  // * Does this function change the state of Matrix? If not, make const
  // * The challenge: how do you let the Matrix argument be a different type?

  template <typename G>
  bool IsSameSize(const Matrix<G> &matrix1) {
    int size1 = matrix1.GetWidth() * matrix1.GetHeight();
    int size2 = GetWidth() * GetHeight();
    return size1 == size2;
  }

  // ADD AN operator[] MEMBER FUNCTION
  // * You should have two versions of this function, one const and one not.
  //   (C++ will always use the non-const if it can, const if it has too)
  std::vector<T> const & operator[](size_t num) const {
    return matrix[num];
  }

  std::vector<T> & operator[](size_t num)  {
    return matrix[num];
  }

  // ADD A Write MEMBER FUNCTION
  // * Remember, streams as parameters must be passed by reference!
  // * Does this function change the state of Matrix? If not, make const
  // * No return value needed (though you are welcome to have one if you want)

  

  // ADD AN operator+ MEMBER FUNCTION
  // * Parameter should be another matrix.  Make sure to check its size!
  // * Does this function change the state of Matrix? If not, make const
  // * Return should be a NEW matrix!


  // ADD AN operator* MEMBER FUNCTION
  // * Parameter should be a scalar if the same type as matrix values
  // * Does this function change the state of Matrix? If not, make const
  // * Return should be a NEW matrix!

};

// ADD AN operator<< REGULAR (NOT MEMBER) FUNCTION
// * We can't modify the std::ostream class, but we can tell C++ how to do <<
// * Parameters should be an ostream reference (for left side of <<)
//   And a Matrix (perhaps const reference?) for the right side to be printed.
// * Make it a templated function, with a template parameter to allow Matrix<T>
// * Can simply call Write() on the Matrix that was passed in!
// * Just return the stream that was passed in (and make return a reference!)
