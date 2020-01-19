#include <iostream>
#include <map>
#include <vector>
#include <list> 
#include <queue>
#include <algorithm>
#include <ctime>
#include <cmath>
#define print_time 	cout << "\nTIME: " << ((double)(end_time - start_time))/(long)CLOCKS_PER_SEC << " sec" << endl;
// 결과값을 정렬해서 하는것보다 max 값이랑 비교하는게 더 빠름  
typedef long long ll;
using namespace std;

map < ll, list<ll> > maplist;
vector< ll > result;	// 컴퓨터 번호, 해킹가능한 수 

bool is_visit( vector<ll> &visit, ll vertex ) {
	for(auto v: visit) {
		if( v == vertex ) {	return true; }
	}
	return false;
}

void BFS( ll startpoint ) {
	queue < ll > queue; 
	vector< ll > visit;
	 
	queue.push( startpoint );
	visit.push_back( startpoint );
	
	while( !queue.empty() ) {
		ll target = queue.front();
		list< ll > sublist = maplist[target];
		list< ll >:: iterator iter;
		
		for(iter = sublist.begin(); iter != sublist.end(); iter++) {
			if( !is_visit( visit, *iter ) ) {
				queue.push( *iter );
				visit.push_back( *iter );
			}
		}
		if( iter == sublist.end() ) {
			queue.pop();
		}
	}
	result[startpoint] = visit.size();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	clock_t	start_time;
	clock_t	end_time;
	time_t	currentTime;
	// computer_N <= 10,000    relation_N <= 100,000
	ll computer_N, relation_N;
	ll start, end;

	cin >> computer_N >> relation_N;
	time(&currentTime);
	start_time = clock();
	for(int i=0; i < relation_N; i++) {
		cin >> end >> start;
		maplist[start].push_back(end);		// 입력받은 edge 추가
	} 
	end_time = clock();
	print_time
	
	result.assign(computer_N+1, 0);
	
	for(ll i = 1; i<=computer_N; i++) {
		BFS(i);
	}
	/*
	map< ll, list<ll> >::iterator it;
	for(it = maplist.begin(); it != maplist.end(); it++) {
		cout << (*it).first << ": " ;
		for( auto s: (*it).second )
			cout << s << ' ';
		cout << "\n";
	}	
	
	cout << "------------------\n";
	cout << result.size() << endl;
	for(int i=1; i<result.size(); i++) { 
		cout << i << " -> " << result[i] << "개\n"; 
	}
	*/
	ll max_value = *max_element(result.begin(), result.end());

	for(ll i=1; i<result.size(); i++) {
		if(result[i] == max_value) {
			cout << i << ' ';
		}
	}
	
	end_time = clock();
	print_time

	return 0;
}

