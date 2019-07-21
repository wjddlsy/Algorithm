#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi = 2.0 * acos(0);
const int INF=987654321;

int n;
double R=8.0, y[100], x[100], r[100];
vector<pair<double, double>> ranges;

void convertToRange() {
    ranges.clear();
    ranges.resize(n);
    for (int i = 0; i < n; ++i) {
        double loc = fmod(2 * pi + atan2(y[i], x[i]), 2 * pi);
        double range = 2.0 * asin(r[i] / (2.0 * R));
        ranges[i] = {loc - range, loc + range};
    }
    sort(ranges.begin(), ranges.end());
}

int solveLinear(double begin, double end) {
    int used = 0, idx = 0 ;
    while(begin<end) {
        double maxCover = -1;
        while(idx<n && ranges[idx].first<=begin) {
            maxCover = max(maxCover, ranges[idx].second);
            ++idx;
        }
        if(maxCover<=begin) return INF;
        begin=maxCover;
        ++used;
    }
    return used;
}

int solveCircular() {
    int ret=INF;
    for(int i=0; i<n; ++i){
        if(ranges[i].first<=0 || ranges[i].second>=2*pi) {
            double begin = fmod(ranges[i].second, 2*pi);
            double end = fmod(ranges[i].first+2*pi, 2*pi);
            ret=min(ret, 1+solveLinear(begin, end));
        }
    }
    return ret;
}
int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> y[i] >> x[i] >> r[i];
        }
        convertToRange();
        int ret=solveCircular();
        if(ret==INF)
            cout<<"IMPOSSIBLE";
        else
            cout<<ret;
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}