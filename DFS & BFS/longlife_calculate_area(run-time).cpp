#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> coordinate;
typedef pair<coordinate,coordinate> rectangle;

typedef vector<int> row;

bool is_rectangle(vector<row>& paper, int i, int j)
{
	return paper[i][j] == -1;
}
bool is_top_edge(int i){
	return i == 0;
}
bool is_left_edge(int j){
	return j == 0;
}
bool is_bottom_edge(int i,vector<row>& paper){
	return i == paper.size()-1;
}
bool is_right_edge(int j,vector<row>& paper){
	return j == paper[0].size()-1;
}
void follow_left(vector<row>& paper, int i, int j, vector<int>& area)
{
	paper[i][j] = paper[i][j-1];
	area[paper[i][j-1]]++;
}
void follow_up(vector<row>& paper, int i, int j, vector<int>& area)
{
	paper[i][j] = paper[i-1][j];
	area[paper[i-1][j]]++;
}
void add_new(vector<row>& paper,int i, int j, vector<int>& area)
{
	area.push_back(1);
	paper[i][j] = area.size()-1;
}

void look_left(vector<row>& paper, int i, int j, vector<int>& area){
	if(!is_rectangle(paper,i,j-1))
		follow_left(paper,i,j,area);
	else
		add_new(paper,i,j,area);
}

void look_up(vector<row>& paper, int i, int j, vector<int>& area){
	if(!is_rectangle(paper,i-1,j))
		follow_up(paper,i,j,area);
	else
		add_new(paper,i,j,area);
}

void follow_min(vector<row>& paper,int i,int j,int max_val,int min_val){
	
	if(!is_top_edge(i) && !is_left_edge(j)){
		if(paper[i-1][j]==max_val){		
			paper[i-1][j] = min_val;
			return follow_min(paper,i-1,j,max_val,min_val);
		}
		if(paper[i][j-1]==max_val){
			paper[i][j-1] = min_val;
			return follow_min(paper,i,j-1,max_val,min_val);
			
		}
		if(!is_right_edge(j,paper) && !is_bottom_edge(i,paper)){
			if(paper[i+1][j]==max_val){
				paper[i+1][j] = min_val;
				return follow_min(paper,i+1,j,max_val,min_val);
			}
			if(paper[i][j+1]==max_val){
				paper[i][j+1] = min_val;
				return follow_min(paper,i,j+1,max_val,min_val);
			}
		}
	}
	else if(is_top_edge(i) && !is_left_edge(j)){
		if(paper[i][j-1]==max_val){
			paper[i][j-1] = min_val;
			return follow_min(paper,i,j-1,max_val,min_val);
		}
		if(!is_right_edge(j,paper) && !is_bottom_edge(i,paper)){
			if(paper[i+1][j]==max_val){
				paper[i+1][j] = min_val;
				return follow_min(paper,i+1,j,max_val,min_val);
			}
			
			if(paper[i][j+1]==max_val){
				paper[i][j+1] = min_val;
				return follow_min(paper,i,j+1,max_val,min_val);
			}
		}
	}
	else if(!is_top_edge(i) && is_left_edge(j)){
		if(paper[i-1][j]==max_val){		
			paper[i-1][j] = min_val;
			return follow_min(paper,i-1,j,max_val,min_val);
		}
		if(!is_right_edge(j,paper) && !is_bottom_edge(i,paper)){
			if(paper[i+1][j]==max_val){
				paper[i+1][j] = min_val;
				return follow_min(paper,i+1,j,max_val,min_val);
			}
			
			if(paper[i][j+1]==max_val){
				paper[i][j+1] = min_val;
				return follow_min(paper,i,j+1,max_val,min_val);
			}
		}
	}
}

void look_both(vector<row>& paper,int i,int j,vector<int>& area){
	if(!is_rectangle(paper,i-1,j) && is_rectangle(paper,i,j-1)){
		follow_up(paper,i,j,area);
		
	}
	else if(is_rectangle(paper,i-1,j) && !is_rectangle(paper,i,j-1)){
		follow_left(paper,i,j,area);
		
	}
	else if(!is_rectangle(paper,i-1,j) && !is_rectangle(paper,i,j-1)){
		if(paper[i-1][j] == paper[i][j-1]){
			follow_up(paper,i,j,area);
		}
		else{
			paper[i][j] = min(paper[i-1][j], paper[i][j-1]);
			area[min(paper[i-1][j], paper[i][j-1])] += area[max(paper[i-1][j], paper[i][j-1])];
			area.erase(area.begin()+max(paper[i-1][j], paper[i][j-1]));
			area[min(paper[i-1][j], paper[i][j-1])]++;
			follow_min(paper,i,j,max(paper[i-1][j], paper[i][j-1]),min(paper[i-1][j], paper[i][j-1]));
		}
	}
	else{
		add_new(paper,i,j,area);
	}
}

void find_area(vector<row>& paper, vector<int>& area)
{
	for(int i=0;i<paper.size();++i){
		for(int j=0;j<paper[i].size();++j){
			if(!is_rectangle(paper,i,j)){
				if(is_top_edge(i) && is_left_edge(j)){
					paper[i][j] = 0;
					area.push_back(1);
				} 
				else if(is_top_edge(i)){
					look_left(paper,i,j,area);
				}
				else if(is_left_edge(j)){
					look_up(paper,i,j,area);
				}
				else {
					look_both(paper,i,j,area);
				}
			}
		}
	}
}


int main(void)
{
	int M, N, K;
	cin >> M >> N >> K;

	vector<rectangle> list_rect(K);
	for(int i=0;i<K;++i){
		cin >> list_rect[i].first.first >> list_rect[i].first.second; 	// 좌하 꼭짓점 
		cin >> list_rect[i].second.first >> list_rect[i].second.second; // 우상 꼭짓점 
	}
	
	vector<rectangle> new_list_rect(K);  // 내가 보는 관점으로 좌표값 변경  
	for(int i=0;i<K;++i){
		new_list_rect[i].first.first = (M-1)-list_rect[i].first.second; // 좌하 x
		new_list_rect[i].first.second = list_rect[i].first.first; 		// 좌하 y
		new_list_rect[i].second.first = M-list_rect[i].second.second; 	// 우상 x
		new_list_rect[i].second.second = list_rect[i].second.first-1; 	// 우상 x 
	}

	
	vector<row> paper(M,row(N,111));
	vector<int> area;

	// 주어진 직사각형 표시 
	for(int i=0;i<new_list_rect.size();++i)
		for(int j=new_list_rect[i].second.first;j<=new_list_rect[i].first.first;++j)
			for(int k=new_list_rect[i].first.second;k<=new_list_rect[i].second.second;++k)
				paper[j][k] = -1;
	
	find_area(paper, area);
	sort(area.begin(), area.end());
	
	cout << area.size() << endl;
	for(int i=0;i<area.size();++i)
		cout << area[i] << ' ';
	cout << endl;
		
	return 0;
}
 

