#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

int N, Q;
vector<tuple<int, int, int>> bookings;
bool check[1000001];
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        bookings.clear();
        memset(check, 0, sizeof(check));
        cin>>N>>Q;
        for(int i=0; i<Q; ++i){
            int l, r;
            cin>>l>>r;
            bookings.push_back({r-l,l, r});
        }

        for(int i=0; i<Q; ++i){
            for(int j=i; j<Q; ++j){
                // 완전히 속함
                if(i<l && )
                // 부분적으로 속함

                // 안 속함
            }
        }

        sort(bookings.begin(), bookings.end());
        int ret=987654321;
        for(int i=0; i<Q; ++i){
            int a, l, r;
            tie(a, l, r)=bookings[i];
            int num=0;
            for(int j=l; j<=r; ++j){
                num+=!check[j];
                check[j]=true;
            }
            ret=min(ret, num);
        }
        cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}