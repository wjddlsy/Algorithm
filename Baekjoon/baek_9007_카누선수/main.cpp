#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int k, n;
        cin>>k>>n;
        vector<int> weight[4];
        for(int i=0; i<4; ++i) {
            for(int j=0; j<n; ++j) {
                int w; cin>>w;
                weight[i].emplace_back(w);
            }
        }
        vector<int> sum[2];
        for(int x=0; x<2; ++x) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    sum[x].emplace_back(weight[x*2][i] + weight[x*2+1][j]);
                }
            }
        }
        for(int i=0; i<2; ++i) {
            sort(sum[i].begin(), sum[i].end());
        }
        int ret=987654321;
        for(int i=0; i<sum[0].size(); ++i) {
            int target=k-sum[0][i];
            auto lower=lower_bound(sum[1].begin(), sum[1].end(), target);

            int found=0;
            if(lower!=sum[1].end()) {
                found=sum[0][i]+(*lower);
                if(abs(k-found)<abs(k-ret))
                    ret=found;
                else if(abs(k-found)==abs(k-ret) && found<ret)
                    ret=found;
            }
            if(lower!=sum[1].begin()) {
                found=sum[0][i]+*(lower-1);
                if(abs(k-found)<abs(k-ret))
                    ret=found;
                else if(abs(k-found)==abs(k-ret) && found<ret)
                    ret=found;
            }
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}