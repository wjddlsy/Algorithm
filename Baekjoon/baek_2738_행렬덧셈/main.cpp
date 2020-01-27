#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int A[101][101];

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> A[i][j];
        }
    }

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            int value;
            cin >> value;
            cout << A[i][j] + value << " ";
        }
        cout << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
