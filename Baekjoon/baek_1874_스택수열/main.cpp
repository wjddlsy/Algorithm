#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, in;
    cin>>n;
    vector<int> list;
    vector<char> ret;
    int max=0;
    int init=1;
    for(int i=0; i<n; ++i){
        cin>>in;
        if(in>max) {
            for(int j=init; j<=in; ++j){
                list.push_back(j);
                ret.push_back('+');
            }
            list.pop_back();
            ret.push_back('-');
            init=in+1;
            max=in;
        }
        else {
            if(list.back()!=in) {
                cout << "NO";
                return 0;
            }
            else {
                ret.push_back('-');
                list.pop_back();
            }
        }
    }


    for(int i=0; i<ret.size(); ++i){
        cout<<ret[i]<<'\n';
    }


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}