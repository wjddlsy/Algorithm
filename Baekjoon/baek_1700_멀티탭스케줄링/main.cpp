#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <map>
using namespace std;

const int INF=987654321;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin>>N>>K;
    vector<int> order(K), updated(K+1, -1);
    vector<bool> isOn(K+1, false);
    vector<queue<int>> when(K+1);
    map<int, int> multitap;
    for(int i=0; i<K; ++i){
        cin>>order[i];
        when[order[i]].push(i);
    }
    int ret=0;
    for(int i=0; i<K; ++i){
        int next=INF;
        when[order[i]].pop();
        if(!when[order[i]].empty()) {
            next=when[order[i]].front();
        }

        if(isOn[order[i]]) {
            multitap[order[i]]=next;
            //updated[order[i]]=next;
            continue;
        }

        if(multitap.size()<N){
            multitap[order[i]]=next;
            isOn[order[i]]=true;
        }

        else {
            auto it_max=multitap.begin();
            for(auto it=multitap.begin(); it!=multitap.end(); ++it){
                if(it->second>it_max->second)
                    it_max=it;
            }
            ret++;
            isOn[it_max->first]=false;
            multitap.erase(it_max);

            multitap[order[i]]=next;
            isOn[order[i]]=true;
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}