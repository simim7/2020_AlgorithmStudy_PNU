/*
	A가 B를 신뢰한다. -> B를 해킹하면 A도 해킹 할 수 있다. 
	but, A를 해킹한다고 해서 B를 해킹할 수 있는건 아니다.
	즉, 단방향 그래프다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max_N 10001 // 인덱스 1부터 시작할거니까 10000이 아닌 10001로 준다. 

int N, M;
vector<int> adj[max_N];
vector<int> answer;
vector<int> deep(1, 0); // 각 노드가 얼마나 해킹 할 수 있는가 저장.
int cnt;

void Input(void) {
	cin >> N >> M;
	for(int i=0; i<M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
}

void DFS(int node) {
	++cnt;
	if( adj[node].empty() )
		return;
	int deep_size = deep.size();
	for(int i=0; i<adj[node].size(); ++i) {
		if(i>=1) --cnt; // 하나의 노드에 여러 edge가 있을때 중복 cnt 증가 방지. 
		if(adj[node][i] <= deep_size) { // 이미 검증된 노드는 DFS 탐색 안함. 
			cnt += deep[adj[node][i]];
		}
		else { 
			DFS(adj[node][i]);
		}
	}
}

void find_max_value_index(int max_value) {
	for(int i=0; i<deep.size(); ++i) {
		if(deep[i] == max_value) { // 최대 값을 가진 인덱스를 저장. 
			answer.push_back(i);
		}
	}
}

void Solve(void) {
	for(int i=1; i<=N; ++i) {
		cnt = 0;
		DFS(i); // 각 노드별로 깊이 탐색. 
		deep.push_back(cnt);
	}	
	auto it = max_element(deep.begin(), deep.end());
	int max_value = *it;
	find_max_value_index(max_value);
	sort(answer.begin(), answer.end());
}

void Print(void) {
	for(int i=0; i<answer.size(); ++i)
		cout << answer[i] << " ";
	cout << endl;
}

int main(void) {
	Input();
	Solve();
	Print();
	return 0;
}
