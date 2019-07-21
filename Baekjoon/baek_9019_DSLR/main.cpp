#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int D(int n){
    return n*2>9999?((n*2)%10000):n*2;
}

int S(int n){
    return n-1<0?9999:n-1;
}
int L(int n){
    return (n%1000)*10+n/1000;
}

int R(int n){
    return (n%10)*1000+n/10;
}
string bfs(int A, int B){
    queue<pair<int, string>> q;
    bool discovered[10000]={};
    q.push({A, ""});
    discovered[A]=true;
    while(!q.empty()){
        int here=q.front().first;
        string ret=q.front().second;
        q.pop();
        if(here==B)
            return ret;
        int there=D(here);
        if(!discovered[there]){
            discovered[there]=true;
            q.push({there, ret+"D"});
        }
        there=S(here);
        if(!discovered[there]){
            discovered[there]=true;
            q.push({there, ret+"S"});
        }
        there=L(here);
        if(!discovered[there]){
            discovered[there]=true;
            q.push({there, ret+"L"});
        }
        there=R(here);
        if(!discovered[there]){
            discovered[there]=true;
            q.push({there, ret+"R"});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int A, B;
        cin>>A>>B;
        cout<<bfs(A, B)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}