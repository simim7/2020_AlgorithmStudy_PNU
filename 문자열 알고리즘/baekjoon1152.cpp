/* 백준 1152   시간: 40ms */
// 처음에 empty string을 고려 안해서 틀렸었음. 공백 하나 입력도 고려해야함
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string sentence;
    int word_cnt = 0;

    getline(cin, sentence, '\n');

    size_t pos = sentence.find_first_not_of(' ');   // 처음으로 공백이 아닌 위치
    while( pos != sentence.find_last_not_of(' ') ){ // 마지막으로 공백이 아닌 위치까지
        if( sentence[pos] == ' ' )     // 첫 단어와 마지막 단어 사이 공백 카운트
            word_cnt++;
        pos++;
    }

    if( !(sentence.empty() || sentence == " ") )    // empty string이나 공백 아니면
        word_cnt++;                                 // 카운트 1 증가
    cout << word_cnt;

	return 0;
}
