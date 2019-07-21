#include <iostream>
#include <string.h>
using namespace std;

const int M=1000*1000*1000+10; // K의 최댓값
int bino[201][201];
int n, m, k, skip;

void calcBino(){
    memset(bino, 0, sizeof(bino));
    for(int i=0; i<=200; ++i){
        bino[i][0]=bino[i][i]=1;
        for(int j=1; j<i; ++j)
            bino[i][j]=min(M, bino[i-1][j-1]+bino[i-1][j]);
    }
}

// skip개를 건너뛰기
void generate3(int n, int m, string s){
    // 기저사례: skip < 0
    if(skip<0) return;
    if(n==0 && m==0){
        if(skip==0) cout<<s<<endl;
        --skip;
        return;
    }
    if(bino[n+m][n]<=skip) {
        skip -= bino[n + m][n];
        return;
    }
    if(n>0) generate3(n-1, m, s+"-");
    if(m>0) generate3(n, m-1, s+"o");
}

void brute(int n, int m, string s) {
    if (n == 0 && m == 0) {
        cout << s << endl;
        return;
    }
    if (n > 0) brute(n - 1, m, s + "-");
    if (m > 0) brute(n, m - 1, s + "o");
}

int main() {
    int c;
    cin>>c;
    while(c--){
        cin>>n>>m>>k;
        skip=k-1;
        calcBino();
        generate3(n,m,"");
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}