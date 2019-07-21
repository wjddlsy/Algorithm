#include <iostream>
#include <vector>

using namespace std;

bool isCorrect(vector<int>& pieces) {
    for(int i=0; i<pieces.size()-1; ++i) {
        if(pieces[i]>pieces[i+1])
            return false;
    }
    return true;
}
int main() {
    vector<int> pieces(5);
    for(auto &piece:pieces) {
        cin>>piece;
    }
    while(true) {
        bool flag=true;
        for(int i=0; i<pieces.size()-1; ++i) {
            if(pieces[i]>pieces[i+1]) {
                swap(pieces[i], pieces[i + 1]);
                for(auto &piece:pieces) {
                    cout<<piece<<" ";
                }
                cout<<'\n';
                flag=false;
            }
        }
        if(flag)
            break;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}