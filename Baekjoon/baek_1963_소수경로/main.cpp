#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

bool isPrime[10000];

void eratos() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i=2; i*i<10000; ++i){
        if(isPrime[i]) {
            for(int j=i*2; j<10000; j+=i)
                isPrime[j]=false;
        }
    }
}

vector<int> convert(int here, int pos){
    int div=pow(10, pos), sub=(here/div)%10;
    int origin=here-sub*div;
    vector<int> ret;
    for(int i=0; i<10; ++i){
        if(pos==3 && i==0)
            continue;
        int converted=origin+div*i;
        if(isPrime[converted])
            ret.emplace_back(origin+div*i);
    }
    return ret;
}
int main() {
    int T;
    cin>>T;
    eratos();
    while(T--){
        int start, end;
        cin>>start>>end;
        queue<int> q;
        vector<int> discovered(10000, -1);
        discovered[start]=0;
        q.push(start);

        while(!q.empty()){
            int here=q.front();
            q.pop();
            if(here==end)
                break;
            for(int i=0; i<4; ++i){
                vector<int> theres=convert(here, i);
                for(auto &there:theres){
                    if(discovered[there]!=-1)
                        continue;
                    discovered[there]=discovered[here]+1;
                    q.push(there);
                }
            }
        }
        cout<<discovered[end]<<'\n';
    }
    return 0;
}