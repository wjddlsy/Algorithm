#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N; cin>>N;
    vector<pair<int, int>> works(N);
    // 끝나는 날이 뒤인 애들을 뒤에 채우는거야
    for(auto &work:works){
        cin>>work.first>>work.second;
    }
    sort(works.begin(), works.end());
    priority_queue<int, vector<int>, greater<>> pq;
    int ret=0;

    for(auto &work:works) {
        if(pq.empty()) {
            pq.push(work.second);
            ret+=work.second;
        }
        else {
            if(pq.size()<work.first) {
                pq.push(work.second);
                ret+=work.second;
            }
            else if(pq.top()<work.second) {
                ret-=pq.top();
                pq.pop();
                pq.push(work.second);
                ret+=work.second;
            }
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}