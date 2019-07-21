#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, in;
    string s;
    vector<int> stack;
    cin >>N;
    while(N--){
        cin>>s;
        if(s=="push"){
            cin >> in;
            stack.push_back(in);
        }
        else if(s=="top"){
            if(stack.empty())
                cout<< -1 << endl;
            else
                cout << stack.back() << endl;
        }
        else if(s=="size"){
            cout << stack.size() << endl;
        }
        else if(s=="empty"){
            cout << (stack.empty()?1:0) << endl;
        }
        else if(s=="pop"){
            if(stack.empty())
                cout << -1 << endl;
            else {
                cout << stack.back() << endl;
                stack.pop_back();
            }
        }

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}