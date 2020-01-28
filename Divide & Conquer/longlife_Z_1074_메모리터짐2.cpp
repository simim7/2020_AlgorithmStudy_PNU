#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> line;
typedef unsigned short us;

us row, col, order;
bool is_find = false;

void find_order(us x, us y, us sz)
{
	vector< line > *digits = new vector< line >(sz,line(sz));
	if(is_find){
		delete digits;
		return ;
	}
	else if(x==row && y==col){
		is_find = true;
		delete digits;
		return ;
	}
	else if(sz==1){
		order++;
		delete digits;
		return ;
	}
	else{
		sz /= 2;
		find_order(x,y,sz);			// 1) 상좌 
		find_order(x,y+sz,sz);			// 2) 상우 
		find_order(x+sz,y,sz);			// 3) 하좌 
		find_order(x+sz,y+sz,sz);		// 4) 하우 
		delete digits;
		return ;
	}
}


int main(void)
{
	us N, sz=2, cnt=0;
	cin >> N >> row >> col;
	for(us i=0;i<N;++i)
		sz*=2;
	
	find_order(0,0,sz);
	cout << order << endl;
	
	return 0;
}
