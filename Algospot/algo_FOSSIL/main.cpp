#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
    Point(double x, double y):x(x), y(y){};

};

vector<Point> hull1, hull2;
vector<pair<Point, Point>> upper, lower;

void decompose(vector<Point>& hull) {
    int n=hull.size();
    for(int i=0; i<n; ++i) {
        if(hull[i].x>hull[(i+1)%n].x) {
            upper.emplace_back(hull[i], hull[(i+1)%n]);
        } else if(hull[i].x<hull[(i+1)%n].x) {
            lower.emplace_back(hull[i], hull[(i+1)%n]);
        }
    }
}

bool between(Point& a, Point& b, double x) {
    double minX=min(a.x, b.x), maxX=max(a.x, b.x);
    return x>=minX && x<=maxX;
}

double at(Point& a, Point& b, double x) {
    return ((b.y-a.y)/(b.x-a.x))*(x-a.x)+a.y;
}

double vertical(double x) {
    double hi=1e20, lo=-1e20;
    for(int i=0; i<upper.size(); ++i) {
        if(between(upper[i].first, upper[i].second, x)) {
            hi=min(hi, at(upper[i].first, upper[i].second, x));
        }
    }
    for(int i=0; i<lower.size(); ++i) {
        if(between(lower[i].first, lower[i].second, x)) {
            lo=max(lo, at(lower[i].first, lower[i].second, x));
        }
    }
    return hi-lo;
}

double minX(vector<Point>& hull) {
    return (*min_element(hull.begin(), hull.end(), [](const Point& a, Point& b) {
        return a.x<b.x;
    })).x;
}
double maxX(vector<Point>& hull) {
    return (*max_element(hull.begin(), hull.end(), [](const Point& a, Point& b) {
        return a.x<b.x;
    })).x;
}
double solve() {
    double lo=max(minX(hull1), minX(hull2));
    double hi=min(maxX(hull1), maxX(hull2));
    if(hi<lo)
        return 0;
    for(int i=0; i<100; ++i) {
        double one=(lo*2+hi)/3.0;
        double two=(lo+hi*2)/3.0;
        if(vertical(one)>vertical(two)) {
            hi=two;
        } else {
            lo=one;
        }
    }
    return max(0.0, vertical((hi+lo)/2));
}
int main() {
    int c;
    cin>>c;
    while(c--) {
        hull1.clear(); hull2.clear();
        upper.clear(); lower.clear();
        int n, m;
        cin>>n>>m;
        for(int i=0; i<n; ++i) {
            double x, y;
            cin>>x>>y;
            hull1.emplace_back(x, y);
        }
        for(int i=0; i<m; ++i) {
            double x, y;
            cin>>x>>y;
            hull2.emplace_back(x, y);
        }
        decompose(hull1);
        decompose(hull2);
        printf("%.11f\n", solve());
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}