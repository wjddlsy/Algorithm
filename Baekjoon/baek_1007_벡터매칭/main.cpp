#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        vector<pair<int, int>> points;
        double ret=1e9;
        for(int i=0; i<N; ++i) {
            int x, y;
            cin>>x>>y;
            points.emplace_back(x, y);
        }
        vector<int> pick(N, 1);
        for(int i=0; i<N/2; ++i) {
            pick[i]=0;
        }

        do {
            long long x=0, y=0;
            for(int i=0; i<N; ++i) {
                if(pick[i]) {
                    x+=points[i].first;
                    y+=points[i].second;
                } else {
                    x-=points[i].first;
                    y-=points[i].second;
                }
            }
            ret=min(ret, sqrt(x*x+y*y));
        } while(next_permutation(pick.begin(), pick.end()));
        printf("%.8f\n", ret);
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}