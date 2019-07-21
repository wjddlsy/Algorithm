#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <limits>
using namespace std;

int cache[101][101];
int n, m, A[100], B[100];

const long long NEGINF=numeric_limits<long long>::min();

int jlis(int indexA, int indexB){
    int& ret=cache[indexA+1][indexB+1];
    if(ret!=-1) return ret;

    ret=0;
    long long a=(indexA==-1 ? NEGINF : A[indexA]);
    long long b=(indexB==-1 ? NEGINF : B[indexB]);
    long long maxElement = max(a,b);
    for(int nextA=indexA+1; nextA<n; ++nextA){
        if(maxElement<A[nextA])
            ret=max(ret, jlis(nextA, indexB)+1);
    }

    for(int nextB=indexB+1; nextB<m; ++nextB){
        if(maxElement<B[nextB])
            ret=max(ret, jlis(indexA, nextB)+1);
    }
    return ret;
}

int main() {
    int c;
    cin>>c;
    while(c--){
        cin>>n>>m;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; ++i){
            cin>>A[i];
        }
        for(int i=0; i<m; ++i){
            cin>>B[i];
        }

        cout << jlis(-1,-1) << endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}