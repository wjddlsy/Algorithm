#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> weightValue;
bool cache[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=3;
    while(t--) {
        int N, total = 0;
        cin>>N;
        for (int i = 0; i < N; ++i) {
            int value, cnt;
            cin >> value >> cnt;
            total += value*cnt;
            for(int j=1; cnt>0; j*=2) {
                int ix = min(j, cnt);
                weightValue.emplace_back(value*ix);
                cnt-=ix;
            }
        }
        memset(cache, 0, sizeof(cache));
        if(total%2!=0)
            cout<<0<<'\n';
        else {
            for (int i = 0; i < weightValue.size(); ++i) {
                for (int j = total; j >= weightValue[i]; --j) {
                    cache[j] += cache[j-weightValue[i]]+1;
                }
            }
            cout << 0 << '\n';

            //cout<<solve(total, 0, total)<<'\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}