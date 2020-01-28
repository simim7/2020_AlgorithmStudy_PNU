#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;
ll Answer;
ll N;
vector<ll> heights;

void print_heights(void) {
	for(int i=0;i<heights.size();++i)
		cout << heights[i] << ' ';
	cout << endl;
}

void print_stack(stack<ll> st) {
	stack<ll> temp = st;
	
	cout << "--------현재 스택상황--------" << endl; 
	while(!temp.empty()) {
		printf("<%d>:%d\n", temp.top(), heights[temp.top()]);
		temp.pop();	
	}
	cout << "-----------------------------" << endl;
}

void processing(void) {
	stack<ll> st;
	ll top, area;
	for(ll i=0;i<N;++i) {
//		cout << endl << "--------------------------------------- for문 시작---------------------------------------" << endl; 
		if(st.empty()) {	// 스택이 비었으면 
//			cout << "\"0\"" << endl;
//			printf("스택이 비어서 %d을 집어넣음\n", i); 
			st.push(i);
//			print_stack(st);
			continue;
		}
		top = st.top();
		if(heights[top] < heights[i]) {		// 탑에있는거보다 새로들어오는게 크면 
//			cout << "\"1\"" << endl;
//			printf("top(%d:%d)이 i번째(%d:%d)보다 작기때문에 %d를 푸시.\n", top,heights[top],i,heights[i],i);
			st.push(i);
//			print_stack(st);
			continue;
		}
		if(heights[top] == heights[i]) {	// 같으면 그냥 continue 
//			cout << "\"2\"" << endl;
//			printf("top(%d:%d)이 i번째(%d:%d)와 같기 때문에 그냥 패스.\n", top,heights[top],i,heights[i]);
			continue;
		} 
//		cout << "\"3\"" << endl;
//		cout << "========================while문 시작===========================" << endl; 
	 	while(!st.empty()) {
	 		top = st.top();
	 		if(heights[top]<=heights[i]) {
//				printf("top(%d:%d)이 i번째(%d:%d)보다 작거나 같으므로  그냥 패스.\n", top,heights[top],i,heights[i]);
				break;
			}
			
			st.pop();
			ll width;
			if(!st.empty()) {
				width = i-st.top()-1;
			}
			else { 
				width = i; 
			}	
//			printf("top: %d, height: %d, width: %d\n",top,heights[top],width);
	 		area = (long long)width * (long long)heights[top];
	 		if(area > Answer) {
//				printf("area(%d) 가 Answer(%d)보다 커서 값이 바뀜. %d ==> %d\n",area,Answer,Answer,area); 
				Answer = area;
			}
//			printf("%d를 stack에서 뽑아냄.\n", top); 
//	 		print_stack(st);
	 	}
//	 	cout << "==========================while 끝=============================" << endl; 
// 		cout << "집어 넣음." << endl;
 		st.push(i);
// 		print_stack(st);

	}
	
	
	while(!st.empty()) {
//		cout << "다 안빠졌음." << endl;
//		print_stack(st);
		ll top_index = st.top();
		ll height = heights[top_index];
		
		st.pop();
		ll width;
		if(!st.empty()) {
			width = N-st.top()-1;
		}
		else { 
			width = N; 
		}	
//		printf("top_index: %d, height: %d, width: %d\n",top_index,height,width);
		ll area = (long long)height * (long long)width;
//		printf("area: %d\n",area);
		if(area>Answer) {
//			printf("Answer: %d ==> %d\n", Answer, area);
			Answer = area;
		}
	}
}

int main(void)
{
	ifstream ifs("6549_3.txt");
	
	while(ifs >> N) {
//		cout << "N: " << N << endl; 
		if(N == 0) break;
		Answer=0;
		heights.clear();
		heights.resize(N);
		
		for(ll i=0;i<N;++i) {
			ifs >> heights[i];
//			cout << heights[i] << ' ';	
		}
//		cout << endl;
		
		processing();
			
		cout << Answer << endl;
	}

	return 0;	
}
