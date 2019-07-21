#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int w, h;
char board[1000][1000];
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};

bool isRange(pair<int, int> here){
    if(here.first<0 || here.first>=h || here.second<0 || here.second>=w)
        return false;
    return true;
}

string bfs(pair<int, int> s, vector<pair<int, int>> fires){
    int discovered_s[1000][1000], discovered_f[1000][1000];
    memset(discovered_f, -1, sizeof(discovered_f)); memset(discovered_s, -1, sizeof(discovered_s));
    queue<pair<int, int>> qs, qf;
    qs.push(s);
    discovered_s[s.first][s.second]=0;
    for(auto fire:fires){
        qf.push(fire);
        discovered_f[fire.first][fire.second]=0;
    }

    while(!qf.empty()){
        pair<int, int> hf=qf.front();
        qf.pop();
        for(int i=0; i<4; ++i){
            pair<int, int> tf={hf.first+dx[i], hf.second+dy[i]};
            if(isRange(tf) && board[tf.first][tf.second]!='#' && discovered_f[tf.first][tf.second]==-1){
                qf.push(tf);
                discovered_f[tf.first][tf.second]=discovered_f[hf.first][hf.second]+1;
            }
        }
    }

    while(!qs.empty()) {
        pair<int, int> hs=qs.front();
        qs.pop();

        for(int i=0; i<4; ++i){
            pair<int, int> ts={hs.first+dx[i], hs.second+dy[i]};
            if(!isRange(ts))
                return to_string(discovered_s[hs.first][hs.second]+1);
            if(isRange(ts) && discovered_s[ts.first][ts.second]==-1){
                if(board[ts.first][ts.second]!='#' && (discovered_f[ts.first][ts.second]>discovered_s[hs.first][hs.second]+1 || discovered_f[ts.first][ts.second]==-1)) {
                    qs.push(ts);
                    discovered_s[ts.first][ts.second]=discovered_s[hs.first][hs.second]+1;

                }
            }

        }
    }

    return "IMPOSSIBLE";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>w>>h;
        vector<pair<int, int>> fires;
        pair<int, int> s;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin>>board[i][j];
                if(board[i][j]=='*')
                    fires.push_back({i, j});
                else if(board[i][j]=='@')
                    s={i, j};
            }
        }
        cout<<bfs(s, fires)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}