#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> line;

int row, col, order;
bool is_find = false;

void find_order(int x, int y, int sz)
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
		find_order(x,y,sz);				// 1) ÁÂ»ó 
		find_order(x,y+sz,sz);			// 2) ¿ì»ó
		find_order(x+sz,y,sz);			// 3) ÁÂÇÏ 
		find_order(x+sz,y+sz,sz);		// 4) ¿ìÇÏ
		delete digits;
		return ;
	}
}


int main(void)
{
	int N, cnt=0;
	cin >> N >> row >> col;
	double sz = pow((double)2,(double)N);
	
	find_order(0,0,sz);
	cout << order << endl;
	
	return 0;
}
