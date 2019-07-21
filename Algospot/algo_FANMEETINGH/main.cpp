#include <iostream>

using namespace std;

bool isPossible(unsigned int a, unsigned int b){
    // O(n)에 확인할 수 있음
    unsigned int ret=a&b;
    if(ret)
        return false;
    return true;
}

int count(unsigned int a, unsigned int b, int a_size, int b_size){
    if(a>b)
        return 0;
    int cnt=0;
    unsigned int tmp=0;
    for(int index=0; index<=b_size-a_size; ++index){
        tmp=b;
        tmp=(tmp<<(32-index-a_size));
        tmp=(tmp>>(32-a_size));
        if(isPossible(a, tmp))
            cnt++;
    }

    return cnt;

}


int main() {
    int C;
    cin>>C;
    string a, b;

    while(C--){
        cin>>a>>b;
        unsigned int ia=0, ib=0;
        //string to int!!!!!!!!
        for(int i=0; i<a.size(); ++i){
            ia=(ia << 1);
            if(a[i]=='M')
                ia++;
        }

        for(int i=0; i<b.size(); ++i){
            ib=(ib << 1);
            if(b[i]=='M')
                ib++;
        }

        cout << count(ia,ib, a.size(), b.size())<<endl;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}