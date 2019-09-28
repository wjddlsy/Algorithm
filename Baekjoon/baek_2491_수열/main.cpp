#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> arr(N);
    for(auto &a:arr) {
        cin>>a;
    }
    int is = 0, ds = 0, ti=0, td=0;
    int iindex = 0, dindex = 10;

    for(auto &a:arr) {
        if(iindex<=a) {
            ti++;
            iindex = a;
        } else {
            is = max(is, ti);
            ti = 1;
            iindex = a;
        }
        if(dindex>=a) {
            td++;
            dindex = a;
        } else {
            ds = max(ds, td);
            td = 1;
            dindex = a;
        }
    }
    is = max(is, ti);
    ds = max(ds, td);
    cout << max(is, ds) ;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}