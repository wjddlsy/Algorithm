#include <iostream>
#include <vector>

#include <string.h>
using namespace std;

int N, W;
int wx[1001], wy[1001];
int c1_x[1001], c1_y[1001], c2_x[1001], c2_y[1001];
int cache[1001][1001];

int go(int c1, int c2){
    if(c1==W || c2==W){
        return 0;
    }
    int& ret=cache[c1][c2];
    if(ret!=-1)
        return ret;
    // c1이 가던지 c2가 가던지
    int nw=max(c1,c2)+1;

    ret=min(abs(c1_x[nw]-c1_x[c1])+abs(c1_y[nw]-c1_y[c1])+go(nw, c2), abs(c2_x[nw]-c2_x[c2])+abs(c2_y[nw]-c2_y[c2])+go(c1, nw));
    return ret;
}

vector<int> reconstruct(int c1, int c2, vector<int>& v){
    if(c1==W || c2==W)
        return v;
    int nw=max(c1,c2)+1;
    int cand1=abs(c1_x[nw]-c1_x[c1])+abs(c1_y[nw]-c1_y[c1])+go(nw, c2);
    int cand2=abs(c2_x[nw]-c2_x[c2])+abs(c2_y[nw]-c2_y[c2])+go(c1, nw);
    if(cand1>cand2) {
        v.push_back(2);
        return reconstruct(c1, nw, v);
    } else{
        v.push_back(1);
        return reconstruct(nw, c2, v);
    }
}
int main() {
    /*INPUT*/
    cin>>N>>W;
    for(int i=1; i<=W; ++i){
        cin>>wx[i]>>wy[i];
        c1_x[i]=c2_x[i]=wx[i];
        c1_y[i]=c2_y[i]=wy[i];
    }
    memset(cache, -1, sizeof(cache));
    c1_x[0]=c1_y[0]=1;
    c2_x[0]=c2_y[0]=N;

    cout<<go(0,0)<<endl;
    vector<int> ret;
    reconstruct(0,0,ret);
    for(auto r:ret)
        cout<<r<<endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}