#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int F, S, G, U, D;

string bfs(){
    vector<int> discovered(F+1, -1);
    queue<int> q;
    q.push(S);
    discovered[S]=0;
    while(!q.empty()){
        int here=q.front();
        q.pop();
        if(here==G)
            return to_string(discovered[here]);
        int there=here+U;
        if(there<=F && discovered[there]==-1){
            q.push(there);
            discovered[there]=discovered[here]+1;
        }
        there=here-D;
        if(there>0 && discovered[there]==-1){
            q.push(there);
            discovered[there]=discovered[here]+1;
        }
    }

    return "use the stairs";

}
int main() {
    cin>>F>>S>>G>>U>>D;
    cout<<bfs();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}