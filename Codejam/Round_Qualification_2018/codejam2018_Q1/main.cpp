#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int calScore(string s){
    int ret=0, damage=1;
    for(auto ss:s){
        if(ss=='C'){
            damage*=2;
        }
        else
            ret+=damage;
    }
    return ret;
}

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        int D;
        string P;
        cin>>D>>P;
        // S가 앞으로 오는게 좋은거같은대
        // s가 앞으로왔을때 줄어드는 데미지는 ....
        // c를 뒤로 보냄
        vector<int> posC;
        for(int i=0; i<P.size(); ++i){
            if(P[i]=='C')
                posC.push_back(i);
        }

        int cur=calScore(P);
        int ret=0;
        int damage=(int)pow(2, posC.size());
        int csize=P.size()-1;
        while(cur>D &&!posC.empty()){
            int pos=posC.back();
            posC.pop_back();
            while(pos<csize){
                ret++;
                cur-=damage;
                cur+=damage/2;
                pos++;
                if(cur<=D){
                    break;
                }
            }
            damage/=2;
            csize--;
        }

        if(cur>D)
            cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<'\n';
        else
            cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}