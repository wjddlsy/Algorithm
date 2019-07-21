
#include <iostream>
using namespace std;

bool cache[1001]; // 자기 턴에 남은 돌의 개수에 따른 자기가 이기는지,,

string whoWin(int n){

    cache[1] = cache[3] = cache[4] = true;
    cache[2] = false;
    
    for (int i=5; i<=n; ++i){
        cache[i] = ! ( cache[i-1] & cache[i-3] & cache[i-4] ); // 전부다 true가 아니면 됨
    }
    
    if (cache[n])
        return "SK";
    return "CY";
}
string whoWin2(int n){
    
    cache[1] = cache[3] = false;
    cache[4] = cache[2] = true;
    
    for (int i=5; i<=n; ++i){
        cache[i] = ! ( cache[i-1] & cache[i-3] & cache[i-4] ); // 전부다 true가 아니면 됨
    }
    
    if (cache[n])
        return "SK";
    return "CY";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    cout << whoWin2(n);
    return 0;
}
