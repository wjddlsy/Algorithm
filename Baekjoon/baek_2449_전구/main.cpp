#include <iostream>
#include <string.h>
using namespace std;

int lamp[201];
int cache[201][201]; // left, right까지 색 통일하는데 드는 최솟값
int N, K;
int go(int left, int right){
    if(left==right)
        return 0;
    int& ret=cache[left][right];
    if(ret!=-1)
        return ret;
    ret=987654321;
    for(int i=left; i<right; ++i){
        ret=min(ret, go(left, i)+go(i+1, right)+(int)(lamp[left]!=lamp[i+1]));
    }
    return ret;
}
int main() {
    cin>>N>>K;
    for(int i=0; i<N; ++i){
        cin>>lamp[i];
    }
    memset(cache, -1, sizeof(cache));
    cout<<go(0, N-1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}