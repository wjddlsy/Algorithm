#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, B, C; // 시험장의 개수, 총 감독자, 부감독자
vector<int> A;
int main() {

    /* INPUT */
    cin>>N;
    for(int i=0; i<N; ++i){
        int in;
        cin>>in;
        A.push_back(in);
    }

    cin>>B>>C;

    long long cnt=0;
    for(int i=0; i<N; ++i){
        A[i]-=B;
        cnt++;
        if(A[i]>0){
            cnt+=ceil((double)A[i]/C);
        }
    }

    cout << cnt;


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}