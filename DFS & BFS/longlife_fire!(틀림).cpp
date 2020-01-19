#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

#define WALL -1
#define PATH -2
#define MAX_PATH 1000

typedef int fire;
typedef int Jihoon;
typedef pair<fire,Jihoon> position; 
typedef vector<position> room_row;
typedef pair<int,int> F_pos;
typedef pair<int,int> J_pos;


int miniute=1000;
F_pos F_start;
J_pos J_start;
int F_minute, J_minute;
deque<F_pos> fire_path;
deque<J_pos> jihoon_path;

bool is_impossible=true;
int escape_minute;

bool is_top_edge(int i)
{
	return i==0;
}
bool is_left_edge(int j)
{
	return j==0;
}
bool is_right_edge(int j, vector<room_row>& room)
{
	return j==room[0].size()-1;
}
bool is_bottom_edge(int i, vector<room_row>& room)
{
	return i==room.size()-1;
}

void find_Fire_path(vector<room_row>& room)
{
	fire_path.push_back(F_start);
	F_pos tmp;
	while(!fire_path.empty()){
		int level = fire_path.size();
		F_minute++;
		
		
		for(int i=0;i<level;++i){
			tmp = fire_path[0];
			fire_path.erase(fire_path.begin());
			
			if(!is_top_edge(tmp.first)){
				if(room[tmp.first-1][tmp.second].first==PATH){
					room[tmp.first-1][tmp.second].first = F_minute;
					fire_path.push_back(F_pos(tmp.first-1,tmp.second));
					
				}
			}
			if(!is_left_edge(tmp.second)){
				if(room[tmp.first][tmp.second-1].first==PATH){
					room[tmp.first][tmp.second-1].first = F_minute;
					fire_path.push_back(F_pos(tmp.first,tmp.second-1));
					
				}
			}
			if(!is_right_edge(tmp.second,room)){
				if(room[tmp.first][tmp.second+1].first==PATH){
					room[tmp.first][tmp.second+1].first = F_minute;
					fire_path.push_back(F_pos(tmp.first,tmp.second+1));
					
				}
			}
			if(!is_bottom_edge(tmp.first,room)){
				if(room[tmp.first+1][tmp.second].first==PATH){
					room[tmp.first+1][tmp.second].first = F_minute;
					fire_path.push_back(F_pos(tmp.first+1,tmp.second));
				}
			}
			
		}
	}
}

void find_Jihoon_path(vector<room_row>& room){
	jihoon_path.push_back(J_start);
	J_pos tmp;
	while(!jihoon_path.empty()){
		int level = jihoon_path.size();
		J_minute++;
		
		
		for(int i=0;i<level;++i){
			tmp = jihoon_path[0];
			jihoon_path.erase(jihoon_path.begin());
			
			if(!is_top_edge(tmp.first)){
				if(room[tmp.first-1][tmp.second].second==PATH){
					room[tmp.first-1][tmp.second].second = J_minute;
					jihoon_path.push_back(J_pos(tmp.first-1,tmp.second));
				}
			}
			if(!is_left_edge(tmp.second)){
				if(room[tmp.first][tmp.second-1].second==PATH){
					room[tmp.first][tmp.second-1].second = J_minute;
					jihoon_path.push_back(J_pos(tmp.first,tmp.second-1));
				}
			}
			if(!is_right_edge(tmp.second,room)){
				if(room[tmp.first][tmp.second+1].second==PATH){
					room[tmp.first][tmp.second+1].second = J_minute;
					jihoon_path.push_back(J_pos(tmp.first,tmp.second+1));
				}
			}
			if(!is_bottom_edge(tmp.first,room)){
				if(room[tmp.first+1][tmp.second].second==PATH){
					room[tmp.first+1][tmp.second].second = J_minute;
					jihoon_path.push_back(J_pos(tmp.first+1,tmp.second));
					
				}
			}
			
		}
	}
}

void find_answer(vector<room_row>& room)
{
	for(int i=0;i<room[0].size();++i){
		if(room[0][i].first != WALL){
			if(room[0][i].first >= room[0][i].second){
				if(escape_minute > room[0][i].second){
					is_impossible=false;
					escape_minute=room[0][i].second;
				}
			}
		}
		if(room[room.size()-1][i].first != WALL){
			if(room[room.size()-1][i].first >= room[room.size()-1][i].second){
				if(escape_minute > room[room.size()-1][i].second){
					is_impossible=false; 
					escape_minute=room[room.size()-1][i].second;
				}
			}
		}
	}
	for(int i=1;i<room.size();++i){
		if(room[i][0].first != WALL) {
			if(room[i][0].first >= room[i][0].second){
				if(escape_minute > room[i][0].second){
					is_impossible=false;
					escape_minute=room[i][0].second;
				}
			}
		}
		if(room[i][room[0].size()-1].first != WALL) {
			if(room[i][room[0].size()-1].first >= room[i][room[0].size()-1].second){
				if(escape_minute > room[i][room[0].size()-1].second){
					is_impossible=false;
					escape_minute=room[i][room[0].size()-1].second;
				}
			}
		}
		
	}
	
}

int main(void)
{
	int R, C;
	cin >> R >> C;
	
	vector<room_row> room(R,room_row(C));
	char tmp;
	for(int i=0;i<room.size();++i){
		for(int j=0;j<room[i].size();++j){
			cin>>tmp;
			if(tmp=='#'){
				room[i][j].first = WALL;
				room[i][j].second = WALL;
			}
			else if(tmp=='F'){
				room[i][j].first = 0;
				room[i][j].second = PATH;
				F_start.first = i;
				F_start.second = j;
			}
			else if(tmp=='J'){
				room[i][j].first = PATH;
				room[i][j].second = 0;
				J_start.first = i;
				J_start.second = j;
			}
			else{
				room[i][j].first = PATH;
				room[i][j].second = PATH;
			}
		}
	}

	
	find_Fire_path(room);
	find_Jihoon_path(room);
	

	find_answer(room);
	if(is_impossible==false)
		cout << escape_minute+1 << endl;
	else
		cout << "IMPOSSIBLE" << endl; 
	
	return 0;
}

