#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int C;
    cin>>C;
    while(C--){
        int N, K;
        cin>>N>>K;
        list<int> people;
        for(int i=1; i<=N; ++i){
            people.emplace_back(i);
        }
        int index=0;
        while(people.size()>2){
            auto it=people.begin();
            advance(it, index);
            it=people.erase(it);
            index--;
            if(index==-1)
                index=people.size()-1;
            index=(index+K)%people.size();
        }
        cout<<people.front() <<" "<<people.back()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}