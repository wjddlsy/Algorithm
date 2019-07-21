#include <iostream>
#include <list>
#include <vector>
using namespace std;

int N;
int main() {
    cin>>N;
    vector<int> ret;
    list<pair<int, int>> ballons;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        ballons.emplace_back(i, a);
    }
    int index=0;
    while(ballons.size()>1){
        auto it=ballons.begin();
        advance(it, index);

        int move=(*it).second, num=(*it).first;

        ballons.erase(it);
        ret.emplace_back(num);
        if(move>0)
            index--;
        if(index==-1)
            index=ballons.size()-1;
        else if(index==ballons.size())
            index=0;
        if(move>0)
            index=(index+move)%ballons.size();
        else {
            move=(-1*move)%ballons.size()*-1;
            index = (index + ballons.size() + move) % ballons.size();
        }

    }
    ret.emplace_back(ballons.front().first);
    for(auto r:ret){
        cout<<r<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}