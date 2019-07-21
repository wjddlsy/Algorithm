#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t, n, m, in, ret=0;
    cin>> t;
    while(t--){
        ret=0;

        queue<pair<int,int>> q;
        priority_queue<int> pq;
        cin>>n>>m;
        for(int i=0; i<n; ++i){
            cin>>in;
            q.push({in,i});
            pq.push(in);
        }
        while(!q.empty()){
            int first=q.front().first;
            int pr=q.front().second;
            q.pop();
            if(pq.top()==first){
                pq.pop();
                ret++;
                if(m==pr){
                    cout<<ret<<endl;
                    break;
                }
            }
            else
                q.push({first, pr});
        }

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}