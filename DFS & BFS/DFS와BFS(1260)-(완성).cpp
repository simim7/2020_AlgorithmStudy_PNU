// 12ms

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector< vector<bool> > graph;
vector< bool > visited_dfs;
vector< bool > visited_bfs;
vector<int> list_visited_dfs;
vector<int> list_visited_bfs;

void print_graph(void) {
	cout << "================graph===============" << endl << endl;
	for(int i=1;i<graph.size();++i) {
		for(int j=1;j<graph[i].size();++j)
			cout << graph[i][j] << '\t';
		cout << endl << endl;
	}
	cout << "====================================" << endl;	
}

void DFS(int visit) {
	cout << visit << "을 방문함." << endl; 
	print_graph();
	visited_dfs[visit]=true;

	list_visited_dfs.push_back(visit);
	
	cout << "방문안한곳은 "; 
	for(int i=1;i<graph[visit].size();++i) {
		if(graph[visit][i]==true)
			cout << i << ' ';
	}
	cout << "가 있음." << endl;  
	for(int i=1;i<graph[visit].size();++i) {
		if(visited_dfs[i]==false)
			if(graph[visit][i] == true) {
				graph[visit][i] = false;
				graph[i][visit] = false;
				cout << "그 중에서 "; 
				DFS( i );	
			}
	}
	cout << "이제 " << visit << "에서는 볼일 다보고 돌아감." << endl; 
}

void BFS(int visit) {
	queue<int> Q;
	visited_bfs[visit]=true;

	Q.push(visit);
	
	while(!Q.empty()) {
		int node = Q.front();
		Q.pop();
		list_visited_bfs.push_back(node);

		for(int i=1;i<graph[node].size();++i) {
			if(visited_bfs[i]==false)
				if(graph[node][i]==true) {
					graph[node][i]=false;
					graph[i][node]=false;
					visited_bfs[i]=true;
					Q.push(i);
				}
		}	
		
	}
	
}

int main(void)
{
	ifstream ifs("1260_1.txt");
	ifs >> N >> M >> V;
//	cin >> N >> M >> V;
	
	graph.resize(N+1, vector<bool>(N+1));
	visited_dfs.resize(N+1);
	visited_bfs.resize(N+1);
	
	for(int i=0;i<M;++i) {
		int node1, node2;
		ifs >> node1 >> node2;
//		cin >> node1 >> node2;
		graph[node1][node2]=true;
		graph[node2][node1]=true;		
	}
	ifs.close();
	
	vector< vector<bool> > graph_temp = graph;
	DFS(V);
	graph=graph_temp;
	
	for(int i=0;i<list_visited_dfs.size();++i) 
		cout << list_visited_dfs[i] << ' ';
	cout << endl;
	
	BFS(V);
	for(int i=0;i<list_visited_bfs.size();++i) 
		cout << list_visited_bfs[i] << ' ';
	cout << endl;
	
	
	return 0;
}
