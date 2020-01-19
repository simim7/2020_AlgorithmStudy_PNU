//time 80ms
#include <iostream>

using namespace std;

int main(void) {
    int testCase,country,airplane,garbage;
    cin>> testCase;
    int numbersOfMinAirplane[testCase];
    for(int i=0; i<testCase; ++i) {
        cin>>country;
        cin>>airplane;
        for(int j=0; j<airplane; ++j) {
            cin>>garbage>>garbage;
        }
        numbersOfMinAirplane[i] = country-1;
    }
    for(int i=0; i<testCase; ++i) {
        cout<< numbersOfMinAirplane[i]<<endl;
    }
    return 0;
}