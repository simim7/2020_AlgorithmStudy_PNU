/* 카카오 2020 신입 개발자 블라인드 채용 1차 코딩 테스트 문제1  시간: 7.51ms */
#include <string>
using namespace std;
int compress( string data, int unit);
/*
int main(void) {
    string s;   cin >> s;
    cout << solution(s);
}
*/
int solution(string s) {
    int data_size = s.size();
    int min_size = data_size;

    for(int i=1; i <= data_size/2; i++){          // 분할 단위는 1~(문자열 길이 절반 )
        int compress_size = compress(s, i);
        if(compress_size < min_size) {          // 작은 값 나올때마다 min값 대체
            min_size = compress_size;
        }
    }

    return min_size;
}

int compress( string data, int unit ) {
    int compressed_size = 0;
    int data_size = data.size();
    int remainder = data_size%unit;     // 단위로 나누고 남은 나머지 string

    size_t pos = 0;
    while( pos < data_size - remainder ){
        int overlap_cnt = 0;            // 같은 문자열 중복 횟수
        string target = data.substr(pos, unit);
        overlap_cnt++;
        pos += unit;

        while( target == data.substr(pos, unit) ) {   // target string이랑 같은게 몇번 있는지
            overlap_cnt++;
            pos += unit;
        }

        if(overlap_cnt > 1){
            cout << overlap_cnt;
            compressed_size += ( to_string(overlap_cnt).size() );   // 두번 이상 똑같은게 나왔을 경우 겹친 횟수 숫자의 길이 더함
        }
        cout << target;
        compressed_size += target.size();   // substring의 길이 더함
    }
    cout << remainder;
    compressed_size += remainder;           // 단위로 나누고 남은 문자열 길이 더함

    return compressed_size;
}
