#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
using namespace std;

bool isRight(const string& q, const string& n, int s, int b) {
    int ns=0, nb=0;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            if(n[i] == q[j]) {
                i==j? ns++ : nb++;
            }
        }
    }
    return s==ns && nb==b;
}
int main() {
    int N;
    cin>>N;
    vector<tuple<string, int, int>> games(N);
    for(auto && [q, s, b]:games) {
        cin >> q >> s>> b;
    }
    int ret = 0;
    for(int i=1; i<=9; ++i) {
        for(int j=1; j<=9; ++j) {
            for(int k=1; k<=9; ++k) {
                if(i==j || i==k || j==k)
                    continue;
                string n = to_string(i) + to_string(j) + to_string(k);
                bool flag = true;
                for(auto && [q, s, b]:games) {
                    if(!isRight(q, n, s, b)) {
                        flag = false;
                        break;
                    }
                }
                ret += flag;
            }
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}