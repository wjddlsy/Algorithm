#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

bool isRight(string p) {
    stack<char> st;
    for(int i=0; i<p.size(); ++i) {
        if(p[i]=='(')
            st.push('(');
        else {
            if(st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}

string solution(string p) {
    string answer = "";
    if(p.size()==0)
        return answer;
    if(isRight(p))
        return p;
    map<char, int> m;
    string u, v;
    for(int i=0; i<p.size(); ++i) {
        m[p[i]]++;
        if(m['('] !=0 && m['(']==m[')']) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            if(isRight(u))
                answer = u + solution(v);
            else {
                u.erase(0, 1); u.pop_back();
                string uu;
                for(auto &c:u) {
                    if(c=='(')
                        uu+=')';
                    else
                        uu+='(';
                }
                answer = "(" + solution(v) + ")" + uu;
            }
            break;
        }
    }
    return answer;
}

int main() {
    string s;
    cin>>s;
    cout<<solution(s);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}