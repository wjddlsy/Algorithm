#include <iostream>

#define MAX 100001

using namespace std;

long long A[MAX], B[MAX], C[MAX], P[MAX], visit[MAX];
long long sumA[MAX], sumB[MAX];

int main() {
    int N, M;
    cin>>N>>M;
    for(int i=1; i<=M; ++i){
        cin>>P[i];
    }

    for(int i=1; i<=N-1; ++i){
        cin>>A[i]>>B[i]>>C[i];
    }

    for(int i=1; i<=M-1; ++i){
        int a=P[i], b=P[i+1];
        if(a>b) swap(a,b);
        visit[a]++;
        visit[b]--;

    }

    long long visitSum=0;
    long long ret=0;
    for(int i=1; i<=N-1; ++i){
        visitSum+=visit[i];
        ret+=min(visitSum*A[i], visitSum*B[i]+C[i]);
    }

    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}