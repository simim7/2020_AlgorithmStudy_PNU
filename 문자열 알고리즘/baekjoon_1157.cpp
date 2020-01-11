//  메모리  시간    코드길이 
//  4880KB  40ms    1812B
#include <iostream>
#include <string>

using namespace std;

char biggestCountAlphabet(const string&);
void setZero(int*,const int);
void countAlphabet(const string& inputString, int* countAlphabet);
char findMostInAlphabetCount(int* alphabetCount);
constexpr int ALPHABET_NUMBER = 26;

int main(void)
{
    string inputString;
    getline(cin, inputString);
    cout << biggestCountAlphabet(inputString);
    return 0;
}

char biggestCountAlphabet(const string& inputString)
{
    int alphabetCount[ALPHABET_NUMBER];
    setZero(alphabetCount,ALPHABET_NUMBER);
    countAlphabet(inputString, alphabetCount);
    char mostAlphabet = findMostInAlphabetCount(alphabetCount);
    
    return mostAlphabet;
}
char findMostInAlphabetCount(int* alphabetCount)
{
    
    int indexOfMost=0,indexOf2nd=-1;
    for(size_t i=1;i<ALPHABET_NUMBER;i++){
        bool foundBigger = alphabetCount[i]>=alphabetCount[indexOfMost];
        if(foundBigger){
            indexOf2nd = indexOfMost;
            indexOfMost = i;
        }
    }
    char mostAlphabet;
    bool isCountSame = alphabetCount[indexOfMost] == alphabetCount[indexOf2nd];
    if(isCountSame){
        mostAlphabet = '?';
    }
    else{
        mostAlphabet = char('A'+indexOfMost);
    }
    return mostAlphabet;
}

void countAlphabet(const string& inputString, int* alphabetCount)
{
    string::const_iterator iter = inputString.cbegin();
    string::const_iterator stringEnd = inputString.cend();
    for(;iter!= stringEnd; iter += 1){
        int alphabetIndex = *iter-'a';
        bool isBigRange = alphabetIndex < 0;
        if(isBigRange){
            alphabetIndex = *iter -'A';
        }
        alphabetCount[alphabetIndex]++;
    }
}
void setZero(int* intArray, const int length)
{
    for(size_t i=0;i<length;i++){
        intArray[i] = 0;
    }
}
