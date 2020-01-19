// < DFS와 BFS >  
// 메모리 	시간	코드길이
// 2256KB	8ms		1716B 
 
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,V;
map<int, vector<int> > Graph;
vector<int> path;
// 그래프 형태라면 DFS, BFS 둘 다 방문 여부를 체크하지 않으면 무한 루프에 빠진다. 
bool* Visited; 

void print(vector<int> v){
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout <<endl;
}

void DFS(int V){	 
	Visited[V] = true;
	path.push_back(V);

	vector<int> ChildNodes = Graph[V];
	for(size_t i=0; i<ChildNodes.size(); i++){
		int Child = ChildNodes[i];
		if( !Visited[Child]	){
			DFS(Child);
		}
	}
}

void BFS(int V){

	queue<int> NodeQueue;
	NodeQueue.push(V);
	Visited[V] = true;

	while(!NodeQueue.empty()){
		path.push_back(V);
		NodeQueue.pop();
		vector<int> ChildNodes = Graph[V];
		for(size_t i=0; i<ChildNodes.size(); i++){
			int Child = ChildNodes[i];
			if( !Visited[Child]	){
				  Visited[Child] = true;
				  NodeQueue.push(Child);
			}
		}
		V = NodeQueue.front();
	}
	print(path);
}

int main(void){
	cin >> N >> M >> V;
//	cout << (Graph[N] == vector<int>());	
	for(size_t i=0; i<M; i++){	
		int n1, n2;
		cin >> n1 >> n2;
		Graph[n1].push_back(n2);
   		Graph[n2].push_back(n1);
	}
	
	for(size_t i=1; i<=N; i++){
		vector<int>* ChildNodes = &Graph[i];
		sort((*ChildNodes).begin(), (*ChildNodes).end());
	}
	
	map<int,vector<int> >::iterator iter;
//    for(iter=Graph.begin();iter!=Graph.end();iter++)
//    {
//    	if((iter->second).size()>=1)
//	         cout<< "Key : "<< (iter->first) <<" Value : "; print(iter->second);
//    }
    
    Visited = new bool[N+1];
    fill(Visited, Visited+N+1, false);
	Visited[0] = true;

	DFS(V);
	delete(Visited);
	print(path);

	path.clear();	
	Visited = new bool[N+1];
    fill(Visited, Visited+N+1, false);

	BFS(V);
	delete(Visited);
	
	return 0;
}
