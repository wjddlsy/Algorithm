#include <iostream>

using namespace std;
const double INF=1e9;
int px[50], py[50], vx[50], vy[50];
int N;

double canGet(double t) {
    double maxX=-INF, maxY=-INF, minX=INF, minY=INF;
    for(int i=0; i<N; ++i) {
        double x=px[i]+vx[i]*t, y=py[i]+vy[i]*t;
        maxX=max(maxX, x);
        maxY=max(maxY, y);
        minX=min(minX, x);
        minY=min(minY, y);
    }
    return max(maxX-minX, maxY-minY);
}
int main() {
    cin>>N;
    for(int i=0; i<N; ++i) {
        cin>>px[i]>>py[i]>>vx[i]>>vy[i];
    }
    double lo=0, hi=INF;
    for(int i=0; i<1000; ++i) {
        double fi=(2*lo+hi)/3, la=(lo+2*hi)/3;
        if(canGet(fi)<canGet(la)) {
            hi=la;
        } else {
            lo=fi;
        }
    }
    printf("%.10f", canGet(lo));
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}