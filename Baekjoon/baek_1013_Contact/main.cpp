#include <iostream>

using namespace std;

int adj[8][2]= {
        {6, 1}, {2, 7},
        {3, 7}, {3, 4},
        {5, 4}, {7, 0},
        {7, 0}, {7, 7}
};
int main() {
    int T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;

        int t=0;
        for(auto &c:s) {
            t=adj[t][c-'0'];
        }
        if(t==0 || t==4 )
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}