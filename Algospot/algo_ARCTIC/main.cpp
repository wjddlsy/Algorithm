#include <iostream>
#include <vector>
#include <queue>

using namespace std;

double getDist(double x1, double x2, double y1 ,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool decision(const vector<pair<double, double>>& coord, double dist) {
    int n=coord.size(), visit=1;
    vector<bool> discovered(n, false);
    queue<int> q;
    discovered[0]=true;
    q.push(0);
    while(!q.empty()) {
        int here=q.front();
        q.pop();
        for(int there=0; there<n; ++there) {

            if(discovered[there])
                continue;
            double d=getDist(coord[here].first, coord[there].first, coord[here].second, coord[there].second);
            if(dist*dist<d)
                continue;
            q.push(there);
            discovered[there]=true;
            visit++;
        }
    }
    return visit==n;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        int N;
        cin>>N;
        vector<pair<double, double>> coord;
        for(int i=0; i<N; ++i) {
            double x, y;
            cin>>x>>y;
            coord.emplace_back(x, y);
        }
        // 왜 100번만하지
        double lo=0, hi=1500.00;
        for(int i=0; i<100; ++i) {
            double mid=(lo+hi)/2;
            if(decision(coord, mid))
                hi=mid;
            else
                lo=mid;
        }

        printf("%.2f\n", hi);
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}