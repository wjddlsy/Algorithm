#include <iostream>
#include <vector>
#include "cmath"
using namespace std;

#define MAX_N 10000000

int minFactor[MAX_N+1];
void eratosthenes2(int n){
    // 1은 항상 예외
    minFactor[0]=minFactor[1]=-1;
    // 모든 숫자를 처음에는 소수로 표시
    for(int i=2; i<=n; ++i){
        minFactor[i]=i;
    }
    int sqrtn=int(sqrt(n));
    for(int i=2; i<=sqrtn; ++i){
        if(minFactor[i]==i){
            for(int j=i*i; j<=n; j+=i){
                // 아직 약수를 본 적이 없는 숫자인 경우 i를 써 둔다.
                if(minFactor[j]==j)
                    minFactor[j]=i;
            }
        }
    }
}

int minFactorPower[MAX_N+1];
int factors[MAX_N+1];

void getFactorsSmart(){
    factors[1]=1;
    for(int n=2; n<=MAX_N; ++n){
        //소수인 경우 약수가 두개뿐
        if(minFactor[n]==n){
            minFactorPower[n]=1;
            factors[n]=2;
        }
        else{
            int p=minFactor[n];
            int m=n/p;
            //m이 p로 더 이상 나누어지지 않는 경우
            if(p!=minFactor[m])
                minFactorPower[n]=1;
            else
                minFactorPower[n]=minFactorPower[m]+1;
            int a=minFactorPower[n];
            factors[n]=(factors[m]/a) * (a+1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int cnt=0;
    int c, n, lo, hi;
    cin >> c;
    eratosthenes2(MAX_N);
    getFactorsSmart();
    while(c--){
        cin>>n>>lo>>hi;
        cnt = 0;
        for(int i=lo; i<=hi; ++i) {
            if (factors[i]==n)
                cnt++;
        }
        cout << cnt << endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}