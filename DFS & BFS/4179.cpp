// < 불! >  
//3888 KB	84 6ms	C++14 	2632B

#include <iostream>
#include <queue>

using namespace std;

/* 시행 착오 
DFS로 할 경우 시간초과남.  불과 지훈이의 위치를 되돌려놔야 해서
맵 전체의 변화가 크므로 한 depth 씩 진행하는 
BFS로 하는 것이 더 현명한 일이었다. 

그리고 queue에 넣고 방문 여부를 true로 해야 queue에 중복되서 안들어가는데
그걸 모르고 처음에 queue 에서 꺼낼 때 체크하여 메모리 초과가 발생했을 것.  

또한 보통 이런 맵 탐색 문제에서 행,렬이나 x,y축 이동 좌표를 배열로 정해놓고
편하게 for문을 돌린 후 범위 체크를 하는데 상하좌우 이동 후 범위 체크를 전부
if문으로 처리하고 범위 체크 후에 큐에 넣었더니 배열 범위를 벗어났는지 런타임에러가
떴다. 이유는 정확히 캐치하지 못했지만 방향 배열을 사용하니 에러가 사라졌다

그리고 IMPOSSIBLE 출력을 Impossible로 해서 틀렸습니다가 뜨기도 했다... 
*/

bool* isVisited;
char** Map;
queue<int> nodeQueue;
queue<int> fireQueue; 
	
int R,C;
int Moves = 0;
 
int rdir[4] = {-1,0,1,0};
int cdir[4] = {0,-1,0,1}; 

void print_map(){
	for(size_t i=0; i<R; i++){
		for(size_t j=0; j<C; j++)
			cout << Map[i][j]<< " ";
		cout <<endl;
	}
	cout <<endl;
}

void MoveFire(){
	int steps = fireQueue.size();
	for(int i=0; i<steps; i++){
		int curpos = fireQueue.front();
		fireQueue.pop();
		int r = curpos/C;  int c = curpos%C;
		for(int i=0; i<4; i++){
			int nextr = r + rdir[i];
			int nextc = c + cdir[i];
			if (0 <= nextr && nextr < R 
			   && 0 <= nextc && nextc < C ){
				if((Map[nextr][nextc]=='.' || Map[nextr][nextc]=='J' ))	{
			 		Map[nextr][nextc] = 'F';
				 fireQueue.push(nextr*C+nextc);
				}
			}
		}
	}
}

bool MoveMan(){	
	int steps = nodeQueue.size();
	for(int i=0; i<steps; i++){
		int curpos = nodeQueue.front();
		nodeQueue.pop();
		int r = curpos/C;  int c = curpos%C;			

		// 탈출구에 닿았을 시 탈출  
		if(r==0 || r==R-1 || c==0 || c==C-1){
			Moves++;
			return true;
		}
		
		for(int i=0; i<4; i++){
			int nextr = r + rdir[i];
			int nextc = c + cdir[i];
			if (0 <= nextr && nextr < R 
			   && 0 <= nextc && nextc < C 
			   && !isVisited[nextr*C+nextc]){
				if(Map[nextr][nextc]=='.')	{
			 	isVisited[nextr*C+nextc] = true;
				 nodeQueue.push(nextr*C+nextc);
				}
			}
		}
	}
	Moves++;
	return false; 
} 

bool Escape(){
	
	// 탈출구를 만나면 탈출 
	while(!nodeQueue.empty()){
		/*-------한 턴-----*/
		// 차피 사람이 움직이고 불이 와서 잡나, 불이 먼저움직여서 사람이 그리로 못가나
		// 마찬가지 이므로 불이 먼저 움직이고 사람의 움직임을 판단한다. 
		MoveFire();
		if(MoveMan()) return true;
		/*------------------*/

	}
	return false;
}

int main(void){

	cin >> R >> C;
	isVisited = new bool[R*C];
	fill(isVisited, isVisited+R*C, false);
	Map = new char*[R];
	for(int i=0; i<R; i++){
		Map[i] = new char[C];
		for(int j=0; j<C; j++){
			char c;
			cin >> c;
			Map[i][j] = c;
			if(c == 'J'){
				 nodeQueue.push(i*C+j);
				 isVisited[i*C+j]=true;
			}
			else if(c=='F'){
				fireQueue.push(i*C+j);
			}
		}
	}
	
	if(!Escape()) cout << "IMPOSSIBLE"; // 이걸 소문자로 했더니 틀림 
	else cout << Moves;
	
	delete isVisited;
	delete[] Map;
	//print_map();
	return 0;
}
