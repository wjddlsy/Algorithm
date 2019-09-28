#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main(){
    string s;
    cin>>s;
    char stk[31]={};
    int val[31]={}, top = 0;

    for(int i=0; i<s.size(); ++i) {
        if(s[i] == '(' || s[i]=='[') {
            top ++;
            stk[top] = s[i];
        }
        else {
            if(!top || abs(s[i]-stk[top]) > 2) {
                cout << "0";
                return 0;
            } else {
                int m = s[i]==')' ? 2:3;
                int cur = val[top];
                val[top] = 0;
                top--;
                if(cur==0)
                    val[top] += m;
                else
                    val[top] += cur * m;
            }
        }
    }
    cout << (top == 0 ? val[0]:0);
}