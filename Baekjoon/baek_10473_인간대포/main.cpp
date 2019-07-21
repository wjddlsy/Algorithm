#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>
#include <tuple>
using namespace std;

vector<pair<double, double>> cannon;
const double INF=numeric_limits<double>::max();
double SX, SY, EX, EY;
int n;
double adj[102][102];
double getDist(double sx, double sy, double ex, double ey){
    return sqrt((sx-ex)*(sx-ex)+(sy-ey)*(sy-ey));
}

double dijkstra(){
    priority_queue<pair<double, int>> pq;
    vector<double> dist(n+2, INF);
    pq.push({0, 0});
    dist[0]=0;
    while(!pq.empty()){
        double cost;
        int here;
        tie(cost, here)=pq.top();
        cost=-cost;
        pq.pop();
        if(cost<dist[here])
            continue;
        for(int there=0; there<n+2; ++there){
            if(adj[here][there]<numeric_limits<double>::epsilon())
                continue;
            double nextDist=cost+adj[here][there];
            if(nextDist<dist[there]){
                dist[there]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist[n+1];
}
int main() {
    //int n;
    cin>>SX>>SY>>EX>>EY>>n;
    cannon.push_back({0, 0});
    for(int i=0; i<n; ++i){
        double x, y;
        cin>>x>>y;
        cannon.push_back({x, y});
    }

    // 대포 사이 거리 구함
    // 1. 시작 위치에서 대포들
    for(int i=1; i<=n; ++i){
        double dist=getDist(SX, SY, cannon[i].first, cannon[i].second);
        double time=dist/5.0;
        adj[0][i]=time;
    }
    adj[0][n+1]=adj[n+1][0]=getDist(SX, SY, EX, EY)/5.0;

    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            double dist=getDist(cannon[i].first, cannon[i].second,
                    cannon[j].first, cannon[j].second);
            double walkTime=dist/5.0;
            double cannonTime=abs(dist-50)/5.0 + 2.0;
            adj[i][j]=adj[j][i]=min(walkTime, cannonTime);
        }
    }

    // 마지막!
    for(int i=1; i<=n; ++i){
        double dist=getDist(EX, EY, cannon[i].first, cannon[i].second);
        double walkTime=dist/5.0;
        double cannonTime=abs(dist-50)/5.0 + 2.0;
        adj[i][n+1]=min(walkTime, cannonTime);
    }

    cout<<(double)dijkstra();
    //std::cout << "Hello, World!" <<std::endl;
    return 0;
}