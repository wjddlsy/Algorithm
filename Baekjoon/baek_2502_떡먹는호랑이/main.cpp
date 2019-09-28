#include <iostream>

using namespace std;

int main() {
    int D, K;
    cin>>D>>K;
    // D째 날에 준 떡의 개수가 K개임

    int arr[32] = {};
    arr[1] = arr[2] = 1;
    for(int i=3; i<=D+1; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    bool flag = false;

    int a=0, b=0;
    for(a=1; a<=K; ++a) {
        for(b=1; b<=K; ++b) {
            int cnt = a*arr[D-2] + b*arr[D-1];
            if(cnt > K)
                break;
             if(cnt == K ) {
                 flag = true;
                 break;
             }
        }
        if(flag)
            break;
    }
    cout << a<<'\n'<<b;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}