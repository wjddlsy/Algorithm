#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main() {
    int A, B, C;
    cin>>A>>B>>C;
    vector<int> capacity={A, B, C};
    vector<int> bottles={0,0,C};

    set<int> ret;
    queue<vector<int>> q;
    map<vector<int>, bool> discovered;
    q.push(bottles);
    discovered[bottles]=true;
    while(!q.empty()){
        vector<int> here=q.front();
        q.pop();
        if(here[0]==0) {
            ret.insert(here[2]);
        }
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(i==j)
                    continue;
                vector<int> there=here;
                if(here[i]+here[j]>capacity[j]) {
                    there[i]=here[i]-(capacity[j]-here[j]);
                    there[j]=capacity[j];
                }
                else {
                    there[i]=0;
                    there[j]=here[i]+here[j];
                }
                if(discovered[there])
                    continue;
                q.push(there);
                discovered[there]=true;
            }
        }
    }
    for(auto s:ret){
        cout<<s<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}