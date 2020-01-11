#include <iostream>

using namespace std; 

int main(){
	bool flag=0;
	int cnt=0;
	char c;
	while(!cin.eof()){
		c = cin.get();
		if(isalpha(c) && !flag) 
			flag = 1;
		if(c==' ' && flag){
			cnt++;
			flag = 0;
		}
		if(c=='\n'){
			if(flag) cnt++;
			break;
		}
	}
	cout << cnt;	
	return 0;
}
