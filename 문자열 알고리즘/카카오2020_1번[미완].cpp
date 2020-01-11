#include <iostream>
#include <string>
#include <vector>
using namespace std;

void find_divisor(const string s, vector<int>& divisor) {
    int len = s.length();
    for(int i=1; i<=len/2; ++i) {
        if( len%i == 0 )
            divisor.push_back(i);
    }
}

int solution(string s) {
    vector<char> string;
    vector<int> divisor;
    int selected_divisor = 0;
    int answer = 0;
    
    answer = s.length();
    
    find_divisor(s, divisor);
    
    int myint = 0;
    while( !divisor.empty() ) {
    	cout << "myint: " << ++myint << endl;;
        selected_divisor = divisor.back();
        divisor.pop_back();
        cout << "selected_divisor: " << selected_divisor << endl;
        
        int string_i = 0;
        int swit = 0; // 1: duplicated -> none
        for(int i=0; i<s.length(); ) {
            if( string.empty() ) {
                for(int j=0; j<selected_divisor; ++j) {
                    string.push_back(s.at(i));
                    ++i;
                }
            }
            int clone_i = i;
            int clone_string_i = string_i;
            int t;
            for(t=0; t<selected_divisor && !(string.at(clone_string_i)!=s.at(clone_i))
                ; ++t, ++clone_string_i, ++clone_i)
                ;
            if(t<selected_divisor) {
				for(int j=0; j<selected_divisor; ++j) {
					string.push_back(s.at(i));
                	++i;
                	++string_i;
            	}
            	if(swit == 1) {
            		++string_i;
            		swit = 0;
            	}
                cout << "escaped" << endl;
            }
            else {
                string.push_back('1');
                for(int j=0; j<selected_divisor; ++j) {
                    ++i;
                }
                swit = 1;
                cout << "not escaped" << endl;
            }
        }
        answer = string.size() + duplicated_num;
        cout << "answer: " << answer << endl;
        string.clear();
    }
    return answer;
}

int main(void) {
	string input_string;
	int answer;
	
	cin >> input_string;
	
	answer = solution(input_string);
	
	cout << answer;
	
	return 0;
}
