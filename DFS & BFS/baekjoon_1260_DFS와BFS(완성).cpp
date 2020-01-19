// time 8ms
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

class Graph {
    vector<list<int>> vertice;
  public:
    Graph(const int numOfVertex, const int numOfEdge) : vertice(numOfVertex+1) {
        for(int i=0; i<numOfEdge; ++i) {
            int vertex1, vertex2;
            cin>> vertex1 >> vertex2;
            vertice[vertex1].push_back(vertex2);
            vertice[vertex2].push_back(vertex1);
        }
        for(int i=1; i<=numOfVertex; ++i) {
            vertice[i].sort();
        }
    }
    vector<int> DFS(const int beginNumber = 0);
    vector<int> BFS(const int beginNumber = 0);
    friend istream& operator>>(istream& is, Graph& graph);
};

vector<int> Graph::DFS(const int beginVertex) {
    vector<int> visitSequence;
    stack<int> visitedStack;
    bool isVisitedAt[vertice.size()];
    for(int i=0; i<vertice.size(); ++i)
        isVisitedAt[i] = false;
    int current = beginVertex;
    visitSequence.push_back(current);
    isVisitedAt[current] = true;
    bool isDone = false;
    while(!isDone) {
        int previous = current;
        for(list<int>::iterator i=vertice[current].begin(); i!=vertice[current].end(); ++i) {
            int connectedVertex = *i;
            if(!isVisitedAt[connectedVertex]) {
                current = connectedVertex;
                visitedStack.push(previous);
                visitSequence.push_back(current);
                isVisitedAt[current] = true;
                break;
            }
        }
        bool noMoreDepth = previous == current;
        if(noMoreDepth&&!visitedStack.empty()) {
            current = visitedStack.top();
            visitedStack.pop();
        } else if(noMoreDepth) {
            isDone = true;
        }
    }
    return visitSequence;
}

vector<int> Graph::BFS(const int beginVertex) {
    vector<int> visitSequence;
    queue<int> visitedQueue;
    bool isVisitedAt[vertice.size()];
    for(int i=0; i<vertice.size(); ++i)
        isVisitedAt[i] = false;
    int current = beginVertex;
    visitSequence.push_back(current);
    isVisitedAt[current] = true;
    bool isDone = false;
    while(!isDone) {
        for(list<int>::iterator i=vertice[current].begin(); i!=vertice[current].end(); ++i) {
            int connectedVertex = *i;
            if(!isVisitedAt[connectedVertex]) {
                visitSequence.push_back(connectedVertex);
                isVisitedAt[connectedVertex] = true;
                visitedQueue.push(connectedVertex);
            }
        }
        if(visitedQueue.empty()) {
            isDone = true;
        } else {
            current = visitedQueue.front();
            visitedQueue.pop();
        }
    }
    return visitSequence;
}

istream& operator>>(istream& is, Graph& graph) {
    int vertex1, vertex2;
    is>> vertex1 >> vertex2;
    graph.vertice[vertex1].push_back(vertex2);
    graph.vertice[vertex2].push_back(vertex1);
    return is;
}
int main(void) {
    int numOfVertex, numOfEdge, beginVertex;
    cin >> numOfVertex >> numOfEdge >>beginVertex;
    Graph graph(numOfVertex, numOfEdge);
    vector<int> resultOfDFS(graph.DFS(beginVertex));
    vector<int> resultOfBFS(graph.BFS(beginVertex));
    for(int vertex:resultOfDFS)
        cout << vertex << ' ';
    cout << endl;
    for(int vertex:resultOfBFS)
        cout << vertex << ' ';
    return 0;
}
