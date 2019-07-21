#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
//vector<int> perm;

int reverseBit(int here, int start){
    // 1 000 111 222 333 444 555 666 777
    int total=N*3;
    int headLength=(start)*3, midLength=K*3, tailLength=total-headLength-midLength;
    int head=(here>>(total-headLength)), tail=(here & ((1<< tailLength)-1));
    int mid= (here>>tailLength) & ((1<<midLength)-1);
    for(int i=0; i<K; ++i){
        head=head<<3;
        head= head+ (mid & (1<<3)-1);
        mid=mid>>3;
    }

    head = head << tailLength;
    return head+tail;
}
int bfs(int start, int end){
   queue<pair<int, int>> q;
   vector<bool> discovered(1<<26, false);
   q.push({start, 0});
   discovered[start]=true;
   while(!q.empty()){
       int here=q.front().first;
       int dist=q.front().second;
       q.pop();
       if(here==end){
            return dist;
       }
       for(int i=0; i<=N-K; ++i){
           int there=reverseBit(here, i);
           if(discovered[there])
               continue;
           q.push({there, dist+1});
           discovered[there]=true;
       }
   }
   return -1;
}
int main() {
    cin>>N>>K;
    int start=1, end=1;
    for(int i=0; i<N; ++i){
        int a;
        cin>>a;
        a--;
        start=start<<3;
        start+=a;
    }
    for(int i=0; i<N; ++i){
        end=end<<3;
        end+=i;
    }
    cout<<bfs(start, end);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}