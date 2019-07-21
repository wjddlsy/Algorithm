#include <iostream>
#include <vector>

using namespace std;
int main() {
    string s;
    int ret, tmp=1;
    vector<char> stk;
    cin>>s;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='('){
            tmp*=2;
            stk.push_back('(');
        }
        else if(s[i]=='['){
            tmp*=3;
            stk.push_back('[');
        }
        else if(s[i]==')'){
            if(s[i-1]=='(')
                ret+=tmp;
            if(stk.empty()){
                cout<<"0";
                return 0;
            }
            if(stk.back()=='('){
                stk.pop_back();
            }
            tmp/=2;
        }
        else if(s[i]==']'){
            if(s[i-1]=='[')
                ret+=tmp;
            if(stk.empty()){
                cout<<"0";
                return 0;
            }
            if(stk.back()=='['){
                stk.pop_back();
            }
            tmp/=3;
        }
    }
    cout<<stk.empty()?ret:0;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}