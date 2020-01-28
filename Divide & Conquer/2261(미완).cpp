//2261 두 점 간의 거리 
//조알고때 다룬 문제 

#include<bits/stdc++.h> 

using namespace std;

int n;	
int Min = INT_MAX;
vector< pair<int, vector<int> > > PV;

bool func(pair<int,int> a, pair<int,int> b){
	if(a.first<b.first) return true;
	else if(a.first==b.first) return a.second < b.second;
	return false;
}

void pfind(int p, int N){
	
	if(N==1){
		vector<int>& ys = PV[p].second;
		for(size_t i=0; i<ys.size()-1; i++){
			int d = pow(ys[i+1] - ys[i] , 2);
			if( Min > d ){
//				cout << "d : " << d <<" ,x : "<<  PV[p].first << "/ y:" << ys[i+1] << "-" << ys[i] <<endl; 
				 Min = d;
				 if(Min==0) {
//				 	cout << PV[p].first << " , " << ys[i] << "vs" << ys[i+1]<<endl;
				 	cout << Min; exit(0);
				 }
			}		
		}
		return;
	}	
	
	else if(N>=2){
		pfind(p , (N/2) + (N%2) );
		pfind(p+(N/2) + (N%2) ,(N/2)  );

	  if(Min==0) {
		 	cout << Min; exit(0);
	  }
		
	}
	
	int ridx = 0; int lidx = 0;
	int rp = p+(N/2) + (N%2);
	int lp = p+(N/2) + (N%2) - 1;
	vector<int>& rv = PV[rp].second;
	vector<int>& lv = PV[lp].second;
		
	while(1){
		int dist = 	pow ( PV[rp].first - PV[lp].first , 2) +
					pow ( rv[ridx] - lv[lidx] , 2);
								
		if(dist < Min){
			Min = dist;
//			cout << "DIST : " << dist << "| " << PV[rp].first << " - " << PV[lp].first <<" , " << rv[ridx] << " - " << lv[lidx] <<endl; 
			 if(Min==0) {
				 	cout << Min; exit(0);
			}
		}
		
		if(ridx == rv.size()-1 && lidx == lv.size()-1) break;
		else if(ridx == rv.size()-1 && lidx < lv.size()-1 ) lidx++;
		else if(ridx < rv.size()-1 && lidx == lv.size()-1 ) ridx++;
		else {	(ridx > lidx ) ? (lidx++) : (ridx++) ;}
		
	}
	
	return;
}

int main(void){
	ifstream ifs("!.txt");
//	ifs >> n;
	cin >> n;
	vector<pair<int,int> > TMP =  vector< pair<int,int> >(n);
	int x,y;
	for(size_t i=0; i<n; i++){
		cin >> x >> y;
//		ifs >> x >> y;
		TMP[i]= make_pair(x,y);
	}
	sort(TMP.begin(), TMP.end(), func);
	int p = TMP[0].first;
	vector<int> pv;
	for(int i=0; i<n; i++){
		if(TMP[i].first!=p ){
			PV.push_back(make_pair(p, pv));
			pv.clear();
			pv.push_back(TMP[i].second);
			p = TMP[i].first;
		}	
		else
			pv.push_back(TMP[i].second);
		if(i==n-1){
			PV.push_back(make_pair(p, pv));
		}
	}
	
//	cout << PV.size();
	pfind(0, PV.size());
	cout << Min;
	return 0;
}
