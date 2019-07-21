#include <iostream>
#include <deque>

using namespace std;
int main() {
    deque<int> dq;
    int n, in;
    string s;
    cin>>n;
    while(n--){
        cin >> s;
        if(s=="push_back"){
            cin >> in;
            dq.push_back(in);
        }
        else if(s=="push_front"){
            cin >>in;
            dq.push_front(in);
        }
        else if(s=="pop_front"){
            if(dq.empty())
                cout<<-1<<'\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(s=="pop_back"){
            if(dq.empty())
                cout<<-1<<'\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(s=="size"){
            cout<<dq.size()<<'\n';
        }
        else if(s=="empty"){
            cout<<(dq.empty()?1:0)<<'\n';
        }
        else if(s=="front"){
            if(dq.empty())
                cout<<-1<<'\n';
            else
                cout<<dq.front()<<'\n';
        }
        else if(s=="back"){
            if(dq.empty())
                cout<<-1<<'\n';
            else
                cout<<dq.back()<<'\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}