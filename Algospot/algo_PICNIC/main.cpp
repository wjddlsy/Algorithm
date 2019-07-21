#include <iostream>
#include <string.h>
using namespace std;

int n;
bool isFriend[10][10];

int countPairings(bool taken[10]){
    // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다
    int firstFree = -1;
    for(int i=0; i<n; ++i){
        if(!taken[i]){
            firstFree=i;
            break;
        }
    }

    // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
    if(firstFree==-1) return 1;
    int ret=0;

    // 이 학생과 짝을 지을 학생 결정
    for(int pairWith=firstFree+1; pairWith<n; ++pairWith){
        if(!taken[pairWith] && isFriend[firstFree][pairWith]){
            taken[firstFree]=taken[pairWith] =true;
            ret+=countPairings(taken);
            taken[firstFree]=taken[pairWith]=false;
        }
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin>>c;
    while(c--) {
        int m, a, b;
        cin >> n >> m;
        memset(isFriend, 0, sizeof(isFriend));
        for(int i=0; i<m; ++i){
            cin>>a>>b;
            isFriend[a][b]=true;
            isFriend[b][a]=true;
        }

        bool taken[10]={0,};
        cout << countPairings(taken) <<endl;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}