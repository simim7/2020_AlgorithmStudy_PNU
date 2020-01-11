// 44ms

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    string s;
    int cnt=0;
    
    while(cin >> s) {
        ++cnt;
    }
    
    cout << cnt << endl;
    
    return 0;
}
