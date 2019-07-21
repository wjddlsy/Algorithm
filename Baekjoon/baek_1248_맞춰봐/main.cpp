#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visited;
int N;
string sign;
void solve(int pos, int status, vector<int>& perm) {
    if (pos == N) {
        for (auto &p:perm) {
            cout << p << " ";
        }
        return;
    }
    if(sign[pos*N-(N-1)*N/2]=='+') {

    }
}
int main() {
    cin>>N>>sign;
    visited=vector<vector<bool>>(N, vector<bool>(22, 0));
    // -10~10

    std::cout << "Hello, World!" << std::endl;
    return 0;
}