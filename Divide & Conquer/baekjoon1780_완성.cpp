#include <iostream>
#include <vector>
using namespace std;

/*
	백준 1780번 종이의 개수.
	메모리: 37052KB		시간: 484ms
	기존 코드에서  cin/cout을 scanf/printf로 바꾸고,
	결과출력을 for문에서 하나하나 출력하는걸로 바꾸니까
	시간이 1128ms에서 484ms로 단축됨. 
*/

vector< vector<int> > Paper;
int result[3];	// result[n+1]: n인 종이 개수 
int Maxsize;	// 1 ~ 3^7(약 2000) 

void inputData() {
	scanf("%d", &Maxsize);
	Paper.resize(Maxsize);
	
	for(int i=0; i<Maxsize; i++) {
		int tmp;
		for(int j=0; j<Maxsize; j++) {
			scanf("%d", &tmp);
			Paper[i].push_back(tmp);
		}
	}
}

bool is_paper( int s_x, int s_y, int e_x, int e_y ) {
	int standard = Paper[s_x][s_y];

	for(int x=s_x; x<=e_x; x++) {
		for(int y=s_y; y<=e_y; y++) {
			if( Paper[x][y] != standard ) { 
				return false; 
			} 
		}
	}
	return true;
}

void solve( int s_x, int s_y, int size ) { 
	if( size == 1 ) {
		int num = Paper[s_x][s_y];
		result[num+1]++ ;
		return ;
	} 
	
	int e_x = s_x + size - 1;	int e_y = s_y + size - 1;
	int standard = Paper[s_x][s_y];
	if( is_paper( s_x, s_y, e_x, e_y ) ) {
		result[standard+1]++ ;
		return ;
	} 
	
	for( int i=s_x; i<(s_x+size); i+=(size/3) ) {
		for(int j=s_y; j<(s_y+size); j+=(size/3) ) {
			solve(i, j, size/3);
		}	
	}
}

int main(void) {
	inputData();
	solve( 0, 0 , Maxsize);
	
	printf("%d\n%d\n%d", result[0], result[1], result[2]);
	
	return 0;
}
