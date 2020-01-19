#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int M, N, K;
vector< vector<char> > paper; 
vector<int> areas;

void print_paper(void) {
	cout << "=================================================" << endl;
	for(int i=0;i<paper.size();++i) {
		for(int j=0;j<paper[i].size();++j) 
			cout << paper[i][j]	<< '\t';
		cout << endl << endl;		
	}
	cout << "=================================================" << endl;
}

/* 좌표가 유효한지 체크 */ 
bool is_in_boundary(int x, int y) {
	if(!(x >= 0 && x < M)) return false;
	if(!(y >= 0 && y < N)) return false;
	return true;
}

/* 빈 영역 X 채우기 */ 
int draw_X(int x, int y, int area) { 
	paper[x][y] = 'X';
//	print_paper();
	
	if(is_in_boundary(x-1,y)) 
		if(paper[x-1][y]=='0') 
			area = draw_X(x-1,y,++area);		
	
	if(is_in_boundary(x,y-1)) 
		if(paper[x][y-1]=='0') 
			area = draw_X(x,y-1,++area);
	
	if(is_in_boundary(x+1,y)) 
		if(paper[x+1][y]=='0') 
			area = draw_X(x+1,y,++area);
	
	if(is_in_boundary(x,y+1)) 
		if(paper[x][y+1]=='0') 
			area = draw_X(x,y+1,++area);
			
	return area;
}

/* 사각형 내부 #으로 채우기 */ 
void draw_rectangle(int lx, int ly, int rx, int ry) {
	for(int x=ly; x<ry;++x) 
		for(int y=lx; y<rx; ++y) 
			paper[x][y] = '#';
}

int main(void)
{	
//	ifstream ifs("input1.txt");
//	if(!ifs.is_open()) {
//		cout << "안열림!" << endl;	
//	}
	
	cin >> M >> N >> K;
	paper.resize(M,vector<char>(N,'0'));
	
	for(int i=0;i<K;++i) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;	
		draw_rectangle(lx,ly,rx,ry);
		//print_paper();
	}
	
	for(int i=0;i<M;++i) {
		for(int j=0;j<N;++j) {
			if(paper[i][j] == '0') {
				//cout << "그리기작업 시작: (" << i << ", " << j << ")" << endl; 
				areas.push_back(draw_X(i,j,1));
				//print_paper();
			}
			
		}
	}
	sort(areas.begin(),areas.end());
	cout << areas.size() << endl;
	for(int i=0;i<areas.size();++i) 
		cout <<	areas[i] << ' ';
	cout << endl;

//	ifs.close();
	return 0;
}
