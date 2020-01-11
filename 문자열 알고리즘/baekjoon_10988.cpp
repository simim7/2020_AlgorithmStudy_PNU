//  메모리  시간    코드길이 
//  1988KB  0ms     795B
#include <iostream>

using namespace std;

bool checkPalindrome(const string&);

int main(void)
{
    string inputWord;
    getline(cin,inputWord);
    bool isPalindrome = checkPalindrome(inputWord);
    if(isPalindrome){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}


bool checkPalindrome(const string& word)
{
    size_t middle = word.length()/2;
    bool isSameChar = true;
    bool isPalindrome = true;
    size_t i;
    string::const_iterator forward = word.cbegin();
    string::const_iterator backward = word.cend() - 1;
    for(i = 0;i<middle && isSameChar;++i){
        isSameChar = *(forward)==*(backward);
        ++forward;
        --backward;
    }
    if(!isSameChar){
        isPalindrome = false;
    }
    return isPalindrome;
}

