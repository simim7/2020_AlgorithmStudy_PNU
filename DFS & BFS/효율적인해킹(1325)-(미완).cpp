#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <queue>
#include <utility>

using namespace std;

int N, M;

vector< vector<bool> > trusts;
vector< vector<bool> > checked;
vector< pair<int,int >> max_nums;

bool compare(const pair<int,int>& p1, const pair<int,int>& p2) {
	if(p1.first>p2.first)
		return true;
	if(p1.first==p2.first)
		return p1.second < p2.second;
	return false;
}

void print_trusts(void) {
	cout << "============ trusts =============" << endl;
	for(int i=1;i<trusts.size();++i) {
		for(int j=1;j<trusts[i].size();++j) {
			cout << trusts[i][j] << '\t';
		}
		cout << endl << endl;
	}
	cout << "=================================" << endl;
}

void print_checked(int ii) {
	cout << "============ checked =============" << endl;
	for(int i=1;i<checked[ii].size();++i) {
		cout << checked[ii][i] << ' ';
	}
	cout << endl;
	cout << "=================================" << endl;
}		

void print_max_nums(void) {
	cout << "======== max_nums ========" << endl;
	for(int i=1;i<max_nums.size();++i)
		cout << max_nums[i].first << "(" << max_nums[i].second << ")" << ' ';
	cout << endl;
	cout << "==========================" << endl;
}

int get_max_hacking(int num_com) {
//	cout << "======================= " << num_com << " 해킹시작함 =======================" << endl; 
	int max=1;
	
	queue<int> Q;
	Q.push(num_com);
	
	while(!Q.empty()) {
		int target = Q.front();
		Q.pop();
		if(checked[num_com][target]==true) continue;
		
		checked[num_com][target] = true;
//		cout << target << " 조사 시작." << endl; 
//		print_checked(num_com);
		for(int i=1;i<trusts[target].size();++i)
			if(trusts[target][i]==true)
				if(checked[num_com][i]==false) {
//					cout << i << "가 " << target << "을 신뢰함." << endl; 
					Q.push(i);
					max++;
				}
	}

//	cout << "============================================================" << endl << endl;
	return max;
}

int main(void)
{
	int max=0;
//	ifstream ifs("1325_1.txt");
//	ifs >> N >> M;
	cin >> N >> M;
	
	trusts.resize(N+1, vector<bool>(N+1,false));
	max_nums.resize(N+1);
	checked.resize(N+1, vector<bool>(N+1,false));
	
	for(int i=0;i<max_nums.size();++i) {
		max_nums[i].second=i;
	}	
	max_nums[0].first=0;
	
	for(int i=0;i<M;++i) {
		int com1, com2;
//		ifs >> com1 >> com2;
		cin >> com1 >> com2;
		trusts[com2][com1]=true;
	}

//	print_trusts();
	
	for(int i=1;i<=N;++i) {
		max_nums[i].first = get_max_hacking(i);
	}
	
//	print_max_nums();
	
	sort(max_nums.begin()+1, max_nums.end(), compare);
	
//	print_max_nums();
	
	for(int i=1;i<max_nums.size();++i) {
		cout << max_nums[i].second;
		
		if(i==max_nums.size()-1)
			break;
		if(max_nums[i].first!=max_nums[i+1].first)
			break;
			
		cout << ' ';
	}
	cout << endl;

	
	return 0;
}
