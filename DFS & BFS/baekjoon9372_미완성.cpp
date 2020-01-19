#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <list>
#include <stack>
#include <map>
#define MAX_V 1001

using namespace std;

map< int, list<int> > maplist;
vector< int > result;
int case_N, country_N, airplane_N;

bool is_visit( vector<int> visit, int vertex ) {
	for(auto v: visit) {
		if( v == vertex ) {	return true; }
	}
	return false;
}

void BFS() {
	queue < int > queue; 
	vector< int > visit;
	int cnt = 0;
	
	queue.push( 1 );
	visit.push_back( 1 );
	
	while( !queue.empty() ) {
		int target = queue.front();
		list< int > sublist = maplist[target];
		list< int >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {
			if( !is_visit( visit, *iter ) ) {
				queue.push( *iter );
				visit.push_back( *iter );
				cnt++;
			}
		}
		if( iter == sublist.end() ) {
			queue.pop();
		}
	}
	result.push_back(cnt);	
}
/*
void DFS() {
	stack < int > stack;
	vector< int > visit;
	int cnt = 0;
	
	stack.push(1);				// 시작 정점 넣음 
	visit.push_back(1);

	while( !stack.empty() ) {
		int target = stack.top();		// 타겟(출발 정점)은 stack의 top원소 
		list< int > sublist = arraylist[target];	// 타겟 정점과 연결된 정점list 
		list< int >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {	
			if( !is_visit( visit, *iter ) ) {	// 나아갈 곳이 있으면 
				target = *iter;					// 나아가서 타겟 변경 
				stack.push(target);
				visit.push_back(target);
				cnt++;
				break;
			}
		}
		if( iter == sublist.end() ) {	// 나아갈 곳이 없으면 
			stack.pop();				// stack에서 제거 
		}
	}
	
	result.push_back(cnt);
}*/
int main(void) {
	scanf("%d", &case_N);
	for(int i=0; i<case_N; i++) {
		int start, end;
		scanf("%d%d", &country_N, &airplane_N);
		for(int j=0; j<airplane_N; j++) {
			scanf("%d%d", &start, &end);	
			maplist[start].push_back(end);		// 입력받은 edge 추가
			maplist[end].push_back(start);	// edge는 왕복임을 고려 
		} // airplane_N
		
		BFS();
		for(auto s: maplist) 	{ s.second.clear(); }
		
	} // case_N
	
	for(auto s: result)	{ printf("%d\n", s); }
	
	return 0;
}

