//  memory  time    code length 
//  4880KB  36ms    1086B

#include <iostream>
#include <string>

using namespace std;

int countWord(const string&);

int main(void)
{
    string inputString;
    getline(cin, inputString);
    int wordNumber = countWord(inputString);
    cout << wordNumber;
    return 0;
}

int countWord(const string& inputString)
{
    int count = 0;
    int length = inputString.length();
    bool isEmptyString = (length==0);
    if(isEmptyString)
        return count;
    bool onlyOneBlank = (inputString[0]==' '&&length==1);
    if(onlyOneBlank)
        return count;
    count = 1;
    string::const_iterator iter = inputString.cbegin();
    string::const_iterator endIter = inputString.cend();
    bool isFirstBlank = (*iter == ' ');
    if(isFirstBlank)
        ++iter;
    bool isCurrentEnd = (iter == endIter);
    while(!isCurrentEnd){
        bool isCurrentBlank = (*iter == ' ');
        ++iter;
        bool isNextEnd = (iter == endIter);
        bool isInsideBlank = isCurrentBlank && !isNextEnd;
        if(isInsideBlank)
            ++count;
        isCurrentEnd = iter == endIter;
    }
    return count;
}

