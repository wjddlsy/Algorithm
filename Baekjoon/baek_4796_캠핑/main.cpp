#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;

int main() {
    cin >> N >> L;
    vector<pair<double, double>> leaks(N);

    for (auto &leak:leaks) {
        double pos; cin>>pos;
        leak={pos-0.5, pos+0.5};
    }
    sort(leaks.begin(), leaks.end());
    int ret=0;
    double idx=0;
    for(int i=0; i<N; ++i) {
        if(idx<leaks[i].first) {
            int length=leaks[i].second-leaks[i].first;
            idx=leaks[i].first+(length/L)*L + (length%L==0?0:L);
            ret+=(length/L) + (length%L==0?0:1);
        }
        else if(idx<leaks[i].second) {
            int length=leaks[i].second-idx;
            idx=idx+(length/L)*L + (length%L==0?0:L);
            ret+=(length/L) + (length%L==0?0:1);
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}