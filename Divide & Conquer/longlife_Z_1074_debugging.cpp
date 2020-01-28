#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> line;

int row, col, order;
bool is_find = false;

void print_digits(vector< line >& digits)
{
	cout << "------------------------------- digits -------------------------------" << endl << endl;
	for(int i=0;i<digits.size();++i){
		for(int j=0;j<digits[i].size();++j)
			cout << digits[i][j] << '\t';
		cout << endl << endl;
	}
	cout << "----------------------------------------------------------------------" << endl << endl;
}


void find_order(vector< line >& digits, int x, int y, int sz)
{
	if(is_find)
		return ;
	else if(x==row && y==col){
		cout << "x : " << x << '\t' <<"y : " << y << '\t' <<"order : " << order << endl;
		is_find = true;
		return ;
	}
	else if(sz==1){
		order++;
		cout << "x : " << x << '\t' <<"y : " << y << '\t' <<"order : " << order << endl;
		return ;
	}
	else{
		sz /= 2;
		find_order(digits,x,y,sz);				// 1) ÁÂ»ó 
		find_order(digits,x,y+sz,sz);			// 2) ¿ì»ó
		find_order(digits,x+sz,y,sz);			// 3) ÁÂÇÏ 
		find_order(digits,x+sz,y+sz,sz);		// 4) ¿ìÇÏ
		cout << endl;
		return ;
	}
}

void processing(istream& is)
{
	int N, cnt=0;
	is >> N >> row >> col;
	cout << "row & col : " << row << ' ' << col << endl;
	double sz = pow((double)2,(double)N);
	vector< line > digits (sz,line(sz));
	
	for(int i=0;i<digits.size();++i)
		for(int j=0;j<digits[i].size();++j)
			digits[i][j] = cnt++;
	print_digits(digits);
	
	find_order(digits,0,0,sz);
	cout << "order : " << order << endl;
	
}

int main(void)
{
	const char* ifn = "Z_1074.txt";
	
	ifstream ifs(ifn);
	if(!ifs.is_open()){
		cerr << "Error: the input file cannot be opened." << endl;
		return -1;
	}
	
	processing(ifs);
	
	ifs.close();
	 
	return 0;
}
 
