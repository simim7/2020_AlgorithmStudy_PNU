// 0ms 

#include <iostream>
#include <cstring>

using namespace std;

bool is_palindrome(string src)
{
	for(int i=0,j=src.size()-1; i<j; ++i,--j) {
		if( !( src[i] == src[j] ) ) 
			return false;		
	}
	return true;	
}

int main(void)
{
	string input;
	
	cin >> input;
	
	printf("%d\n",is_palindrome(input));	
	
	return 0;
}

