/*
	N x N 을 입력받는다.
	(Conquer)N x N 을 검사하면서 첫 번째 숫자와 끝까지 계속 같은지 비교한다.
	이때, 끝가지 계속 같으면 그 숫자의 카운트를 1 증가시킨다. 
	다르면 N/3 x N/3 으로 쪼개어(Divide) 9등분 한다.
	9등분한 각각의 행렬에 (Conquer)을 반복한다. 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Count {
	int negative_1;
	int zero;
	int one;
};

struct Count Cnt;

void Input(vector< vector<int> >& paper, int N) {
	int number;
	vector<int> line;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			cin >> number;
			line.push_back(number);
		}
		paper.push_back(line);
		line.clear();
	}
	Cnt.negative_1 = 0;
	Cnt.zero = 0;
	Cnt.one = 0;
}

void Divide(const vector< vector<int> >&, int, int, int, int);

void Conquer(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2) {
	int p_number = paper[s1][s2];
	int i, j;
	for(i=s1; i<f1; ++i) {
		for(j=s2; j<f2 && (p_number == paper[i][j]); ++j)
			; // 비교하다가 끝까지 같으면 종료, 다르면 Divide.
		if(j<f2) {
			Divide(paper, s1, s2, f1, f2);
			break;
		}
	} // 다 같으면 숫자 카운트 증가. 
	if(p_number == -1) ++Cnt.negative_1;
	else if(p_number == 0 ) ++Cnt.zero;
	else if(p_number == 1 ) ++Cnt.one;
	return;
}

void Divide(const vector< vector<int> >& paper, int s1, int s2, int f1, int f2) {
	Conquer(paper, s1, s2, f1/3, f2/3);
	Conquer(paper, s1, f2/3, f1/3, f2/3+f2/3);
	Conquer(paper, s1, f2/3+f2/3, f1/3, f2);
	Conquer(paper, f1/3, s2, f1/3+f1/3, f2/3);
	Conquer(paper, f1/3, f2/3, f1/3+f1/3, f2/3+f2/3);
	Conquer(paper, f1/3, f2/3+f2/3, f1/3+f1/3, f2);
	Conquer(paper, f1/3+f1/3, s2, f1, f2/3);
	Conquer(paper, f1/3+f1/3, f2/3, f1, f2/3+f2/3);
	Conquer(paper, f1/3+f1/3, f2/3+f2/3, f1, f2);
	// 9등분. 
}

void Process(const vector< vector<int> >& paper, int N) {
	Conquer(paper, 0, 0, N, N); // 0,0부터 N-1, N-1까지 탐색. 
}

void Output(void) {
	cout << Cnt.negative_1 << endl;
	cout << Cnt.zero << endl;
	cout << Cnt.one << endl;
}

int main(void) {
	vector< vector<int> > paper;
	int N;
	cin >> N;

	Input(paper, N);
	Process(paper, N);
	Output();
	
	//
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j)
			cout << paper[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
