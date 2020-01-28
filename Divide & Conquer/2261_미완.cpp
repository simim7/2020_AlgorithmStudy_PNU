#include <bits/stdc++.h>

#define MIN_TERM 20000

using namespace std;

class coordinate {
	int x, y;
public:
	coordinate(int xx, int yy) {
		x = xx;
		y = yy;
	}
public:
	void setX(int xx) {
		x = xx;
	}
	void setY(int yy) {
		y = yy;
	}
	int getX(void) const {
		return x;
	}
	int getY(void) const {
		return y;
	}
	void print(void) const {
		cout << "(" << x << "," << y << ")";
	}
};

long long int calcDistance(const coordinate& c1, const coordinate& c2)
{
	return (c1.getX()-c2.getX())*(c1.getX()-c2.getX())+(c1.getY()-c2.getY())*(c1.getY()-c2.getY());
}
long long int calcAbs(const coordinate& c1, const coordinate& c2)
{
	return abs(c1.getX()-c2.getX())+abs(c1.getY()-c2.getY());
}
bool compare(const coordinate& c1, const coordinate& c2)
{
	if(c1.getX()==c2.getX()) {
		return c1.getY()<c2.getY();
	} else {
		return c1.getX()<c2.getX();
	}
}
bool isExist(vector<coordinate> vec, int xx, int yy)
{
	for(int i=0; i<vec.size(); ++i) {
		if(vec[i].getX()==xx && vec[i].getY()==yy) return true;
	}
	return false;
}
int main(void)
{
	ifstream ifs("2261_2.inp");
	int n=0; // 2<=n<=100000
	int xx=0, yy=0; // -10000<=xx,yy<=10000
	long long int dist = 0, minDist=800000000;

	ifs >> n;
	
	vector<coordinate> coordVec;
	
	for(int i=0; i<n; ++i) {
		ifs >> xx >> yy;
		if(!isExist(coordVec,xx,yy)) {
			coordinate tmpXY(xx,yy);
			coordVec.push_back(tmpXY);
		}
	}
	ifs.close();
	sort(coordVec.begin(), coordVec.end(), compare);
	
	int vecSize = coordVec.size();
	
	//coordVector Ãâ·Â 
	for(int i=0; i<vecSize; ++i) {
		coordVec[i].print();
		cout << endl;
	}
	cout << "---------------------" << endl;
	
	long long int termX = 0, termY = 0, minTermX = MIN_TERM, minTermY = MIN_TERM;
	
	for(int i=0; i<vecSize-1; ++i) {
		for(int j=i+1; j<vecSize; ++j) {
			coordVec[i].print();
			cout << ", ";
			coordVec[j].print();
			cout << " => ";
			dist = calcDistance(coordVec[i],coordVec[j]);
			cout << dist;
			if(dist<minDist) {
				minDist = calcDistance(coordVec[i], coordVec[j]);
				cout << "         MIN!!!"; 
			}
			cout << endl;
			
			termX = abs(coordVec[i].getX()-coordVec[j].getX());
			termX = abs(coordVec[i].getY()-coordVec[j].getY());
			if(minTermX!=MIN_TERM && minTermY!=MIN_TERM) {
				if(termX<minTermX && termY<minTermY) {
					minTermX = MIN_TERM;
					minTermY = MIN_TERM;
					break;
				}
				else {
					if(termX<minTermX) {
						minTermX = termX;
					}
					if(termY<minTermY) {
						minTermY = termY;
					}
				}
			}
		}
	}
	
	cout << minDist;
	
    return 0;
}
