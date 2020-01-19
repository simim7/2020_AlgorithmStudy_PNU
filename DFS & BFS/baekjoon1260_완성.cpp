/* 백준1260번   시간: 24ms */
#include <iostream>
#include <array>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#define MAX_V 1001
using namespace std;

array< list<int>, MAX_V > maplist;
int vertex_N, edge_N, startpoint;
bool is_exist(); 
void setData();
void DFS();
void BFS();

int main(void) {
	cin >> vertex_N >> edge_N >> startpoint;
	
	setData();	// 인접행렬 형태로 만듦 

	DFS();
	BFS();
	
	return 0;
}

bool is_visit( vector<int> visit, int vertex ) {
	for(auto v: visit) {
		if( v == vertex ) {	return true; }
	}
	return false;
}

void setData() {
	int start, end;
	for(int i=0; i<edge_N; i++) {
		cin >> start >> end;
		
		maplist[start].push_back(end);		// 입력받은 edge 추가
		maplist[end].push_back(start);		// edge는 왕복임을 고려 
	}
	
	for(int i=0; i<maplist.size(); i++) {	maplist[i].sort(); }	// list 오름차순 정렬(우선순위 고려) 
}

void DFS() {
	stack < int > stack;
	vector< int > visit;
	
	stack.push(startpoint);				// 시작 정점 넣음 
	visit.push_back(startpoint);

	while( !stack.empty() ) {
		int target = stack.top();		// 타겟(출발 정점)은 stack의 top원소 
		list< int > sublist = maplist[target];	// 타겟 정점과 연결된 정점list 
		list< int >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {	
			if( !is_visit( visit, *iter ) ) {	// 나아갈 곳이 있으면 
				target = *iter;					// 나아가서 타겟 변경 
				stack.push(target);
				visit.push_back(target);
				break;
			}
		}
		if( iter == sublist.end() ) {	// 나아갈 곳이 없으면 
			stack.pop();				// stack에서 제거 
		}
	}
	
//	cout << "DFS: ";
	for(auto v: visit) { cout << v << ' '; }
	cout << "\n";
}

void BFS() {
	queue < int > queue; 
	vector< int > visit;
	
	queue.push( startpoint );
	visit.push_back( startpoint );
	
	while( !queue.empty() ) {
		int target = queue.front();
		list< int > sublist = maplist[target];
		list< int >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {
			if( !is_visit( visit, *iter ) ) {
				queue.push( *iter );
				visit.push_back( *iter );
			}
		}
		if( iter == sublist.end() ) {
			queue.pop();
		}
	}
//	cout << "BFS: ";
	for(auto v: visit) { cout << v << ' '; }
	cout << "\n";	
}
