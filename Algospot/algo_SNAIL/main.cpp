#include <iostream>
#include <string.h>
using namespace std;

double cache[1000][2000];

int n, m;
double climb(int days, int sum){
    if(days==m) {
        if(sum>=n)
            return 1;
        else
            return 0;
    }
    double& ret=cache[days][sum];
    if(ret!=-1) return ret;
    return ret=(0.25*climb(days+1, sum+1) + 0.75*climb(days+1, sum+2));
}
int main() {
    int c;
    cin>>c;
    while(c--){
        cin>>n>>m; //n: 우물 길이, m: 제한날짜
        for(int i=0; i<1000; ++i){
            for(int j=0; j<2000; ++j)
                cache[i][j]=-1;
        }

        cout.precision(10);
        cout<<(double)climb(0, 0)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}