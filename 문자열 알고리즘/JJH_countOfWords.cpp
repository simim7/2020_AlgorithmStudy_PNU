#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string inputString;
    getline(cin, inputString);

    int inputStringLen = inputString.size();
    int wordCnt = 0;

    // cout << inputString << ":" << inputStringLen << endl;

    if(inputString[0]!=' ') {
        wordCnt = 1;
    }
    for(int i=0; i<inputStringLen-1; ++i) {
        // cout << i << endl;
        if(inputString[i]==' ' && i!=inputStringLen-1) {
            wordCnt++;
        }
    }

    cout << wordCnt << endl;

    return 0;
}
