#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N=15;
int k;
string word[MAX_N+1];
int cache[MAX_N+1][(1<<MAX_N)+1], overlap[MAX_N+1][MAX_N+1];
int restore(int last, int used){
    //기저사례
    if(used==(1<<k)-1) return 0;
    int& ret=cache[last][used];
    if(ret!=-1) return ret;
    ret=0;
    for(int next=0; next<k; ++next){
        if((used&(1<<next))==0){
            int cand=overlap[last][next]+restore(next, used+(1<<next));
            ret=max(ret, cand);
        }

    }
    return ret;
}

string reconstruct(int last, int used){
    if(used==(1<<k)-1) return "";
    for(int next=0; next<k; ++next){
        if(used&(1<<next)) continue;
        int ifUsed=restore(next, used+(1<<next))+overlap[last][next];
        if(restore(last, used)==ifUsed){
            return (word[next].substr(overlap[last][next])+reconstruct(next, used+(1<<next)));
        }
    }
    return "****oops****";
}
int getoverlap(const string& a, const string& b){
    int l=min(a.size(), b.size());
    for(int i=l; i>0; --i){
        if(a.substr(a.size()-i)==b.substr(0,i))
            return i;
    }
    return 0;
}
int main() {
    int c;
    cin>>c;
    while(c--){
        cin>>k;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<k; ++i){
            cin>>word[i];
        }
        while(true) {
            bool removed = false;
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                    if (i != j && word[i].find(word[j]) != -1) {
                        word[j] = word[k - 1];
                        k--;
                        removed=true;
                    }
                }
            }
            if(!removed)
                break;
        }
        word[k]="";
        for(int i=0; i<=k; ++i){
            for(int j=0; j<=k; ++j){
                overlap[i][j]=getoverlap(word[i],word[j]);
            }

        }
        cout<<reconstruct(k, 0)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}