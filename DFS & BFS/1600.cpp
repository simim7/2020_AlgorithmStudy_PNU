// < 말이 되고픈 원숭이 > 
//	4872KB	100ms	C++14 	2353B

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* 시행착오
 문제 유형을 연속해서 여러개 풀고 나니까 처음에 접근이 쉬워보였다. 
 말처럼 K번 이동하는 것을 어떻게 제한하느냐를 생각하다가 BFS로 탐색할 떄 각 노드를
 큐에 넣을 때 K를 소비할 경우 이전 노드에서 소비한 K에 +1해서 저장하는 식으로 
 저장읋 한후 K제한이 넘으면 큐에 넣지 않도록 했다.
  -> queue< pair <int,int > >는 ( 좌표정보, K수 )이다.
 
  근데 틀렸다해서 생각해보니까  문제에서는 점프(말의 이동) 과 스텝(한 칸 이동)을 통해  
  노드를 방문하기 때문에  해당 노드를 방문할 때 j-s-j-s(K=2)  s-s-s-s-s(K=0).. 이런 식으로 같은 노드를 방문할 수 있다. 
  전자에서 방문여부를 체크해버리면 점프 수(K) 가 정해져 있으므로 점프 소비 개수에 따라 경로가 다양한데
  그것들을 막아버린다. 그래서 방문 여부 체크 할 때 K의 개수에 따라 달리하기 위해 K길이의 bool 벡터를 요소로 갖는 벡터로 방문 여부를 체크했음.
  
  근데도 틀리고 메모리 초과해서 점프랑 스텝 벡터를 나누고 하나를 빼보고 해봤는데도 통과가 안되길래 소스를 다시보니
    	if(!Visited[nextr*W + nextc][Ks+1] && Map[nextr][nextc]==0 ) 이부분에서 Ks+1 을 해줘야 하는데 Ks 를 체크했던 것이어서
  이부분을 수정하니 통과되었다. 혹시 몰라 스텝과 점프 벡터를 나누어서 돌려보니 통과는 된다 근데 메모리는 1.5배, 시간은 2배정도 더 든다.
   BFS에서 처리할 때는 배열을 두 개 쓴다 해도 따로따로 처리하므로  시간이 2배나 더 들진 않을텐데 메모리 할당 해제에 시간이 더 드는 걸까?
   아니면 배열을 하나만 사용하면 메모리 스택에서 처리할 때 locality 상 유리해서 그런건지.. 정확한 이유를 모르겠다.
  
*/

vector<bool>* Map;
//vector< vector<bool> > stepVisited;
//vector< vector<bool> > jumpVisited;
vector<vector<bool> > Visited;
queue< pair<int,int> > posQueue;
//         좌표정보 , K 수   

int K,W,H; 
int Move=0;

int rdir[12] = { 0, -1, 0, 1, -1, -2, -2, -1, 1 , 2 , 2 , 1};
int cdir[12] = { -1, 0, 1, 0, -2, -1,  1,  2,-2, -1,  1,  2};

//void print(){
//	for(size_t i=0; i<H; i++){
//		for(size_t j=0; j<W; j++){
//			cout  <<  Map[i][j] <<  " ";
//		}
//		cout <<endl;
//	}	
//}

int BFS(){
	int pos;

	posQueue.push(make_pair(0,0));	
	for(int i=0; i<=K; i++){
//		stepVisited[0][i] = true;	
//		jumpVisited[0][i] = true;	
		Visited[0][i]= true;
	}
	
	while(!posQueue.empty()){
//		cout << "-----------MOVE : " << Move << "-----------------" <<endl;
		int queueSize = posQueue.size();
		for(int p=0; p<queueSize; p++){
			pos = posQueue.front().first;
			int Ks = posQueue.front().second;	
			if(pos == W*H-1 && Ks <= K) 
				return Move;
			int r = pos/W; int c = pos%W; 	
//			cout << "r : " <<r << " c : " << c << " K : " << Ks << endl;	
			posQueue.pop();			
			for(int i=0; i<12; i++){
				
				int nextr = r+rdir[i]; int nextc = c+cdir[i];
				// In Range
				if( 0<= nextr && nextr <= H-1 && 0 <= nextc && nextc <= W-1){
					
					if( i>=4 && Ks < K ){
						if(!Visited[nextr*W + nextc][Ks+1] && Map[nextr][nextc]==0 ){ // 여기서 방문 체크할 때 Ks+1을 안했었음.. 
//							cout<< "JUMP & PUSHING " << nextr << ", " << nextc <<endl; 
							posQueue.push(make_pair(nextr*W+nextc, Ks+1));
							Visited[nextr*W+nextc][Ks+1] = true;
						}
					}
					else if( i< 4 ){
						if(!Visited[nextr*W + nextc][Ks] && Map[nextr][nextc]==0 ){
//							cout<< "STEP & PUSHING " << nextr << ", " << nextc <<endl; 
							posQueue.push(make_pair(nextr*W+nextc, Ks));
							Visited[nextr*W+nextc][Ks] = true;
						}
						
					} 
					
				}
			}	
		}
		Move++;
	}
	
	return -1;
}

int main(void){
	cin >> K >> W >> H;
	Map = new vector<bool>[H];
//	stepVisited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
//	jumpVisited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
	Visited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
	for(int i=0; i<H; i++){
		Map[i] = vector<bool>(W);
		for(int j=0; j<W; j++){
			bool b;	 cin >> b;	Map[i][j] = b;
		}
	}
	
	cout << BFS();
	
	return 0; 
}
