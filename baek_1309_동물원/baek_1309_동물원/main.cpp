

#include <iostream>

//0, 1, 2 왜?
int cage[3][100001];
int N;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin >> N;
    cage[0][1]=cage[1][1]=cage[2][1]=1;
    
    for (int i=2; i<=N; ++i){
        cage[0][i]=(cage[0][i-1]+cage[1][i-1]+cage[2][i-1])%9901;
        cage[1][i]=(cage[0][i-1]+cage[2][i-1])%9901;
        cage[2][i]=(cage[0][i-1]+cage[1][i-1])%9901;
    }
    
    std::cout << (cage[0][N]+cage[1][N]+cage[2][N]) % 9901;
    
    return 0;
}
