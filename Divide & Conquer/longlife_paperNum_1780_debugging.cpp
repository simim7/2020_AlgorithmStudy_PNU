/* 
여기서 핵심은 numeric 헤더에 들어있는  accumulate함수!
*/ 


#include <iostream>
#include <fstream>
#include <vector>
#include <numeric> 

using namespace std;

typedef vector<long long> line;

long long NumZero, NumOne, NumMinus, val_th;

void print_paper(vector< line >& paper)
{
	cout << "------------------------------- paper -------------------------------" << endl << endl;
	for(int i=0;i<paper.size();++i){
		for(int j=0;j<paper[i].size();++j)
			cout << paper[i][j] << '\t';
		cout << endl << endl;
	}
	cout << "---------------------------------------------------------------------" << endl << endl;
}

void print_sumLine(vector<long long>& sum_line)
{
	cout << "------------------------------ sum line ------------------------------" << endl << endl;
	for(int i=0;i<sum_line.size();++i)
		cout << sum_line[i] << '\t' ;
	cout << endl << "---------------------------------------------------------------------" << endl << endl;
}

void find_paperNum(vector< line >& paper, long long row, long long col, long long sz)
{
	long long is_NumZero = 0*sz*sz;			// 0 종이 합 
	long long is_NumOne = 1*sz*sz;			// 1 종이 합 
	long long is_NumMinus = val_th*sz*sz;	// -1 종이 합 
	vector<long long> sum_line;
	for(int i=row;i<row+sz;++i)
		sum_line.push_back(accumulate(paper[i].begin()+col,paper[i].begin()+col+sz,0));
	print_sumLine(sum_line);
	
	long long sum_val = accumulate(sum_line.begin(),sum_line.end(),0);
	cout << "sum val : " << sum_val << endl;	
	cout << "N*N : " << sz*sz << endl << endl;
	
	if(sum_val == is_NumZero){ 			// 0 종이일 경우 
		NumZero++;
		return ;
	}
	else if(sum_val == is_NumOne){		// 1 종이일 경우 
		NumOne++;
		return ;
	}
	else if(sum_val == is_NumMinus){	// -1 종이일 경우
		NumMinus++;
		return ;
	}
	else{
		sz/=3;
		find_paperNum(paper,row,col,sz);				// 1) 위, 왼 
		find_paperNum(paper,row,col+sz,sz);				// 2) 위, 중간 
		find_paperNum(paper,row,col+(2*sz),sz);			// 3) 위, 오른 
		find_paperNum(paper,row+sz,col,sz);				// 4) 중간, 왼
		find_paperNum(paper,row+sz,col+sz,sz);			// 5) 중간, 중간 
		find_paperNum(paper,row+sz,col+(2*sz),sz);		// 6) 중간, 오른 
		find_paperNum(paper,row+(2*sz),col,sz);			// 7) 아래, 왼
		find_paperNum(paper,row+(2*sz),col+sz,sz);		// 8) 아래, 중간 
		find_paperNum(paper,row+(2*sz),col+(2*sz),sz);	// 9) 아래, 오른 
		return ;	
	}
}

void processing(istream& is)
{
	long long N, tmp;
	is >> N;
	val_th = N*N + 1;
	vector< line > paper(N,line(N));
	for(int i=0;i<paper.size();++i)
		for(int j=0;j<paper[i].size();++j){
			is >> tmp;
			if(tmp == -1)
				paper[i][j] = val_th;
			else
				paper[i][j] = tmp;
		}
	print_paper(paper);
	
	find_paperNum(paper,0,0,N);

	cout << "-1 : " << NumMinus << endl;
	cout << "0 : " << NumZero << endl;
	cout << "1 : " << NumOne << endl;
}

int main(void)
{
	const char* ifn = "paperNum_1780.txt";
	
	ifstream ifs(ifn);
	if(!ifs.is_open()){
		cerr << "Error: the input file cannot be opened." << endl;
		return -1;
	}
	
	processing(ifs);
	
	ifs.close();
	 
	return 0;
}
