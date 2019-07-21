#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,in;
    cin>>N;
    stack<pair<int, int>> stk;
    long long int ret=0;
    for(int i=0; i<N; ++i){
        cin>>in;
        pair<int, int> p(in, 1);
        for( ; !stk.empty() && stk.top().first <= in; stk.pop() ){
            //stk.pop();
            ret+=stk.top().second;
            if(stk.top().first==in)
                p.second+=stk.top().second;
        }

        if(!stk.empty()) ++ret;
        stk.push(p);
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}

