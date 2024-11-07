#include <iostream> 
#include <string>

#include <cctype>

using namespace std;

string multiply(int row, int column) {
    return to_string(row) + "*" + to_string(column) + "=" + to_string(row * column);
}



int main() {
    string line;
    
    int columnStart, columnEnd, rowStart, rowEnd;

    cin >> columnStart >> columnEnd;
    cin >> rowStart >> rowEnd;

    for (int row = rowStart; row <= rowEnd; ++row) {
        for(int column = columnStart; column <= columnEnd; ++column) {
            std::cout << multiply(row,column);

            if ((rowEnd - rowStart) < (columnEnd - columnStart)){
                if (row != rowEnd) {
                    cout << ", ";
                }
            }else{
                if (column != columnEnd){
                    cout << ", ";
                }
            }
            

        }
        cout << endl;
    }
    return 0;

    
            
}

    

