#include "header9d.h"
#include <memory>
int SumOf5(int * array) {
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += array[i];
	}
  delete[] array;
	return sum;
}
