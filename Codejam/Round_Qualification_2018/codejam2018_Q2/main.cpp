#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        int N;
        cin>>N;
        vector<int> even, odd;
        for(int i=0; i<N; ++i){
            int a;
            cin>>a;
            if(i%2==1)
                odd.push_back(a);
            else
                even.push_back(a);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        string ret="OK";

        vector<int> all(N);
        for(int i=0; i<N; ++i){
            if(i%2==1)
                all[i]=odd[i/2];
            else
                all[i]=even[i/2];
        }
        for(int i=0; i<N-1; ++i){
            if(all[i]>all[i+1]) {
                ret = to_string(i);
                break;
            }
        }
        cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}