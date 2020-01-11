#include <bits/stdc++.h>

using namespace std;

class alphabet {
    char alp;
    int cnt=1;
public:
    alphabet(char c) {
        alp = c;
    }
public:
    char getAlp(void) {
        return alp;
    }
    int getCnt(void) {
        return cnt;
    }
    void increaseCnt(void) {
        ++cnt;
    }
};

void countAlphabet(vector<alphabet>& v, char c)
{
    for(int i=0; i<v.size(); ++i) {
        if(v[i].getAlp() == c) {
            v[i].increaseCnt();
            return;
        }
    }

    v.push_back(alphabet(c));
}

int main(void)
{
    vector<alphabet> alphabetList;
    string inputString;
    cin >> inputString;

    int inputStringLen = inputString.size();

    //cout << inputString << ":" << inputStringLen << endl;
    // 대문자로 변환
    for(int i=0; i<inputStringLen; ++i) {
        inputString[i] = toupper(inputString[i]);
    }

    //cout << inputString << endl;

    for(int i=0; i<inputStringLen; ++i) {
        countAlphabet(alphabetList, inputString[i]);
    }

    vector<char> ans;
    char maxCntChar = alphabetList[0].getAlp();
    int maxCnt = alphabetList[0].getCnt();

    for(int i=1; i<alphabetList.size(); ++i) {
        // cout << alphabetList[i].getAlp() << " : " << alphabetList[i].getCnt() << endl;
        if(alphabetList[i].getCnt()>maxCnt) {
            maxCnt = alphabetList[i].getCnt();
            maxCntChar = alphabetList[i].getAlp();
            ans.clear();
            ans.push_back(maxCntChar);
        } else if(alphabetList[i].getCnt()==maxCnt) {
            ans.push_back(alphabetList[i].getAlp());
        }
    }

    if(ans.size()>1) {
        cout << "?" << endl;
    } else {
        cout << maxCntChar << endl;
    }

    return 0;
}
