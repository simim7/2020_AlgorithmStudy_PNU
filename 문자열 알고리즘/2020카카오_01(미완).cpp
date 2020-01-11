#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> compressed_length;

string int_to_string(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();	
}

string compress(string plain, int size)
{
	vector<string> tokens;
	string cypher;
	
	cout << "---------tokenizer---------" << endl;
	for(int i=0; i<plain.size(); i+=size) {
		printf("[%d, %d)\t==> ",i,i+size);
		cout << plain.substr(i,size) << ", " << plain.substr(i,size).size() << endl;
		tokens.push_back(plain.substr(i,size));		
		
		if(i+size>plain.size())
			break;
	}
	cout << "---------------------------" << endl;
//	for(int i=0;i<tokens.size();++i)
//		cout << tokens[i] << endl;
//	cout << endl;
	
	for(int i=0;i<tokens.size();++i) {
		string token = tokens[i];
		
		int number=1;
		
		while(tokens[i]==tokens[i+1]) {
			++number;
			++i;		
		}
		cypher += int_to_string(number) + token;
	}
	
	cout << cypher << endl;
	
	return cypher;
}

int main(void)
{
	string plain;
	
	cin >> plain;
	
	compressed_length.resize(plain.size()/2);
	 
	cout << "문자열의 길이\t: " << plain.size() << endl;
	cout << "배열의 크기\t: " << compressed_length.size() << endl; 
	
	compress(plain, 3);
	
	
	return 0;	
}
