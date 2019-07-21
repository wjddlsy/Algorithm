#include <iostream>
#include <vector>
#include <set>
using namespace std;

string makeString(string s, int start){
    string ret="";
    int n=s.size();
    for(int i=0; i<n; ++i){
        ret+=s[start];
        start=(start+1)%n;
    }
    return ret;
}
int main() {
    string s;
    cin>>s;
    set<string> words;
    for(int i=0; i<s.size(); ++i){
        words.insert(makeString(s, i));
    }
    cout<<words.size();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}