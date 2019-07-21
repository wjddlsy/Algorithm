#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    vector<string> dnaList(N);
    for(auto &dna:dnaList) {
        cin>>dna;
    }
    vector<vector<int>> count(M, vector<int>(26,0));

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            count[j][dnaList[i][j]-'A']++;
        }
    }

    string ret;
    int dist=0;
    for(int i=0; i<M; ++i){
        int maxFreq=0;
        char c;
        for(int j=0; j<26; ++j){
            if(maxFreq<count[i][j]) {
                c=(char)(j+'A');
                maxFreq=count[i][j];
            }
        }
        ret+=c;
        dist+=N-maxFreq;
    }
    cout<<ret<<'\n'<<dist;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}