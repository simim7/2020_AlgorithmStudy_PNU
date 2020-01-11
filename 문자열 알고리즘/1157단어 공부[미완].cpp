#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string word;
	vector<int> alphabet(26);
	
	cin >> word;
	for(int i=0; i<word.length(); ++i) {
		switch (word.at(i)) {
			case 'a':
			case 'A':
				alphabet.at(0)++;
				break;
			case 'b':
			case 'B':
				alphabet.at(1)++;
				break;
			case 'c':
			case 'C':
				alphabet.at(2)++;
				break;
			case 'd':
			case 'D':
				alphabet.at(3)++;
				break;
			case 'e':
			case 'E':
				alphabet.at(4)++;
				break;
			case 'f':
			case 'F':
				alphabet.at(5)++;
				break;
			case 'g':
			case 'G':
				alphabet.at(6)++;
				break;
			case 'h':
			case 'H':
				alphabet.at(7)++;
				break;
			case 'i':
			case 'I':
				alphabet.at(8)++;
				break;
			case 'j':
			case 'J':
				alphabet.at(9)++;
				break;
			case 'k':
			case 'K':
				alphabet.at(10)++;
				break;
			case 'l':
			case 'L':
				alphabet.at(11)++;
				break;
			case 'm':
			case 'M':
				alphabet.at(12)++;
				break;
			case 'n':
			case 'N':
				alphabet.at(13)++;
				break;
			case 'o':
			case 'O':
				alphabet.at(14)++;
				break;
			case 'p':
			case 'P':
				alphabet.at(15)++;
				break;
			case 'q':
			case 'Q':
				alphabet.at(16)++;
				break;
			case 'r':
			case 'R':
				alphabet.at(17)++;
				break;
			case 's':
			case 'S':
				alphabet.at(18)++;
				break;
			case 't':
			case 'T':
				alphabet.at(19)++;
				break;
			case 'u':
			case 'U':
				alphabet.at(20)++;
				break;
			case 'v':
			case 'V':
				alphabet.at(21)++;
				break;
			case 'w':
			case 'W':
				alphabet.at(22)++;
				break;
			case 'x':
			case 'X':
				alphabet.at(23)++;
				break;
			case 'y':
			case 'Y':
				alphabet.at(24)++;
				break;
			case 'z':
			case 'Z':
				alphabet.at(25)++;
				break;
		}
	}
	
	sort(alphabet.begin(), alphabet.end(), greater<int>());
	
	if(*alphabet.begin() == *(alphabet.begin()+1))
		cout << "?" << endl;
	else
		cout << *alphabet.begin() << endl;
	return 0;
}
