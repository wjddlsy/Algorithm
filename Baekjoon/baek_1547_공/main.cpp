#include <iostream>

using namespace std;

int b[3]={0, 1, 2}; //내위치  0번컵 1, 1번컵 2, 3번컵 3
// 1번컵과 2번컵을 바꾸면 2번컵은 1번으로 1번컵은 2번으로
int main() {
    int M,x,y;
    cin>>M;
    while(M--){
        cin>>x>>y;
        swap(b[x-1], b[y-1]);
    }
    for(int i=0; i<3; ++i){
        if(b[i]==0)
            cout << i+1;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}