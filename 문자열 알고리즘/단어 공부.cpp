// 60ms
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int,char>> alpha;

bool compare(const pair<int,char> A, const pair<int,char> B) {
	return A.first > B.first;	
}

int main(void)
{
	char c;
	alpha.resize(26);
	
	for(int i=0;i<26;++i) {
		alpha[i].second = i;	
	}
	
	while(cin >> c) {
		c = toupper(c);
		++alpha[c-'A'].first;	
	}
	
	sort(alpha.begin(), alpha.end(), compare);
	
	if(alpha[0].first==alpha[1].first) {
		cout << "?" << endl;
	}
	else {
		cout << char(alpha[0].second+'A') << endl;
	}
	
	return 0;
}

