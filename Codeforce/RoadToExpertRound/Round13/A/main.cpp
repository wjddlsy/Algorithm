#include <iostream>
#include <vector>
using namespace std;

int main() {
    string cand1, cand2;
    cin>>cand1>>cand2;
    cout<<cand1<<" "<<cand2<<'\n';
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        string murdered;
        cin>>murdered;
        if(cand1==murdered) {
            cand1=cand2;
        }
        cin>>cand2;
        cout<<cand1<<" "<<cand2<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}