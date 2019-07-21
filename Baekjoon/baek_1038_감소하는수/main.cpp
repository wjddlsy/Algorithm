#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long ret=0, cnt=0, N;
void pick(int n, int toPick, vector<int>& picked){
    if(toPick==0) {
//        for(auto p:picked)
//            cout<<p;
//        cout<<endl;
        cnt++;
        if(1023-cnt==N){
            int size=picked.size();
            for(int i=0; i<picked.size(); ++i){
                ret+=(picked[i]*pow(10, picked.size()-i-1));
            }
        }

        return;
    }
    int largest = picked.empty()?9:picked.back()-1;
    for(int next=largest; next>=0; --next){
        picked.push_back(next);
        pick(n, toPick-1, picked);
        picked.pop_back();
    }
}
int main() {

    cin>>N;
    if(N>1022)
        ret=-1;
    else {
        for(int i=10; i>0; --i){
            vector<int> picked;
            pick(10, i, picked);
        }
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}