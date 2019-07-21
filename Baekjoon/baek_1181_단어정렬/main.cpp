#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

struct Comparator{
    bool operator()(const string &a, const string &b){
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size()<b.size();
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> ss;
    while(n--){
        cin>>s;
        ss.push_back(s);
    }

    sort(ss.begin(), ss.end(), Comparator());
    string tmp="";
    for(auto sss:ss){
        if(sss==tmp)
            continue;
        cout << sss << endl;
        tmp=sss;

    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}