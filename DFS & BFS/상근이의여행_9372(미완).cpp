#include <bits/stdc++.h>

using namespace std;

class testCase {
    int N; // 국가의 수(2<=N<=1000)
    int M; // 비행기의 종류(1<=M<=10000)
    vector< pair<int,int> > schedule;
public:
    testCase(int n, int m) {
        N = n;
        M = m;
    }
public:
    int getNation(void) const {
        return N;
    }
    int getAirplane(void) const {
        return M;
    }
    void pushSchedule(int f, int s) {
        schedule.push_back(make_pair(f,s));
    }
    void printSchedule(void) {
        for(int m=0; m<M; ++m) {
            cout << "(" << schedule[m].first << "," << schedule[m].second << ")";
            cout << endl;
        }
    }
};

int main(void)
{
    ifstream ifs("test1.inp");
    int T = 0; // 테스트 케이스의 수
    ifs >> T;

    vector<testCase> totalSchedule;

    for(int t=0; t<T; ++t) {
        int n = 0; // 국가의 수
        int m = 0; // 비행기의 종류
        ifs >> n >> m;
        testCase tmpCase(n,m);
        int a = 0, b = 0;
        for(int mm=0; mm<m; ++mm) {
            ifs >> a >> b;
            tmpCase.pushSchedule(a, b);
        }
        totalSchedule.push_back(tmpCase);
     }

     for(int i=0; i<totalSchedule.size(); ++i) {
        cout << i << "th : N=" << totalSchedule[i].getNation() << ", M=" << totalSchedule[i].getAirplane() << endl;
        totalSchedule[i].printSchedule();
     }

    ifs.close();

    return 0;
}
