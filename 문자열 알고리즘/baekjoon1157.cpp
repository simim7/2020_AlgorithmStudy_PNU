/* 백준 1157  시간: 48ms */
#include <iostream>
#include <cctype>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXSIZE 1000000

bool byValue(pair<char, int> p1, pair<char, int> p2){
    return p1.second > p2.second;
}

int main(void){
    map< char, int > container_m;
    vector< pair< char, int > > container_v;
    vector< pair< char, int > >::iterator it1, it2;
    char word_arr[MAXSIZE];
    scanf("%1000000s", word_arr);

    int word_size = strlen(word_arr);

    for(int i=0; i<word_size; i++){
        if( islower(word_arr[i]) )              // 소문자는 대문자로 변환
            word_arr[i] = toupper(word_arr[i]);

        if( container_m.count(word_arr[i]) != 0 ){   // 이미 있으면 value 증가
            container_m[word_arr[i]]++;
        }
        else{                                      // 없었으면 추가
            container_m.insert( pair<char, int>(word_arr[i], 1) );
        }
    }

    // map에서 vector로 옮기기(value 기준으로 정렬하기 위해서)
    for(auto m: container_m){                               // 벡터로 옮김
        container_v.push_back( make_pair( m.first, m.second) );
    }
    sort(container_v.begin(), container_v.end(), byValue);      // value 내림차순으로 정렬

    it2 = ( it1 = container_v.begin() ) + 1;
    if( (*it1).second == (*it2).second )    // 앞 2개의 빈도수가 같을 경우(최대가 여러개)
        cout << '?';
    else
        cout << (*it1).first;

	return 0;
}
