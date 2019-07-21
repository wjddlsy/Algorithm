#include <iostream>
#include "deque"
using namespace std;


deque<int> dq;

void left(){
    int tmp=dq.front();
    dq.pop_front();
    dq.push_back(tmp);
}

void right(){
    int tmp=dq.back();
    dq.pop_back();
    dq.push_front(tmp);
}

int main() {
    int n, m, in, l=0, r=0, cnt=0, index=0;
    cin>>n>>m;
    deque<int> q;
    for(int i=1; i<=n; ++i){
        dq.push_back(i);
    }

    auto it=dq.begin();

    for(int i=0; i<m; ++i){
        cin>>in;
        if(dq.front()==in)
            dq.pop_front();
        else {
            index=1;
            for(it=dq.begin();it!=dq.end(); ++it){
                if(*it==in)
                    break;
                index++;
            }

            l=index-1;
            r=dq.size()-index+1;
            if(l>=r){
                for(int j=0; j<r; ++j)
                 right();
                cnt+=r;
                dq.pop_front();
            }

            else {
                for(int j=0; j<l; ++j)
                    left();
                cnt+=l;
                dq.pop_front();

            }
        }
    }

    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}