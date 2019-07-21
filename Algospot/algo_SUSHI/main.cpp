#include <iostream>
using namespace std;

int n, m, price[20], pref[20];
int c[201];

int sushi3(){
    int ret=0;
    c[0]=0;
    for(int budget=1; budget<=m; ++budget){
        int cand=0;
        for(int dish=0; dish<n; ++dish){
            if(budget>=price[dish]){
                cand=max(cand, c[(budget-price[dish])%201]+pref[dish]);
            }
        }
        c[budget%201]=cand;
        ret=max(ret, cand);
    }
    return ret;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        m/=100;
        for(int i=0; i<n; ++i){
            cin>>price[i]>>pref[i];
            price[i]/=100;
        }
        cout<<sushi3()<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}