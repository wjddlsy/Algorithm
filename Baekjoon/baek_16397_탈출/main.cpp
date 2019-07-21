#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int N, T, G;


string bfs(){
    queue<int> q;
    int discovered[100000];
    memset(discovered, -1, sizeof(discovered));
    q.push(N);
    discovered[N]=0;
    while(!q.empty()){
        int here=q.front();
        q.pop();
        if(discovered[here]>T){
            return "ANG";
        }
        if(here==G)
            return to_string(discovered[here]);
        int there=here+1;
        if(here<100000 && discovered[there]==-1){
            discovered[there]=discovered[here]+1;
            q.push(there);
        }

        there=here*2;
        if(there>=100000)
            continue;
        int tmp=there;
        int digit=1;
        while(tmp){
            digit*=10;
            tmp/=10;
        }
        digit/=10;
        there=there-digit;
        if(there<100000 && discovered[there]==-1){
            discovered[there]=discovered[here]+1;
            q.push(there);

        }
    }
    return "ANG";
}
int main() {
    cin>>N>>T>>G;
    cout<<bfs();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}