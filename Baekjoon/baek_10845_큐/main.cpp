#include <iostream>
#include <vector>
using namespace std;

vector<int> queue;
int main() {
    int n, start=0, end=0, in;
    string s;
    cin>>n;
    while(n--){
        cin >> s;
        if(s=="push"){
            cin>>in;
            queue.push_back(in);
        }
        else if(s=="pop"){
            if(queue.empty())
                cout<<-1<<endl;
            else{
                cout<<queue.front()<<endl;
                queue.erase(queue.begin());
            }
        }
        else if(s=="size"){
            cout<<queue.size()<<endl;
        }
        else if(s=="empty"){
            cout<<(queue.empty()?1:0) << '\n';
        }
        else if(s=="front"){
            if(queue.empty())
                cout<<-1<<endl;
            else{
                cout<<queue.front()<<endl;
            }
        }
        else if(s=="back"){
            if(queue.empty())
                cout<<-1<<endl;
            else
                cout<<queue.back()<<endl;
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}