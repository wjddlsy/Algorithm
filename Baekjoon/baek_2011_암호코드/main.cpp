#include <iostream>

using namespace std;

int main() {

    string s;
    cin >> s;

    long long ret = 0;
    long long cache[5001]={};
    string tmp = s.substr(0, 2);
    cache[0]= s[0]!='0' ? 1 : 0;
    cache[1] = (stoi(tmp)<=26 && s[0]!='0'? 1: 0) + (s[1]!='0'? cache[0]: 0 );

    for(int i=2; i<s.size(); ++i) {
        tmp = s.substr(i-1, 2);
        cache[i] = (s[i]!='0'? cache[i-1] : 0) + (stoi(tmp)<=26 && s[i-1]!='0'? cache[i-2] : 0);
        cache[i]%=1000000;
    }
    cout<<cache[s.size()-1];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}