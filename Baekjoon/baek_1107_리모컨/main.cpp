#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;


vector<int> channels;
int m=0, N;
void number(int n, int toPick, int new_num){
    if(toPick==0){
        // 얼마나 이동하는 지 계산
        m=std::min(m, abs(N-new_num)+n);
        return;
    }

    for(int i=0; i<channels.size(); ++i){
        int tmp=channels[i]*pow(10, toPick-1); //골랐을 때 ...
        number(n, toPick-1, new_num+tmp);
    }

}

int main() {

    bool ch[10]={1,1,1,1,1,1,1,1,1,1};
    int broken, in;
    cin>>N>>broken;
    for(int i=0; i<broken ;++i){
        cin>>in;
        ch[in]=false;
    }

    for(int i=0; i<10; ++i){
        if(ch[i])
            channels.push_back(i);
    }


    m=abs(N-100);

    if(broken!=10) {
        for (int i = 1; i <= 6; ++i) {
            // 6자리수까지하깅
            number(i, i, 0);
        }
    }

    cout << m;
    return 0;
}