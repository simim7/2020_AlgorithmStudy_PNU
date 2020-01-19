#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int R, C;
int cnt;
char** maze;

bool** maze_check;
bool** fire_check;

typedef pair<int,int> cd;
vector< queue<cd> > jihoon;
vector< queue<cd> > fire;

void print_maze(void)
{
	cout << "------------maze-------------" << endl << endl;
	for(int i=0;i<R;++i) {
		for(int j=0;j<C;++j)
			cout << maze[i][j] << '\t';
		cout << endl << endl;
	}
	cout << "-----------------------------" << endl;
}

bool boundary_check_valid(int x, int y)
{
	if(!(x>=0 & x<R))
		return false;
	if(!(y>=0 & y<C))
		return false;
	return true;
}


int escape(void)
{
	/* ÃÊ±â°ª ¼¼ÆÃ */  
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j) 
			if(maze[i][j]=='J') {
				jihoon[cnt].push(cd(i,j));
				maze_check[i][j]=true;
			}
			else if(maze[i][j]=='F') {
				fire[cnt].push(cd(i,j));	
				fire_check[i][j]=true;
			}
	
	while(true) {
		if(jihoon[cnt].empty()) return -1;
		
		while(!fire[cnt].empty()) {
			cd burn = fire[cnt].front();
			int x = burn.first, y = burn.second;
			fire[cnt].pop();
			
			if(boundary_check_valid(x-1,y)) {
				if(maze[x-1][y]!='#' && fire_check[x-1][y]==false) {
					maze[x-1][y]='F';
					fire[cnt+1].push(cd(x-1,y));			
					fire_check[x-1][y]=true;		
				}
			} 
			if(boundary_check_valid(x,y-1)) {
				if(maze[x][y-1]!='#' && fire_check[x][y-1]==false) {
					maze[x][y-1]='F';
					fire[cnt+1].push(cd(x,y-1));			
					fire_check[x][y-1]=true;		
				}
			} 
			if(boundary_check_valid(x+1,y)) {
				if(maze[x+1][y]!='#' && fire_check[x+1][y]==false) {
					maze[x+1][y]='F';
					fire[cnt+1].push(cd(x+1,y));					
					fire_check[x+1][y]=true;
				}
			} 
			if(boundary_check_valid(x,y+1)) {
				if(maze[x][y+1]!='#' && fire_check[x][y+1]==false) {
					maze[x][y+1]='F';
					fire[cnt+1].push(cd(x,y+1));		
					fire_check[x][y+1]=true;			
				}
			}
		}
//		cout << "=============ºÒ ¹øÁü=============" << endl; 
//		print_maze();	
		
		while(!jihoon[cnt].empty()) {
			cd run = jihoon[cnt].front();
			int x = run.first, y = run.second;
			jihoon[cnt].pop();
			
			if(boundary_check_valid(x-1,y)) {
				if(maze[x-1][y]=='.' && maze_check[x-1][y]==false) {
					jihoon[cnt+1].push(cd(x-1,y));			
					maze_check[x-1][y]=true;		
				}
			} else return 1;
			if(boundary_check_valid(x,y-1)) {
				if(maze[x][y-1]=='.' && maze_check[x][y-1]==false) {
					jihoon[cnt+1].push(cd(x,y-1));			
					maze_check[x][y-1]=true;		
				}
			} else return 1;
			if(boundary_check_valid(x+1,y)) {
				if(maze[x+1][y]=='.' && maze_check[x+1][y]==false) {
					jihoon[cnt+1].push(cd(x+1,y));					
					maze_check[x+1][y]=true;
				}
			} else return 1;
			if(boundary_check_valid(x,y+1)) {
				if(maze[x][y+1]=='.' && maze_check[x][y+1]==false) {
					jihoon[cnt+1].push(cd(x,y+1));		
					maze_check[x][y+1]=true;			
				}
			} else return 1;
		}
//		cout << "=============ÁöÈÆÀÌ ¶Ù°í³ª¼­=============" << endl; 
//		print_maze();


		
		cnt++;
	}

}

int main(void)
{
//	ifstream ifs("4179_9.txt");
//	ifs >> R >> C;
	
	jihoon.resize(1001);
	fire.resize(1001);
	cin >> R >> C;
	maze = new char*[R];
	for(int i=0;i<R;++i)
		maze[i] = new char[C];
		
	maze_check = new bool*[R];
	for(int i=0;i<R;++i)
		maze_check[i] = new bool[C];
	
	fire_check = new bool*[R];
	for(int i=0;i<R;++i)
		fire_check[i] = new bool[C];
	
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j) {
//			ifs >> maze[i][j];
			cin >> maze[i][j];
		}	
	
//	print_maze(); 
	
	int flag = escape();
	if(flag==-1) { cout << "IMPOSSIBLE" << endl; return 0; }
	if(flag==1) { cnt++; cout << cnt << endl; return 0; }
	
	
	return 0;
}
