//time 0ms
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
    Point
    first : x
    second : y
*/
typedef pair<int,int> Point;
/*
    Rectangle
    first : left-bottom
    second : right-top
*/
typedef pair<Point,Point> Rectangle;

class GraphPaper {
    const int height;
    const int width;
    bool** paper;
    typedef pair<int,int> Point;
    typedef pair<Point,Point> Rectangle;

    inline static bool** initializePaper(int height, int width, const vector<Rectangle>& rectangles) {
        bool** paper = new bool*[height];
        for(int y=0; y<height; ++y)
            paper[y] = new bool[width];
        for(int y=0; y<height; ++y)
            for(int x=0; x<width; ++x)
                paper[y][x] = true;
        for(int i=0; i<rectangles.size(); ++i)
            draw(paper, rectangles[i]);
        return paper;
    }
    inline static void draw(bool** paper, const Rectangle& rectangle) {
        int xStart = rectangle.first.first;
        int xEnd = rectangle.second.first;
        int yStart = rectangle.first.second;
        int yEnd = rectangle.second.second;
        for(int y= yStart; y<yEnd; ++y)
            for(int x= xStart; x<xEnd; ++x)
                paper[y][x]= false;
    }
  public:
    GraphPaper(int h, int w, const vector<Rectangle>& rectangles)
        :height(h), width(w), paper(initializePaper(h,w,rectangles)) {
    }
    inline int getHeight(void) const {
        return height;
    }
    inline int getWidth(void) const {
        return width;
    }
    inline bool at(int x, int y) const {
        return paper[y][x];
    }
};

class GraphPaperChecker {
    int height;
    int width;
    bool** checker;
    constexpr static int X4Directions[4] = {0,1,0,-1};
    constexpr static int Y4Directions[4]= {1,0,-1,0};

    inline int getDirectionIndex(const int currentX, const int currentY) {
        for(int i=0; i<4; ++i) {
            const int nextY = currentY + Y4Directions[i];
            const int nextX = currentX + X4Directions[i];
            if(checker[nextY][nextX])
                return i;
        }
        return -1;
    }

    int calculateArea(const int x, const int y) {
        cout <<"in calculateArea()" << endl;
        cout << "checking route"  <<endl;
        bool isStartChecked = !checker[y][x];
        if(isStartChecked)
            return 0;
        int currentX = x;
        int currentY = y;
        int area = 0;
        stack<Point> PointsInDomain;
        bool isDone = false;
        while(!isDone) {
            cout << "(" << currentX<< "," << currentY<<")"<<endl;
            bool isInDomain = checker[currentY][currentX];
            if(isInDomain) {
                checker[currentY][currentX] = false;
                ++area;
            }
            int directionIndex = getDirectionIndex(currentX,currentY);
            bool canExtendDomain = directionIndex!= -1;
            if(canExtendDomain) {
                PointsInDomain.push(Point(currentX,currentY));
                currentX += X4Directions[directionIndex];
                currentY += Y4Directions[directionIndex];
            } else if(!(PointsInDomain.empty())) {
                currentX = PointsInDomain.top().first;
                currentY = PointsInDomain.top().second;
                PointsInDomain.pop();
            } else {
                isDone = true;
            }
        }
        return area;
    }
  public:
    vector<int> calculateAreas(const GraphPaper& graphPaper) {
        vector<int> areas;
        int height = graphPaper.getHeight();
        int width = graphPaper.getWidth();
        checker = new bool*[height+2];

        for(int y = 0; y<height+2; ++y) {
            checker[y] = new bool[width+2];
            for(int x = 0; x<width+2; ++x) {
                bool isMargin = (x==0||y==0||x==width+1||y==height+1);
                if(isMargin) {
                    checker[y][x] = false;
                } else {
                    checker[y][x] = graphPaper.at(x-1,y-1);
                }
            }
        }
        cout << "in calculateAreas checker made" << endl;
        for(int y =1; y<height+2; ++y)
            for(int x= 1; x<width+2; ++x) {
                const int area = calculateArea(x,y);
                if(area > 0)
                    areas.push_back(area);
                cout << "(" << x << "," << y <<") is calculated" << endl;
            }
        return areas;
    }

};
constexpr int GraphPaperChecker::X4Directions[];
constexpr int GraphPaperChecker::Y4Directions[];

int main(void) {
    int height, width, rectangleCount;
    int x,y;
    cin >> height;
    cin >> width;
    cin >> rectangleCount;
    vector<Rectangle> rectangles(rectangleCount);
    for(int i=0; i<rectangleCount; ++i) {
        cin >> x;
        cin >> y;
        rectangles.at(i).first = Point(x,y);
        cin >> x;
        cin >> y;
        rectangles.at(i).second = Point(x,y);
    }
    GraphPaper graphPaper(height,width,rectangles);
    cout << "graphPaper made" << endl;
    GraphPaperChecker graphPaperChecker;
    cout << "checker made" << endl;
    vector<int> areas(graphPaperChecker.calculateAreas(graphPaper));
    cout << "area calculated" <<endl;
    cout << areas.size() << endl;
    sort(areas.begin(),areas.end());
    for(int i=0; i<areas.size(); ++i) {
        cout << areas.at(i) << ' ';
    }
    return 0;
}
