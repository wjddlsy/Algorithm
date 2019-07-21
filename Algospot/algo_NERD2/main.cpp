#include <iostream>
#include <map>
using namespace std;

int N;
map<int, int> cands;

bool isDominated(int x, int y){
    auto it=cands.lower_bound(x); //나보다 큰거
    if(it==cands.end()) return false;
    return y<it->second;
}

void removeDominated(int x, int y){
    auto it=cands.lower_bound(x);
    if(it==cands.begin()) return;
    --it;
    while(true){
        if(it->second>y) break;
        if(it==cands.begin()){
            cands.erase(it);
            break;
        }
        else {
            auto it2=it;
            --it2;
            cands.erase(it);
            it=it2;
        }
    }
}
int solve(int x, int y){
    if(isDominated(x, y)) return cands.size();
    removeDominated(x, y);
    cands[x]=y;
    return cands.size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin>>C;
    while(C--){
        cands.clear();
        cin>>N;
        int ret=0;
        for(int i=0; i<N; ++i) {
            int p, q;
            cin>>p>>q;
            ret+=solve(p,q);
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}