#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, k, m, v, c;
long long sum;

int main(){
    cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++){
        cin >> m >> v;
        pq.push({v,m});
    }
    
    multiset<int> ms;
    for(int i=0; i<k; i++){
        cin >> c;
        ms.insert(c);
    }
    
    while(pq.size()){
        int value=pq.top().first;
        int mass=pq.top().second;
        pq.pop();
        auto it=ms.lower_bound(mass);
        if(it==ms.end())
            continue;
        ms.erase(it);
        sum+=value;
    }
    
    cout << sum;
    return 0;
}
