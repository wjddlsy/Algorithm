#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
    int N, K;
    cin>>N>>K;
    long long ret=0;
    vector<queue<int>> friends(21);

    for(int i=0; i<N; ++i){
        string s;
        cin>>s;
        int index=s.size();
        while(!friends[index].empty() && friends[index].front()<i-K)
            friends[index].pop();
        ret+=friends[index].size();
        friends[index].push(i);
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}