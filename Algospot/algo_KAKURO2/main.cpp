#include <iostream>
#include <vector>
#include <cstring>
#
using namespace std;

int N;
int color[20][20], value[20][20], hint[20][20][2], candidates[10][46][1024];
int sum[20*20], length[20*20], known[20*20];

int getSize(int mask) {
    return __builtin_popcount(mask);
}
int getSum(int mask) {
    int ret=0;
    for(int i=1; i<=9; ++i){
        if(mask & (1<<i)) {
            ret+=i;
        }
    }
    return ret;
}

void generateCandidates() {
    memset(candidates, 0, sizeof(candidates));
    for(int set=0; set<1024; set+=2){
        int l=getSize(set), s=getSum(set);
        int subset=set;
        while(true){
            candidates[l][s][subset]|=(set&~subset);
            if(subset==0) break;
            subset = (subset-1) & set;
        }
    }
}

void put(int y, int x, int val) {
    for(int h=0; h<2; ++h){
        known[hint[y][x][h]]+=(1<<val);
    }
    value[y][x]=val;
}

void remove(int y, int x, int val) {
    for(int h=0; h<2; ++h){
        known[hint[y][x][h]]-=(1<<val);
    }
    value[y][x]=0;
}

int getCandHint(int hint) {
    return candidates[length[hint]][sum[hint]][known[hint]];
}

int getCandCoord(int y, int x){
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

void printSolution() {
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout<<value[i][j]<<" ";
        }
        cout<<'\n';
    }
}

bool search() {
    // 아직 숫자를 쓰지 않은 흰 칸 중 후보의 수가 최소인 칸을 찾는다.
    int y=-1, x=-1, minCands=1023;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(color[i][j]==1 && value[i][j]==0) {
                int cands=getCandCoord(i, j);
                if(getSize(minCands)>getSize(cands)){
                    minCands=cands;
                    y=i; x=j;
                }
            }
        }
    }
    // 이 칸에 들어갈 숫자가 없으면 실패
    if(minCands==0) return false;
    if(y==-1) {
        printSolution();
        return true;
    }
    for(int val=1; val<=9; ++val){
        if(minCands & (1<<val)) {
            put(y, x, val);
            if(search()) return true;
            remove(y, x, val);
        }
    }
    return false;
}

int main() {
    int C, Q;
    cin>>C;
    generateCandidates();
    while(C--){
        memset(color, 0, sizeof(color));
        memset(value, 0, sizeof(value));
        memset(hint, 0, sizeof(hint));
        memset(sum, 0, sizeof(sum));
        memset(length, 0, sizeof(length));
        memset(known, 0, sizeof(known));
        cin>>N;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cin>>color[i][j];
            }
        }
        cin>>Q;
        for(int i=0; i<Q; ++i){
            int y, x, direction, s, len=0;
            cin>>y>>x>>direction>>s;
            y--; x--;
            hint[y][x][direction]=i;
            sum[hint[y][x][direction]]=s;
            int ny=y, nx=x;
            while(true){
                if(direction) {
                    ny+=1;
                }
                else {
                    nx+=1;
                }
                if(!color[ny][nx])
                    break;
                hint[ny][nx][direction]=i;
                len++;
            }
            length[hint[y][x][direction]]=len;
        }
        search();
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}