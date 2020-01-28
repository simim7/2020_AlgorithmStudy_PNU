#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

int MakeLineSize(int N) {
	int size = 1;
	for(int i=0; i<N; ++i) {
		size *= 2;
	}
	return size;
}

void Input(vector< vector<int> >& secArray, int lineSize) {
	for(int i=0; i<lineSize; ++i) {
		secArray.push_back(vector<int>(lineSize));
	}
}

void Qunquer(vector< vector<int> >& secArray, int _i, int _j) {
	for(int i=_i; i<_i+2; ++i) {
		for(int j=_j; j<_j+2; ++j) {
			secArray[i][j] = cnt;
			++cnt;
		}
	}
}

void Devide(vector< vector<int> >& secArray) {
	int i, j;
	for(i=0; i<secArray.size(); i+=2) {
		for(j=0; j<secArray.size(); j+=2) {
			Qunquer(secArray, i, j);
		}
	}
}

void Output(const vector< vector<int> >& secArray) {
	int r, c;
	cin >> r >> c;
	cout << secArray[r][c] << endl;
}

int main(void) {
	vector< vector<int> > secArray;
	int N, lineSize;
	cin >> N;
	
	lineSize = MakeLineSize(N);
	Input(secArray, lineSize);
	Devide(secArray);
	Output(secArray);
	
	return 0;
}
