#include <iostream>
using namespace std;

int wall1[1000][1000], wall2[1000][1000];

int wall[1000];
int main() {
    int N, M, H;
    cin>>N>>M>>H;
    //가로벽 정보
    for(int i=0; i<N+1; ++i){
        for(int j=0; j<M; ++j) {
            cin >> wall1[i][j];
        }
    }

    //세로벽 정보
    for(int i=0; i<N; ++i){
        for(int j=0; j<M+1; ++j) {
            cin >> wall2[i][j];
        }
    }


    for(int i=0; i<H; ++i){
        for(int j=0; j<M ++j){
            for(int k=0; k<N; ++k){

            }
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}