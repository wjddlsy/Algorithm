#include <iostream>
#include <string.h>

using namespace std;

int cache[301][2];
int step[301];
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i){
        int in;
        cin>>in;
        step[i]=in;
    }


    cache[1][0]=step[1];
    cache[2][0]=step[1]+step[2];
    cache[2][1]=step[2];
    //cache[2][1]=step[2];
    for(int i=3; i<=n; ++i){
            cache[i][0] = cache[i - 1][1] + step[i]; // 한칸 뛰기
            cache[i][1] = max(cache[i-2][1],cache[i - 2][0])+ step[i]; //두칸 뛰기
    }
    cout << max(cache[n][0], cache[n][1]);

    return 0;
}