#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <algorithm>

using namespace std;
//부루투로해부자
vector< pair<tuple<int,int,int>, string> > chunk_idx_vec;
//map<string, int> chunk_num_map;
string s;
string fb = "(";
string eb = ")";

int get_answer(){
	for(size_t i=0; i<chunk_idx_vec.size(); i++){
		tuple<int,int,int> info = chunk_idx_vec[i].first;
		int len = get<0>(info);
		int beg = get<0>(info);
		int end = get<0>(info);
		string chunk = chunk_idx_vec[i].second;
	}
}

void get_chunks_with_size(int chunk_size){
	size_t max_idx = s.size()- 2*chunk_size;
	int dup_count = 1; int start_idx;
	string dup_chunk = "";
	for(size_t idx = 0; idx <= max_idx;  ){
		string read_chunk = s.substr(idx, chunk_size);
		
		if(read_chunk == s.substr(idx+chunk_size, chunk_size)){
			if(dup_count == 1) start_idx = idx;
//			chunk_idx_map.insert(make_pair( pair<int,int>(idx, idx+chunk_size), read_chunk));
//			cout << "read_check : "<<read_chunk<<endl;
		
			if(dup_chunk=="")
				dup_chunk = read_chunk;
		
			dup_count++;
			
			if(idx + chunk_size > max_idx){ // 더 이상 합칠 게 없을 때 
//				cout << idx+chunk_size << " " <<max_idx<<endl;
//				cout << dup_chunk.size() <<  " " << dup_count<<endl;
				if( (dup_chunk.size()==1 && dup_count  > 4) || dup_chunk.size() > 1) {
						char buf[3];   sprintf(buf, "%d",dup_count);
						string insert_chunk = (buf+fb+dup_chunk+eb);
//						dup_chunk += (fb + buf + eb);
//						cout << insert_chunk <<endl;
 						chunk_idx_vec.push_back(make_pair(make_tuple( idx+2*chunk_size-start_idx , start_idx, idx+2*chunk_size), insert_chunk));
//						cout << "INSERTED "<<endl;
						dup_count = 1;
					}
			}
			
			idx += chunk_size;
		}
		else{
			if(dup_chunk!=""){
				if( (dup_chunk.size()==1 && dup_count  > 4) || dup_chunk.size() > 1) {
						char buf[3];   sprintf(buf, "%d",dup_count);
						string insert_chunk = (buf+fb+dup_chunk+eb);
//						dup_chunk += (fb + buf + eb);
//						cout << insert_chunk <<endl;
 						chunk_idx_vec.push_back(make_pair(make_tuple(idx+2*chunk_size-start_idx, start_idx, idx+2*chunk_size), insert_chunk));
				}
//				chunk_num_map.insert(make_pair(dup_chunk, dup_count));
				dup_chunk="";
				dup_count = 1;
			}	
			
			idx++;	
		}
	}
} 
 
bool sort_func(pair<tuple<int,int,int>, string> a, pair<tuple<int,int,int>, string> b){
	tuple<int,int,int> ainfo = a.first; 
	tuple<int,int,int> binfo = b.first;	
	if(get<0>(ainfo) > get<0>(binfo)) return true;
	else if(get<0>(ainfo) == get<0>(binfo)){
		if(get<1>(ainfo) < get<1>(binfo)) return true;
		else if(get<1>(ainfo) == get<1>(binfo)) return  get<2>(ainfo) > get<2>(binfo);
	}
	else return false;
} 
 
int main(void){
	cin >> s;
	
	int max_chunk_len = s.size()/2;
    for(int i = max_chunk_len; i>=1; i--){
    	get_chunks_with_size(i);
	}	
	
	sort(chunk_idx_vec.begin(), chunk_idx_vec.end(), sort_func);
	for(size_t i = 0; i< chunk_idx_vec.size();i++)
    {
         cout << "LEN : "<< get<0>(chunk_idx_vec[i].first)
			  <<" BEG : "<< get<1>(chunk_idx_vec[i].first) 
		      <<" END : " <<get<2>(chunk_idx_vec[i].first)
			  <<" CHUNK : "<<chunk_idx_vec[i].second<<endl;
    }
    
//	cout << get_shortest_len();
//	cout << "s : " << s;
	
	return 0;
}
