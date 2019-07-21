#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<string> words(N);
    map<char, int> m;

    for(auto &word:words){
        cin>>word;
        for(int i=0; i<word.size(); ++i){
            m[word[i]]+=(int)pow(10, word.size()-1-i);
        }
    }

    vector<int> count;
    for(auto &mm:m){
        count.emplace_back(mm.second);
    }
    sort(count.begin(), count.end(), greater<>());
    int ret=0;
    for(int i=0; i<count.size(); ++i){
        ret+=(9-i)*count[i];
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}