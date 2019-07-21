#include <iostream>

using namespace std;

int A[100][100], B[100][100];


int multiple(int a, int b, int n){
    // A의 a행과 B의 b열을 곱할거시다
    int ret=0;
    for(int i=0; i<n; ++i){
        ret+=(A[a][i]*B[i][b]);
    }
    return ret;
}

int main() {
    int N, M, K;
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j)
            cin>>A[i][j];
    }
    cin >> M >> K;

    for(int i=0; i<M; ++i){
        for(int j=0; j<K; ++j)
            cin>>B[i][j];
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<K; ++j){
            cout << multiple(i, j, M) << " ";
        }
        cout << endl;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}