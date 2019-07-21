#include <iostream>
#include <vector>
#include <set>
using namespace std;


vector<pair<int, set<string>>> hPhotos;
vector<pair<int, set<string>>> vPhotos;

int main() {
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        char type;
        int nTag;
        cin>>type>>nTag;
        set<string> tags;

        for(int i=0; i<nTag; ++i){
            string s;
            cin>>s;
            tags.insert(s);
        }

        if(type=='H'){
            hPhotos.push_back({i,tags});
        }
        else {
            vPhotos.push_back({i, tags});
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}