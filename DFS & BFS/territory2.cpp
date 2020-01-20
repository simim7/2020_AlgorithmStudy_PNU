// 0ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define max_M 100
#define max_N 100

int M, N; // 입력받을 모눈종이 크기. 
int Graph_paper[max_N][max_M] = {-1, }; // 안쓰는 곳: -1, 방문하지 않은 곳: 0, 방문한 곳: 1
int area; // 각 영역의 넓이. 

typedef struct {
	int x, y;
} Direction;

Direction Dir[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} }; // 탐색 방향 동서남북. 

void DFS(int x, int y) {
	if(Graph_paper[x][y] == 1) // 이미 방문한 곳이라면 그냥 빠져나온다. 
		return;
		
	Graph_paper[x][y] = 1; // 방문하지 않은 곳이라면 방문했다고 표시. 
	++area; // 넓이 1 증가. 
	
	for(int i=0; i<4; ++i) { // 동서남북으로 한번씩 가면서 DFS 탐색. 
		int next_x = x + Dir[i].x; // x쪽 방향 더하기. 
		int next_y = y + Dir[i].y; // y쪽 방향 더하기. 
		if(next_x >= 0 && next_x < N && // 이때, 범위에 유의해야 함. 
			next_y >= 0 && next_y < M)
			if(Graph_paper[next_x][next_y] == 0) // 방문하지 않은곳 찾으면 그곳 DFS 재귀탐색. 
				DFS(next_x, next_y);
	}
}

int main(void) {
	int K;
	cin >> M >> N >> K;
	
	vector<int> Areas; // 각 영역의 넓이를 담기. 
	
	// 모는종이 범위를 0으로 초기화.
	for(int x=0; x<N; ++x) {
		for(int y=0; y<M; ++y) {
			Graph_paper[x][y] = 0;
		}
	} 
	
	// 모눈종이에 빗금 채우기. 
	int x1, y1, x2, y2;
	for(int i=0; i<K; ++i) {
		cin >> x1 >> y1 >> x2 >> y2; // x: n, y: m
		for(int x=x1; x<x2; ++x) {
			for(int y=y1; y<y2; ++y) {
				Graph_paper[x][y] = 1;
			}
		}		
	}
	//
	
	for(int x=0; x<N; ++x) {
		for(int y=0; y<M; ++y) {
			if(Graph_paper[x][y] == 0) { // 방문하지 않은 영역을 찾음. 
				area = 0; // 그 곳 넓이 0부터 시작해 DFS로 탐색. 매 영역마다 0부터 시작. 
				DFS(x,y);
				Areas.push_back(area); // 한 영역의 DFS가 끝나면 그 영역의 area가 나옴. 
			}
		}
	}
	
	cout << Areas.size() << endl;
	
	sort(Areas.begin(), Areas.end());
	
	for(int i=0; i<Areas.size(); ++i)
		cout << Areas.at(i) << " ";
	cout << endl;
	
	return 0;
}
