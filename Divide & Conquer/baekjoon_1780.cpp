// memory 20612KB
// time 1124ms
// code length 2946B
#include <iostream>

using namespace std;

class Paper {
    int** paper;
    const int paperSize;
    int countMinusOne = 0;  // is initialization possible in declaration?
    int countZero = 0;
    int countPlusOne = 0;

    static constexpr const int MIXED_DOMAIN = -2;

    void packDomain(const int row, const int col) {
        const int spot = paper[row][col];
        if(spot==-1) {
            countMinusOne -= 8;
        } else if(spot==0) {
            countZero -= 8;
        } else {
            countPlusOne -= 8;
        }
    }
    int checkSpot(const int row, const int col) {
        const int spot = paper[row][col];
        if(spot==-1) {
            ++countMinusOne;

        } else if(spot==0) {
            ++countZero;
        } else {
            ++countPlusOne;
        }
        return spot;
    }
    int checkDomain(const int checkSize, const int row, const int col) {
        if(checkSize==1)
            return checkSpot(row, col);
        const int smallerSize = checkSize/3;
        int smallerRows[3];
        int smallerCols[3];
        int checkResults[3][3];
        for(size_t i=0; i<3; ++i) {
            smallerRows[i] = row + smallerSize*i;
            smallerCols[i] = col + smallerSize*i;
        }
        for(size_t r=0; r<3; ++r) {
            for(size_t c=0; c<3; ++c) {
                checkResults[r][c] =  checkDomain(smallerSize,smallerRows[r],smallerCols[c]);
            }
        }
        bool isMixedDomain = false;
        for(size_t r=0; r<3; ++r)
            for(size_t c=0; c<3; ++c) {
                isMixedDomain = (checkResults[r][c] == MIXED_DOMAIN) || (checkResults[r][c]!=checkResults[0][0]);
                if(isMixedDomain)
                    return MIXED_DOMAIN;
            }
        if(!isMixedDomain)
            packDomain(row,col);
        return checkResults[0][0];
    }
    void calculateCounts(void) {
        if(paperSize==1) {
            checkSpot(0,0);
            return;
        }

        checkDomain(paperSize,0,0);
    }
  public:
    Paper(const int _paperSize):paperSize(_paperSize) {
        paper = new int*[paperSize];
        for(size_t i=0; i<paperSize; ++i)
            paper[i]= new int[paperSize];
        for(size_t i=0; i<paperSize; ++i)
            for(size_t j=0; j<paperSize; ++j)
                cin >> paper[i][j];
        calculateCounts();
    }
    ~Paper() {
        for(size_t i=0; i<paperSize; ++i)
            delete[] paper[i];
        delete[] paper;
    }
    int minusOneCount(void) {
        return countMinusOne;
    }
    int zeroCount(void) {
        return countZero;
    }
    int plusOneCount(void) {
        return countPlusOne;
    }
};
constexpr const int Paper::MIXED_DOMAIN;

int main(void) {
    size_t paperSize;
    cin >> paperSize;
    Paper paper(paperSize);
    cout << paper.minusOneCount() << endl;
    cout << paper.zeroCount() << endl;
    cout << paper.plusOneCount() << endl;
    return 0;
}