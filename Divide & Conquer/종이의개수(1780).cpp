#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

int paper[2187][2187];
int N;
int paper_minus, paper_zero, paper_plus;

void print_paper(void) {
	cout << "----------------paper----------------" << endl << endl;
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j)
			cout << paper[i][j] << '\t';
		cout << endl << endl;
	}
	cout << "-------------------------------------" << endl;
}

bool is_same_number(int x, int y, int size) {
	cout << "---------------- 판단 ----------------" << endl;
	printf("x는 %d 부터 %d 까지, y는 %d 부터 %d 까지.\n", x, x+size-1, y, y+size-1); 
	int v = paper[x][y]; 
	for(int i=x; i<x+size; ++i)
		for(int j=y; j<y+size; ++j)
			if(paper[i][j]!=v) {
				cout << "같지 않음!" << endl; 
				cout << "--------------------------------------" << endl;
				return false;
			}
	cout << "같음!" << endl; 
	cout << "--------------------------------------" << endl;

	return true;
}



int main(void)
{
	ifstream ifs("1780_1.txt");
	ifs >> N;
	
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			ifs >> paper[i][j];
	
	print_paper();
	
	cout << is_same_number(0,0,N) << endl;
	
	return 0;
}
