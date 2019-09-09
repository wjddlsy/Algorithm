#include <iostream>
#include <string>
#include <vector>

using namespace std;


void rotate(vector<vector<int>> &key) {
    vector<vector<int>> tmp = key;
    for(int i=0; i<key.size(); ++i) {
        for(int j=0; j<key.size(); ++j) {
            key[j][key.size()-1-i]=tmp[i][j];
        }
    }
}

bool canOpen(vector<vector<int>> &key, vector<vector<int>> &lock, int x, int y, int require) {
    for(int lock_i=0; lock_i<lock.size(); ++lock_i) {
        for(int lock_j=0; lock_j<lock.size(); ++lock_j) {
            int cnt=0;
            bool flag=true;
            for(int i=0; i<key.size(); ++i) {
                for(int j=0; j<key.size(); ++j) {
                    if(x+i>=key.size() || y+j>=key.size() || lock_i+i >=lock.size() || lock_j + j >=lock.size())
                        break;
                    if(key[x+i][y+j] == 1 && lock[lock_i+i][lock_j+j] == 1) {
                        flag = false;
                        break;
                    }
                    if(key[x+i][y+j]==1 && lock[lock_i+i][lock_j+j]==0)
                        cnt++;
                }
            }
            if(flag && require == cnt)
                return true;
        }
    }

    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int require=0;
    for(int i=0; i<lock.size(); ++i) {
        for(int j=0; j<lock.size(); ++j) {
            if(lock[i][j]==0)
                require++;
        }
    }
    for(int i=0; i<4; ++i) {
        rotate(key);
        for(int x=0; x<key.size(); ++x) {
            for(int y=0; y<key.size(); ++y) {
                if(canOpen(key, lock, x, y, require))
                    return true;
            }
        }
    }
    return false;
}
int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<int>> key(m), lock(n);
    for(int i=0; i<m; ++i) {
        for(int j=0; j<m; ++j) {
            int in; cin>>in;
            key[i].emplace_back(in);
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            int in; cin>>in;
            lock[i].emplace_back(in);
        }
    }
    cout<<solution(key, lock);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}