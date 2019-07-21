#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    string s;
    cin>>n;

    while(n--){
        cin>>s;
        stack<char> stk;
        bool chk=true;

        for(auto ss:s){
            if(ss=='('||ss=='{'||ss=='[')
                stk.push(ss);
            else {
                if(stk.empty()){
                    chk=false;
                    break;
                }
                else if(stk.top()+1==ss || stk.top()+2==ss){
                    stk.pop();
                }
            }
        }

        if(stk.empty() && chk)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
