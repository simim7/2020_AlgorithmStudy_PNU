#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream ifs("test2.inp");
    string inputString;
    bool isPalindrome = true;

    ifs >> inputString;
    int inputStringLen = inputString.size();

    // cout << inputString << " : " << inputStringLen << endl;

    int i = 0, j = inputStringLen-1;
    for( ; i<j; ++i, --j) {
        if(inputString[i]!=inputString[j]) {
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
