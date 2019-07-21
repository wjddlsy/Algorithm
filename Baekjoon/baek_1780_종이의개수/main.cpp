#include <iostream>
#include <vector>
using namespace std;

int ret[3]={0,0,0};
int areSame(vector<vector<int>>& v, int idx_y, int idx_x, int n){

    int tmp=v[idx_y][idx_x];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(tmp!=v[idx_y+i][idx_x+j])
                return -2;
            tmp=v[idx_y+i][idx_x+j];

        }
    }

    return tmp;
}

void cut(vector<vector<int>>& v, int idx_y, int idx_x, int n){
    int t=areSame(v, idx_y, idx_x, n);
    if(t!=-2) {
        ret[t+1]++;
        return;
    }

    n/=3;

    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cut(v, idx_y+n*i, idx_x+n*j, n);
        }
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cin>>v[i][j];
    }

    cut(v, 0, 0, n);

    for(int i=0; i<3; ++i){
        cout << ret[i]<<'\n';
    }

    return 0;
}