#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector<vector<int>> colors(N+1);
    for(int i=0; i<N; ++i){
        int a, b;
        cin>>a>>b;
        colors[b].push_back(a);
    }

    int ret=0;
    for(int i=1; i<=N; ++i){
        if(colors[i].empty())
            continue;
        sort(colors[i].begin(), colors[i].end());
    }

    int val=0;
    for(int i=1; i<=N; ++i){
        for(int j=0; j<colors[i].size(); ++j){
            if(j==0) {
                val = colors[i][j + 1] - colors[i][j];
            }
            else if(j==colors[i].size()-1) {
                val = colors[i][j] - colors[i][j - 1];
            }
            else
                val=min(colors[i][j+1]-colors[i][j], colors[i][j]-colors[i][j-1]);
            ret+=val;
        }
    }

    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}