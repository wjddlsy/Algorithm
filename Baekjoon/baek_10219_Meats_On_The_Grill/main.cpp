#include <iostream>

using namespace std;

int H, W;
char board[11][11];
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>H>>W;
        for(int i=0; i<H; ++i){
            for(int j=0; j<W; ++j){
                cin>>board[i][j];
            }
        }

        for(int i=0; i<H; ++i){
            for(int j=W-1; j>=0; --j)
                cout << board[i][j];
            cout << endl;
        }
    }

    return 0;
}