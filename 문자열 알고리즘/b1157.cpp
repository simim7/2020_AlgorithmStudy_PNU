//3536KB 92ms 1090B(x)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//void print(vector<char>& s){
//		for(int i=0; i<s.size(); i++)
// 		cout <<s[i];
// 	cout <<endl;
//}
//void print(vector< pair<int, char> >& m){
//		for(int i=0; i<m.size(); i++)
// 		cout <<m[i].first << 
//			" " << m[i].second<<endl;
//		cout <<endl;
//}
bool func(char a, char b){
		return a<b;
}

bool func_pair(pair<int,char> a, pair<int, char> b){
	return a.first > b.first;
}

int main(){
    char pc = 64;
    vector<char> s;
    vector< pair<int,char> > m;
    int Answer = 0, p, n=-1;
    
	while(cin.good()){
		char c= cin.get();
		if(c=='\n')
			break;
    	if(c >= 97) 
			c-=32;
		s.push_back(c);
	}
	
//	print(s);
 	sort(s.begin(), s.end(), func);
	s.push_back(64); 
//	print(s);
	
	
	for(char c : s){
	 	if(pc!=c){
	 		m.push_back(pair<int,char>(n,pc));
	 		n=0;
		 }
		 n++;
		 pc = c;
	}
	
//	print(m);

	sort(m.begin(), m.end(), func_pair);
//	print(m);

	
	if(m[0].first == m[1].first) cout<< '?';
	else cout<< m[0].second;

	
	//cout << Answer;
	return 0;
}
