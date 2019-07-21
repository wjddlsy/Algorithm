#include <iostream>
#include <cmath>

using namespace std;
double x[512], y[512];
double cache[512][512]; //left, right 갈 때 최소 값
int N;
double dist(int a, int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double go(int left, int right){
    if(right==N-1 || left==N-1) {
        if(right==N-1) return dist(left, N-1);
        if(left==N-1) return dist(right, N-1);
    }
    double &ret=cache[left][right];
    if(ret!=-1.0)
        return ret;
    ret=9876543210;
    int n=max(left, right)+1;
    ret=min(ret, go(n, right)+dist(left, n));
    ret=min(ret, go(left, n)+dist(right, n));
    return ret;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        //memset(cache, 0, sizeof(cache));
        for(int i=0; i<512; ++i){
            for(int j=0; j<512; ++j)
                cache[i][j]=-1.0;
        }
        for(int i=0; i<N; ++i){
            cin>>x[i]>>y[i];
        }
        cout<<go(0,0)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}