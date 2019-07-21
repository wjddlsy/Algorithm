#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
int d[]={1, -1, 2};
int bfs(){
    queue<int> q;
    int discovered[200000];
    memset(discovered, -1, sizeof(discovered));
    q.push(N);
    discovered[N]=0;
    while(!q.empty()){
        int here=q.front();
        q.pop();
        if(here==K)
            return discovered[here];
        for(int i=0; i<3; ++i){
            int there;
            if(i==2)
                there=here*2;
            else
                there=here+d[i];
            if(discovered[there]==-1 && there>=0 && there<=100000){
                q.push(there);
                discovered[there]=discovered[here]+1;
            }
        }
    }
    return -1;
}
int main() {
    cin>>N>>K;
    cout<<bfs();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}