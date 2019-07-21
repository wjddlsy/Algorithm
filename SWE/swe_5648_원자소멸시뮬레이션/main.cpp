#include <iostream>
using namespace std;

int atom[1000][4]; // x, y, dir, power
int visit[4005][4005];  //얜모지
int collided[4005][4005];
int dx[]={0, 0, -1,1}, dy[]={1,-1,0,0};

bool isRange(int x, int y) {
    if(x>=0 && x<=4000 && y>=0 && y<=4000)
        return true;
    return false;
}

void removeAtom(int n, int* pnSize){
    int nLastIndex = (*pnSize)-1;
    // 맨 끝의 원소를 제거될 원소에 갖다 넣음
    atom[n][0]=atom[nLastIndex][0];
    atom[n][1]=atom[nLastIndex][1];
    atom[n][2]=atom[nLastIndex][2];
    atom[n][3]=atom[nLastIndex][3];
    (*pnSize)--; // 남은 원소 개수 줄이기
}


// 방출된 에너지 반환
int simulate(int n) {

    memset(visit, 0, sizeof(visit));
    memset(collided, 0, sizeof(visit));
    int nRest = n; // 남은 원자가 몇 개 인지
    int ans = 0; // 에너지 방출량

    // 2배로 변경
    for (int i = 0; i < nRest; ++i) {
        atom[i][0] *= 2;
        atom[i][1] *= 2;
        // increase visit
        visit[atom[i][0]][atom[i][1]]++;

    }

    // move
    int max_t = 4002;
    for (int t = 0; t < max_t; ++t) {
        // move
        for (int i = 0; i < nRest; ++i) {
            int &x = atom[i][0];
            int &y = atom[i][1];
            int d = atom[i][2];
            visit[x][y]--;
            x += dx[d];
            y += dy[d];

            if (!isRange(x, y)) {
                removeAtom(i, &nRest); // i번째 원소를 제거하겠다.
                i--;
            } else {
                visit[x][y]++;
                if (visit[x][y] >= 2) collided[x][y] = true; // 여기서는 true로만 체크하고 밑에서 처리함.

            }
        }

        // check collision

        // 충돌한 원소가 잇을까요
        // 좌표평면을 돌면서 찾는게 아니고 원소배열을 유지하면서 원소를 순회
        for (int i = 0; i < nRest; ++i) {
            int x = atom[i][0];
            int y = atom[i][1];
            if (collided[x][y]) { // 충돌했다.
                // 둘다 제거
                if (visit[x][y] == 1) collided[x][y] = false; // 원소가 하나라면 마지막꺼지우고 충돌 false로 변경
                visit[x][y]--;
                ans += atom[i][3];

                //충돌된 원자 삭제
                removeAtom(i, &nRest);
                i--; // 나를 지우면 맨 뒤에 애가 나한ㅇ테 오니까 그거 다시 검사!... 후
            }
        }
        if(nRest==0) break;
    }
    return ans;

}
int main(){
    int t, n;
    cin>>t;
    for(int nt=1; nt<=t; ++nt){
        cin>>n;
        for(int i=0; i<n; ++i){
            cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
            atom[i][0]+=1000;
            atom[i][1]+=1000;
        }


        cout << "#"<< nt << " " << simulate(n) << endl;
    }
}