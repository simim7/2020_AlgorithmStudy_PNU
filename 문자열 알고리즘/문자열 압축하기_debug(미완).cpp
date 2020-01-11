#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string int_to_string(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();	
}

/* 문자로 RLE 압축 */ 
string char_RLE(string plain) 
{
	char c;
	int cnt;
	string cypher;	
	
	for(int i=0;i<plain.size();++i) {
		cnt = 1;
		c = plain[i];
		cypher += c;
		
		for(int j=i+1;j<plain.size() && plain[j]==c;++j) {
			++cnt;
			++i;
		}
		if( cnt > 1 ) {
			cypher += int_to_string(cnt);
		}
	}
	
	return cypher;
}
bool is_repeated(string plain, string substr, int index1, int index2)
{
	cout << "is Repeated?" << endl;
	cout << index1 << ", " << index2 << ", " << substr << endl;
	if(index2+(index2-index1)>plain.size()) return false;
	
	if(plain.substr(index2,index2-index1) == substr)
		return true;
	return false;
}

int get_repeated_time(string plain, string substr, int index1, int index2) 
{
	int size = index2-index1;
	int i;
	for(i=index2+size;i<plain.size() && plain[i]==plain[index1];i+=size) {
		if(i+size>plain.size()) break;
		if(plain.substr(i,size) != substr) {
			break;
		}				
	}
	
	cout << (i-index1)/size << " repeated." << endl;
	return (i-index1)/size;
}

bool is_efficient(string plain, int size, int number)
{
	int remove = size*(number-1);
	int add = 3;
	return remove >= add;	
}

/* 문자열을 이용한 RLC */ 
string str_RLE(string plain) 
{
	for(int i=0;i<plain.size();++i) {
		cout << "===========================" << endl;
		
		char target = plain[i];
		cout << "target: " << target << endl;
		if(target=='(' || target==')') {
			cout << "Invalid target." << endl;
			continue;
		}
		
		int j; 
	
		/* 목표문자와 같은 첫번째 문자를 찾음 */ 
		for(j=i+1;j<plain.size();++j) {
			if(plain[j] == target) {
				/* 찾았는데 1칸차이면 */
				if(j==i+1) {
					cout << "1 repeated. "; 
					int k;
					
					for(k=j+1; k<plain.size() && plain[k]==target; ++k);
				
					/* 압축이 더 비효율적 */	
					if(k-i<4){ cout << "But inefficient." << endl; continue; }
				
					/* 압축하는게 본전 이상일때 */ 
					cout << k-i << "times." << endl;
					cout << plain << " ==> ";
					
					/* 압축 */ 
					plain.replace(i,k-i,int_to_string(k-i)+"("+plain[i]+")");
					cout << plain << endl;
					
					continue;
				}
				
				/* i와 j에서 패턴이 반복되는지 검사 */
				if(is_repeated(plain, plain.substr(i,j-i), i, j)) { // 반복될때  
					cout << "Repeat." << endl;
					cout << plain.substr(i,j-i) << endl;
					int number = get_repeated_time(plain, 
												plain.substr(i,j-i),i,j); // 몇번 반복되는지  
					
					if(is_efficient(plain,j-i,number)) { // replace가 효율적일때 
						cout << "replace is efficient." << endl;
						
						/* 압축 */ 
						cout << plain << " ==> ";
						plain.replace(i, (j-i)*number, 
									int_to_string(number)+"("+plain.substr(i,j-i)+")"); 
						cout << plain << endl;
						continue; 
					}
					else { // replace 안하는게 나을때 
						cout << "replace is inefficient." << endl;
						
					}
					
					for(int n=i, m=j; n<j; ++n,++m) {
						cout << plain[n] << "||" << plain[m] << endl;
					}
				}
				else { // 반복되지 않을때  
					cout << "No repeat." << endl; 	
				}
		
			}
		}
		
		
	
	}
	
	return plain;	
}

int main(void)
{
	string plain;
	
	cin >> plain;
	
	string char_after = char_RLE(plain);
	string str_after = str_RLE(plain);
	
	cout << "==========Final==========" << endl;

	cout << "<문자열 비교>" << endl; 
	cout << "원래 문자열\t: " << plain << endl;
	cout << "char 압축후\t: " << char_after << endl;
	cout << "str 압축후\t: " << str_after << endl;
	
	cout << endl;
	cout << "<길이 비교>" << endl;
	cout << "원래 문자열\t: " << plain.size() << endl;
	cout << "char 압축후\t: " << char_after.size() << endl;
	cout << "str 압축후\t: " << str_after.size() << endl;

	cout << endl;
	cout << "더 짧은 길이 ==> " << min(char_after.size(),str_after.size()) << endl; 
	return 0;
}
