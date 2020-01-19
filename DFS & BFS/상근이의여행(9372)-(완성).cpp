// 100ms

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int testCase;
int count;
vector< vector<bool> > planes;
vector< bool > visited;

bool check_all_visited(void) {
	for(int i=1;i<visited.size();++i) 
		if(!visited[i])	
			return false;		
	return true;		
}

void check_planes(void) {
	for(int i=2;i<planes.size();++i) 
		cout << "========";
	cout << "=" << endl;
	for(int i=1;i<planes.size();++i) {
		for(int j=1;j<planes[i].size();++j) 
			cout << planes[i][j] << '\t';
		cout << endl << endl;
	}
	for(int i=2;i<planes.size();++i) 
		cout << "========";
	cout << "=" << endl;
}

void where_to_go(int here) {
	for(int j=1;j<planes[here].size();++j)  
		if(planes[here][j]==true)	{
			if(visited[j]==false) {
//				cout << j << " 방문함." << endl; 
				count++;
				visited[j]=true;
				return;
			}
		}
//	cout << endl;
}

void get_min_plane(void) {
	count=0;
	
	visited[1]=true;
	while(!check_all_visited()) {
//		cout << "========= 훑어보기 시작 ==========" << endl;
		for(int i=1;i<visited.size();++i) 
			if(visited[i]==true) {
				where_to_go(i);
				
			}
	}	
}

int main(void)
{
//	ifstream ifs("9372_1.txt");
//	ifs >> testCase;
	cin >> testCase;
	
	for( ;testCase>0;--testCase) {
		int N, M;
		
		planes.clear();
		visited.clear();
		
//		ifs >> N >> M;
		cin >> N >> M;
		planes.resize(N+1, vector<bool>(N+1,false));
		visited.resize(N+1);
		visited[0]=true;
		
		int city1, city2;
		for(int i=0;i<M;++i) {
//			ifs >> city1 >> city2;
			cin >> city1 >> city2;
			planes[city1][city2]=true;
			planes[city2][city1]=true;
		}
		
//		check_planes();
		get_min_plane();
		cout << count << endl;
		
	}
	
	
	return 0;
}
