#include <iostream>
#include <string.h>
using namespace std;

const int MOD=1000*1000*1000;
int cache[101][10][1<<10]; //몇개까지 왔는지, 마지막 수, 다나왔는지 확인하기

int N;
// 뭐라고 정의하지
// 현재 길이가 n이고 마지막 수가 last일 때, check만큼 나온 수 ! ....
int step(int n, int last, int check){
    if(n==N){
        if(check==(1<<10)-1) return 1;
        return 0;
    }

    int &ret=cache[n][last][check];
    if(ret!=-1)
        return ret;
    ret=0;
    if(last>=1)
        ret+=step(n+1, last-1, check|1<<(last-1));
    if(last<9)
        ret+=step(n+1, last+1, check|1<<(last+1));
    ret%=MOD;
    return ret;


}
int main() {
    cin>>N;
    memset(cache, -1, sizeof(cache));
    int ret=0;
    for(int last=1; last<=9; ++last){
        ret+=step(1,last,1<<last);
        ret%=MOD;
    }
    cout<<ret<<endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}