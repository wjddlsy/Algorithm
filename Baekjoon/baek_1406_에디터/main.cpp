#include <iostream>
#include "list"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char c;
    string input;
    cin >>input >> n;
    list<char> s;
    for(int i=0; i<input.size(); ++i){
        s.push_back(input[i]);
    }
    list<char>::iterator idx=s.end();
    while(n--){
        char cmd;
        cin>>cmd;
        if(cmd=='P'){
            char x;
            cin>>x;
            s.insert(idx, x);
        }
        else if(cmd=='L'){
            if(idx!=s.begin())
                idx--;
        }
        else if(cmd=='D'){
            if(idx!=s.end())
                idx++;
        }
        else if(cmd=='B'){
            if(idx!=s.begin()){
                idx--;
                idx=s.erase(idx);
                //idx++;
            }
        }
    }

    for(auto &ss:s){
        cout<<ss;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}