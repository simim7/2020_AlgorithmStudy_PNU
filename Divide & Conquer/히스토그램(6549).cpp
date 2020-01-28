#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
typedef long long ll;
vector<ll> heights;

void print_heights(void) {
	for(ll i=0;i<heights.size();++i)
		cout << heights[i] << ' ';
	cout << endl;
}

int find_min_index(ll start, ll end) {
	ll min_index = start;
	ll min_value = heights[start];
	
	for(ll i=start+1;i<=end;++i)
		if(heights[i] < min_value) {
			min_index = i;
			min_value = heights[i];
		}
			
	return min_index;	
}

void init_tree(ll start, ll end) {
//	cout << "============================" << endl;
//	printf("start: %d, end: %d\n", start, end);
	ll mindex, area;
	/* 한칸짜리 범위면 */ 
	if(start==end) {
//		printf("start와end가 같음.\n"); 
		mindex = start;
		area = heights[mindex];
//		printf("mindex: %d\n",mindex);
//		printf("area: %d\n", area);
		if(area>Answer) Answer = area;
		return;								// 더이상 안쪼개고 그대로 리턴  
	}
	
//	printf("start와end가 다름.\n");
	mindex = find_min_index(start,end);	// 주어진 범위내에서 최소인 인덱스를 찾음. 
//	printf("mindex: %d\n",mindex);
	area = (end-start+1)*heights[mindex];
//	printf("area: %d\n", area);
	if(area>Answer) Answer = area;
	
	if(mindex != start) {	// 최소 인덱스가 범위의 제일 왼쪽이 아니면 
		init_tree(start, mindex-1);	// 나눔  
	}
	
	if(mindex != end) {	// 최소 인덱스가 범위의 가장 오른쪽이 아니면  
		init_tree(mindex+1,end); // 나눔  
	}

}

int main(void)
{
	int N;
	int height;
	ifstream ifs("6549_3.txt");
	
	while(ifs >> N) {
		//cout << "N: " << N << endl; 
		if(N == 0) break;
		Answer=0;
		heights.clear();
		heights.resize(N);
		
		for(int i=0;i<N;++i) {
			ifs >> heights[i];
		}	
//		cout << "=====================================" << endl;
//		print_heights();
//		cout << "=====================================" << endl;
		init_tree(0, N-1);
		
		printf("%d\n", Answer);
	}

	return 0;	
}
