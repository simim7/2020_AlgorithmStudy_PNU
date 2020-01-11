#include <iostream>

#include <vector>
#include <string>
using namespace std;

int main(void) {
	vector<string> vec;
	string s;
	
	do {
		cin >> s;
		vec.push_back(s);
	} while(getc(stdin)==' ');
	cout << s.length() << endl;
	
	return 0;
}
