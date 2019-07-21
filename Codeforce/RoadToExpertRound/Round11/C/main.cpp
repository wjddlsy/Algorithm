#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> p(n);
    vector<pair<int, int>> index;
    vector<int> order(n);

    for(int i=0; i<n; ++i){
        cin>>p[i];
        index.emplace_back(p[i], i);
    }
    sort(index.begin(), index.end());
    for(int i=0; i<n; ++i){
        order[index[i].second]=i;
    }

    for(int i=0; i<m; ++i){
        int l, r, x;
        cin>>l>>r>>x;
        l--; r--; x--;
        if(x<l || x>r){
            cout<<"Yes"<<'\n';
        }
        else {
            int value=p[x], rank=l;
            for(int j=l; j<=r; ++j){
                if(p[j]<value)
                    rank++;
            }
            if(rank==x)
                cout<<"Yes"<<'\n';
            else
                cout<<"No"<<'\n';
        }
    }
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}