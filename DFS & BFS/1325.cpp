// < 효율적인 해킹 > 
//3196KB	3976ms	C++17 	1797B

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*시행 착오 
 dfs를 사용해서 문제해결을 시도했다.
 원래는 dfs를 각 노드에서 완전 다 수행되지 않고 중간에 cut 되게 하기 위해서 이전 dfs정보를 이용하려 했으나
 생각해보니 루프 형태일 수가  있더라. 루프가 생기면 루프 내의 모든 노드들은 같은 해킹 수를 지니는데, 
 루프가 하나가 아니고 많이 존재하는 그래프 형태일 수 있어서 되게 복잡해진다. 그래서 결국 각 노드마다 dfs를 수행하기로 결정.
 
 그래서 각 노드마다 일반적인 dfs방식으로 해킹 가능한 노드 수를 체크한 후 방문 여부 배열을 새로 설정하는 방식으로 했다.
 근데 시간초과가 떴다. 그래서 시간을 줄여보고자 이래저래 시도했는데 처음에는 벡터에 해킹 가능한 노드 수와 dfs로 체크하는 노드번호를 
 pair 로 저장해 마지막에 sorting 한 후 가장 많이 해킹하는 노드를 출력했었다.
 
 삽입 수와 정렬 시간을 줄이기 위해 일단 노드번호가 높은 것부터 dfs를 돌렸다. 그리고 MaxNum (최다 해킹 노드 수)를 갱신하거나 같을 때마다 
 stack에 저장했다. 그러면 마지막에는 (해킹 노드 수, 노드번호)가 stack에 해킹 노드 수가 높은 것부터  
 stack의 top부터 아래로  노드번호는 오름 차순으로 저장될테니까 해킹 노드 수가 바뀔 때까지 하나씩 꺼내서 노드 번호를 출력하면 노드 번호가
 오름차순으로 출력 될 것. 근데 이래도 처음엔 시간초과가 떴다.. 
  
  <이상한점?> 
    해도해도 통과가 안되길래 
	C++14 사용 시 continue 사용하면 시간 초과가 떠서 
	C++17을 사용해서 continue를 안쓰니 통과되었다. continue를 쓰니 조금 더 오래 걸렸지만
	통과된다.
	다시 C++14를 사용해서 둘 다 해보니?? 된다?? 이유를 모르겠음.
	실제로는 약간의 시간차이가 몇 ms 안났음.
	
	* 실행할 때마다 시간이 차이가 좀 나는데 로직이 많이 돌아가서 그런 듯 
*/ 

int N,M;
vector<int>* Graph;
stack< pair<int,int> > Answer;
vector<bool> Visited;
int Num = 0;
int MaxNum = 0;


void print_Graph(){
	for(int i=1; i<N+1; i++){
		cout << i << ": ";
		for(int j=0; j< Graph[i].size(); j++){
			cout << Graph[i][j] << " ";
		}
		cout <<endl;
	}
}

  
void Hack(int i){
	Num++; 
//	vector<int> ERs = Graph[i];
	for(size_t j=0; j<Graph[i].size(); j++){
		int ER = Graph[i][j];
			if( !Visited[ER-1]) {
			Visited[ER-1] = true;
			Hack(ER);
		}
	}
}



int main(void){
	cin >> N >> M;
	Graph = new vector<int>[N+1];
//	for(size_t i=1; i<=N; i++)
//		Answer.push_back(pair<int,int>(i,0));
	
	Visited = vector<bool>(N,false);
	for(size_t i=0; i<M; i++){
		int ER, EE;
		cin >> ER >> EE;
		Graph[EE].push_back(ER);
	}
	
	for(size_t i=N; i>=1; i--){
//		cout << "i : " << i << " ,size : " << Graph[i].size() <<endl; 
		if(Graph[i].size() > 0) {
			fill(Visited.begin(), Visited.end(), false);
			Visited[i-1] = true;
			Hack(i);
//		cout << "Num :  " << Num <<endl;
			if(Num >= MaxNum){
				MaxNum = Num;
				Answer.push(make_pair(Num, i));
			}	
		
			Num=0;
		}	
	}
	
//	print_Graph();
	
//	sort(Answer.begin(), Answer.end(), func);
	
//	for(size_t i=0; i<N; i++){
//		cout<< Answer[i].first<< " " <<Answer[i].second <<endl;
//	}
//	cout << MaxNum <<endl;
	int StackSize = Answer.size();
	for(size_t i=0; i<StackSize; i++){
//		cout << "Stack size : " << Answer.size() <<endl;
		pair<int,int> Top = Answer.top();
//		cout << "first : " << Top.first <<endl; 
		if(Top.first != MaxNum) break;
//		cout << "second : " << Top.second <<endl; 
		cout << Top.second <<" ";
		Answer.pop();
	}
	
	return 0;
}
