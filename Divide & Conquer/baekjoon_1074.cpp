// memory 1984KB
// time 0ms
// code length 480B
#include <iostream>

using namespace std;

void setBitOf(int& result, size_t digit, int bit) {
    result = result | (bit<<digit);
}

int main(void) {
    int orderOfTwo;
    int row;
    int col;
    int result=0;
    cin >> orderOfTwo >> row >> col;
    for(size_t i=0; i<orderOfTwo; ++i) {
        int row_bit = (row>>i) & 1;
        int col_bit = (col>>i) & 1;
        setBitOf(result,2*i,col_bit);
        setBitOf(result,2*i+1,row_bit);
    }
    cout <<result;
    return 0;
}