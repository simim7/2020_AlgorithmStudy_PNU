#include <iostream>
#include <string>
using namespace std;
// 두글자 단어가 2번 나오는건 압축 안하는게 더 짧음
/*
 * pos1은 비교 기준이 되는 substring의 시작 인덱스임.
 * 기준 단어부터 시작하는 substring 중 길이가 가장 긴 것(남은 string의 절반까지)부터
 * 바로 뒤의 단어와 같은지 비교함.
 * 예를 들어, "mamapapa"면 mama부터 mam, ma...탐색하고
 * ama, am....
 * map, ma...
 * ap....
*/

void compress(string data) {
    int data_size = data.size();
    int cnt = 0;
    size_t pos1 = 0;

    while( pos1 < data_size-1 ) {
        size_t pos2 = pos1 + (data_size-pos1)/2;

        while( pos1 != pos2 ) {
            int interval = pos2 - pos1;
            if( data.substr(pos1, interval) == data.substr(pos2, interval) ){
                cout << data.substr(pos1, interval) << ' ' << pos1 << endl;
                cnt++;
                pos1 += interval;
                pos2 += interval;
              //  break;
              }
            else { pos2-- ; }
        }
        cout << cnt << endl;
        cnt = 0;
        pos1++;
    }
}

int main(void){
    cout << "0123456789012345678901234567890123456\n";
    string data;
    cin >> data;
    compress(data);

	return 0;
}
