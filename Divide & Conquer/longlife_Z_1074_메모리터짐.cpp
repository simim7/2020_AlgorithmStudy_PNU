#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> line;

int row, col, order;
bool is_find = false;

void find_order(vector< line >& digits, int x, int y, int sz)
{
	if(is_find)
		return ;
	else if(x==row && y==col){
		is_find = true;
		return ;
	}
	else if(sz==1){
		order++;
		return ;
	}
	else{
		sz /= 2;
		find_order(digits,x,y,sz);				// 1) ÁÂ»ó 
		find_order(digits,x,y+sz,sz);			// 2) ¿ì»ó
		find_order(digits,x+sz,y,sz);			// 3) ÁÂÇÏ 
		find_order(digits,x+sz,y+sz,sz);		// 4) ¿ìÇÏ
		return ;
	}
}


int main(void)
{
	int N, cnt=0;
	cin >> N >> row >> col;
	double sz = pow((double)2,(double)N);
	vector< line > digits (sz,line(sz));
	
	for(int i=0;i<digits.size();++i)
		for(int j=0;j<digits[i].size();++j)
			digits[i][j] = cnt++;
	
	find_order(digits,0,0,sz);
	cout << order << endl;
	
	return 0;
}
