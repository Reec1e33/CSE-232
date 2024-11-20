#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void PassOrFail(std::vector<std::pair<std::string, int>> &v);

void ShiftRange(std::vector<int> &v, int left, int right);

std::vector<int> Fibonacci(int n);

int BinaryToInt(const std::string &binary_str);
