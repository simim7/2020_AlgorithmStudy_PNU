// 80ms
#include <iostream>
#include <vector>

using namespace std;

/*
	가장 적은 '종류' 의 비행기 라고 했으니 엣지를 지난 횟수가 아니라
	엣지의 개수만 생각하면 된다. 
	이미 방문한 국가도 지나도 된다.
	항상 연결그래프를 이룬다.
	-> 모든 Vertex를 방문하면서, 최소의 Edge를 가진 것을 구하는 것 이므로
	-> Spanning tree 문제다. 
	-> Spanning tree의 edge 수는 vertex-1 이다. 
*/

int main(void) {
	int T, N, M;
	vector<int> vertex;
	
	cin >> T;
	for(int t=0; t<T; ++t) {
		cin >> N >> M;
		vertex.push_back(N);
		for(int m=0; m<M; ++m) {
			int a, b;
			cin >> a >> b;
		}
	}
	
	for(int i=0; i<T; ++i) { // vertex -1 개 출력. 
		cout << vertex[i] - 1 << endl;
	}
	
	return 0;
}
