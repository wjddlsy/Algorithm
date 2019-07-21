#include <iostream>
#include <vector>

using namespace std;

const int mod=1000;
int N;
long long B;
vector<vector<long long>> multiple(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
    vector<vector<long long>> ret=vector<vector<long long>>(N, vector<long long>(N, 0));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            for(int k=0; k<N; ++k) {
                ret[i][j] = ( ret[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return ret;
}
vector<vector<long long>> pow(const vector<vector<long long>> &A, long long m ) {
    if(m==1) return A;
    if(m%2>0) return multiple(pow(A, m-1), A);
    vector<vector<long long>> half=pow(A, m/2);
    return multiple(half, half);
}
int main() {
    cin>>N>>B;
    vector<vector<long long>> matrix(vector<vector<long long>>(N, vector<long long>(N, 0)));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin>>matrix[i][j];
        }
    }

    vector<vector<long long>> ret=pow(matrix, B);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cout<<ret[i][j]%mod<<" ";
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}