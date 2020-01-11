#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	bool is_palindrome = false;
	
	cin >> s;
	auto it_left = s.begin();
	auto it_right = s.end()-1;
	
	size_t i;
	for(i=0; i<s.length()/2; ++i) { // Æ²·ÈÀ»¶§ for¹® Å»Ãâ ¾ÈÇÔ 
		if(*it_left == *it_right)
			is_palindrome = true;
		else
			is_palindrome = false;
		++it_left;
		--it_right;
	}
	if(is_palindrome == true)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
