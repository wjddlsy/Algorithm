#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_DISCS=12;
// index의 기둥 번호 반환
int get(int state, int index){
    return (state>>(index*2))&3;
}
// index에 value 기둥
int set(int state, int index, int value){
    return (state & ~(3<<(index*2))) | (value<<(index*2));
}
int sgn(int x){ if(!x) return 0; return x>0?1:-1; }
int incr(int x){
    if(x<0)
        return x-1;
    return x+1;
}

int c[1<<(MAX_DISCS)*2];

int bidir(int discs, int begin, int end){
    if(begin==end) return 0;
    queue<int> q;
    // c 초기화
    memset(c, 0, sizeof(c));
    q.push(begin); c[begin]=1; // 정방향탐색으로 방문
    q.push(end); c[end]=-1; // 역방향탐색으로 방문
    while(!q.empty()){
        int here=q.front();
        q.pop();
        int top[4]={-1,-1,-1,-1};
        for(int i=discs-1; i>=0; --i)
            top[get(here, i)]=i;
        for(int i=0; i<4; ++i){
            if(top[i]!=-1){
                for(int j=0; j<4; ++j){
                    if(i!=j && (top[j]==-1 || top[j]>top[i])){
                        int there=set(here, top[i], j);
                        if(c[there]==0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        }
                        // 가운데에서 만난 경우
                        else if(sgn(c[there])!=sgn(c[here]))
                            return abs(c[there])+abs(c[here])-1;
                    }
                }
            }
        }
    }
    return -1;
}
int main() {
    int C;
    cin>>C;
    while(C--){
        int N;
        cin>>N;
        int begin=0, end=0;
        for(int i=0; i<4; ++i){
            int n;
            cin>>n;
            for(int j=0; j<n; ++j){
                int index;
                cin>>index;
                begin=set(begin, index-1, i);
            }

        }
        for(int i=0; i<N; ++i){
            end=set(end, i ,3);
        }
        cout<<bidir(N, begin, end)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}