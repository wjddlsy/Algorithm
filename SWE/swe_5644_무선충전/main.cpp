#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int M, A, reta, retb;
vector<vector<vector<pair<int, int>>>> board;

int dx[]={0, 0, 1, 0, -1}, dy[]={0, -1, 0, 1, 0};

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

bool isRange(int x, int y){
    if(x<=10 && y<=10 && x>0 && y>0)
        return true;
    return false;
}
void make_range(int x, int y, int c, int p, int n){
    for(int start_x=x-c; start_x<=x+c; ++start_x){
        for(int start_y=y-c; start_y<=y+c; ++start_y) {
            if(dist(x, y, start_x, start_y)<=c)
                if(isRange(start_x, start_y))
                    board[start_y][start_x].push_back({p,n});
        }
    }
}

void simulate(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {

    for (int sec = 0; sec <= M; ++sec) {

        int xa, xb, ya, yb;
        tie(xa, ya) = a[sec];
        tie(xb, yb) = b[sec];

        sort(board[ya][xa].begin(), board[ya][xa].end(), greater<pair<int,int>>());
        sort(board[yb][xb].begin(), board[yb][xb].end(), greater<pair<int,int>>());
        // 둘다 같은 거 써야할 때.

        if (board[ya][xa].size() == 1 && board[yb][xb].size() == 1) {
            if (board[ya][xa][0].second == board[yb][xb][0].second) {
                reta += board[ya][xa][0].first / 2;
                retb += board[yb][xb][0].first / 2;
            } else {
                reta += board[ya][xa][0].first;
                retb += board[yb][xb][0].first;
            }
        } else if (board[ya][xa].size() == 1 && board[yb][xb].size() > 1) {
            if (board[ya][xa][0].second == board[yb][xb][0].second) {
                reta += board[ya][xa][0].first;
                retb += board[yb][xb][1].first;
            } else {
                reta += board[ya][xa][0].first;
                retb += board[yb][xb][0].first;
            }

        } else if (board[ya][xa].size() > 1 && board[yb][xb].size() == 1) {
            if (board[ya][xa][0].second == board[yb][xb][0].second) {
                reta += board[ya][xa][1].first;
                retb += board[yb][xb][0].first;
            } else {
                reta += board[ya][xa][0].first;
                retb += board[yb][xb][0].first;
            }
        } else if (board[ya][xa].size() > 1 && board[yb][xb].size() > 1) {
            if (board[ya][xa][0].second == board[yb][xb][0].second) {
                reta += board[ya][xa][0].first;
                retb += max(board[yb][xb][1].first, board[ya][xa][1].first);
            } else {
                reta += board[ya][xa][0].first;
                retb += board[yb][xb][0].first;
            }
        } else if (board[ya][xa].empty() && board[yb][xb].empty());
        else if (board[ya][xa].empty())
            retb += board[yb][xb][0].first;
        else if (board[yb][xb].empty())
            reta += board[ya][xa][0].first;

    }
}
int main() {
    int t;
    cin>>t;
    for(int nt=1; nt<=t; ++nt){
        cin>>M>>A;
        vector<pair<int,int>> a, b; //a,b 초기화
        board=vector<vector<vector<pair<int,int>>>>(11, vector<vector<pair<int,int>>>(11)); // 벡터 초기화
        reta=0; retb=0; // 결과 초기화
        int xa=1, ya=1, xb=10, yb=10; // 좌표 초기화
        a.push_back({xa, ya});
        b.push_back({xb, yb});

        for(int i=1; i<=M; ++i){
            int in;
            cin >>in;
            xa+=dx[in]; ya+=dy[in];
            a.push_back({xa, ya});
        }

        for(int i=1; i<=M; ++i){
            int in;
            cin >>in;
            xb+=dx[in]; yb+=dy[in];
            b.push_back({xb, yb});
        }

        for(int i=0; i<A; ++i){
            int x, y, c, p;
            cin>>x>>y>>c>>p;
            make_range(x, y, c, p, i);
        }

        simulate(a, b);
        cout <<"#"<<nt<<" "<<reta+retb << endl;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}