/* 백준 10988번    시간 0ms
* 데이터를 입력 받아서 벡터(또는 배열)에 저장하는 과정에서 어려움을 겪음
*/
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 100

int main(void) {
    char word_arr[MAXSIZE] = {};        // 단어 담을 char 배열
    scanf("%100s", word_arr);           // 100개만 입력받음

    int word_len = strlen(word_arr);    // 단어 길이

    int i = 0, j = word_len-1;          // i는 앞, j는 뒤부터 탐색
    while(i < j){
        if( word_arr[i] != word_arr[j] )
            break;
        i++;
        j--;
    }
    /*
    while문 안에서
    if( word_arr[i++] != word_arr[j--] )
        break;
    이렇게 짜니까 단어 길이가 2, 3일 때 무조건 결과가 1이 나와서 틀렸다.
    */

    int result = ( i < j ? 0 : 1 );
    printf("%d", result);

	return 0;
}
