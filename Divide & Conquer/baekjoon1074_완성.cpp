// 백준 1074  [Z] 	메모리: 2168KB	시간: 0ms 
#include <iostream>
#include <math.h>
using namespace std;

int count;	// 결과 

void solve(int abs_i, int abs_j, int size ) {
	if( size == 1 )	{ return ; }
	int half = size/2;
	int order = 0;	// 4칸중 몇번째 칸인지(0,1,2,3) 
	
	bool i_smaller = abs_i < half;
	bool j_smaller = abs_j < half;
	
		 if(  i_smaller &&  j_smaller )	{ order = 0; }
	else if(  i_smaller && !j_smaller )	{ order = 1; }
	else if( !i_smaller &&  j_smaller ) { order = 2; }
	else if( !i_smaller && !j_smaller ) { order = 3; }
	
	count += (half * half) * order;	// 속한 칸의 첫칸 전까지의 개수 더함 
	
	cout << "\nsize: " << size << endl;
	cout << "order: " << order << endl; 
	cout << "count: " << count << endl;
	// 첫 칸이 (0,0)이 되도록 상대적인 인덱스로 변경 
	int rel_i = ( i_smaller ? abs_i : abs_i-half ) ;
	int rel_j = ( j_smaller ? abs_j : abs_j-half ) ;
	solve( rel_i, rel_j, half );
}

int main(void) {
	int N, abs_i, abs_j;
	scanf("%d%d%d", &N, &abs_i, &abs_j);
	solve( abs_i, abs_j, pow(2,N) );
	cout << count;
	return 0;
}

