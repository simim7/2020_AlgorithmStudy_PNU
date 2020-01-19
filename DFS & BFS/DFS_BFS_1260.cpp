#include <bits/stdc++.h>

using namespace std;

vector<int> resultBFS, resultDFS;
vector< pair<int,bool> > isVisited; // (정점,방문했는지의 유무)

bool compare1(const pair<int,vector<int> > a, const pair<int,vector<int> > b)
{
    return a.first<=b.first;
}
bool compare2(const pair<int,int> a, const pair<int,int> b)
{
    return a.first<=b.first;
}
bool isExist(const int a)
{
    for(int i=0; i<isVisited.size(); ++i) {
        if(a == isVisited[i].first) return true;
    }
    return false;
}
bool isVisit(const int a)
{
    for(int i=0; i<isVisited.size(); ++i) {
        if(a == isVisited[i].first) {
            return isVisited[i].second;
        }
    }
}
void checkVisit(const int a)
{
    for(int i=0; i<isVisited.size(); ++i) {
        if(a == isVisited[i].first && isVisited[i].second == false) {
            isVisited[i].second = true;
        }
    }
}
int findIndex(const int a, const vector< pair<int,vector<int> > > edge)
{
    for(int i=0; i<edge.size(); ++i) {
        if(a == edge[i].first) {
            return i;
        }
    }
    return -1;
}
void printEdge(vector< pair<int,vector<int> > > vec)
{
    for(int i=0; i<vec.size(); ++i) {
        for(int j=0; j<vec[i].second.size(); ++j) {
            cout << "(" << vec[i].first << "," << vec[i].second[j] << ")" << endl;
        }
    }
    cout << endl;
}
void printVisit(vector< pair<int,bool> > vec)
{
    for(int i=0; i<vec.size(); ++i) {
        cout << "(" << vec[i].first << "," << vec[i].second << ")" << endl;
    }
    cout << endl;
}
void initVec(void)
{
    for(int i=0; i<isVisited.size(); ++i) {
        isVisited[i].second = false;
    }
}
void dfs(int beg, vector< pair<int, vector<int> > > edge)
{
    stack<int> st;
    st.push(beg);
    checkVisit(beg);

    while(!st.empty()) {
        int curVer = st.top();
        int index = findIndex(curVer, edge);
        st.pop();

        if(index != -1) {
            for(int i=0; i<edge[index].second.size(); ++i) {
                int nextVer = edge[index].second[i];
                if(!isVisit(nextVer)) {
                    resultDFS.push_back(nextVer);
                    checkVisit(nextVer);
                    st.push(curVer);
                    st.push(nextVer);
                    break;
                }
            }
        }
    }
}
void bfs(int beg, vector< pair<int, vector<int> > > edge)
{
    queue<int> que;
    que.push(beg);
    checkVisit(beg);

    while(!que.empty()) {
        int curVer = que.front();
        que.pop();
        resultBFS.push_back(curVer);

        int index = findIndex(curVer, edge);
        if(index != -1) {
            for(int i=0; i<edge[index].second.size(); ++i) {
                int nextVer = edge[index].second[i];
                if(!isVisit(nextVer)) {
                    que.push(nextVer);
                    checkVisit(nextVer);
                }
            }
        }

    }
}
int main(void)
{
    ifstream ifs("test3.inp");
    int N = 0; // 정점의 수(1<=N<=1000)
    int M = 0; // 간선의 수(1<=N<=10000)
    int V = 0; // 탐색을 시작할 정점의 번호

    ifs >> N >> M >> V;

    vector< pair< int,vector<int> > > edge;
    for(int i=0; i<M; ++i) {
        int a = 0, b = 0;
        ifs >> a >> b;
        int index = findIndex(a,edge);
        pair< int, vector<int> > tmpPair;
        if(index == -1) {
            tmpPair.first = a;
            tmpPair.second.push_back(b);
            edge.push_back(tmpPair);
            index = findIndex(b,edge);
            if(index == -1) {
                tmpPair.first = b;
                tmpPair.second.push_back(a);
                edge.push_back(tmpPair);
            } else {
                edge[index].second.push_back(a);
            }
        } else {
            edge[index].second.push_back(b);
            index = findIndex(b,edge);
            if(index == -1) {
                tmpPair.first = b;
                tmpPair.second.push_back(a);
                edge.push_back(tmpPair);
            } else {
                edge[index].second.push_back(a);
            }
        }

        if(!isExist(a)) {
            isVisited.push_back(make_pair(a,false));
        }
        if(!isExist(b)) {
            isVisited.push_back(make_pair(b,false));
        }
    }
    ifs.close();

    printEdge(edge);

    sort(edge.begin(),edge.end(),compare1);
    for(int i=0; i<edge.size(); ++i) {
        sort(edge[i].second.begin(), edge[i].second.end());
    }
    sort(isVisited.begin(), isVisited.end(), compare2);
    cout << "< edge vector >\nN=" << N << ", M=" << M << ", V=" << V << endl;
    printEdge(edge);
    cout << "< check vector >" << endl;
    printVisit(isVisited);

    resultDFS.push_back(V);

    dfs(V, edge);
    cout << "< result of DFS >" << endl;
    for(int i=0; i<resultDFS.size(); ++i) {
        cout << resultDFS[i] << ' ';
    }
    cout << endl;

    initVec();
    bfs(V, edge);
    cout << "< result of BFS >" << endl;
    for(int i=0; i<resultBFS.size(); ++i) {
        cout << resultBFS[i] << ' ';
    }
    cout << endl;


    return 0;
}
