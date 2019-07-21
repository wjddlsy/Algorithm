#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R, C, K;
int board[300][300];
int check[300][300];

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        cin>>R>>C>>K;
        vector<vector<pair<int, int>>> sub(R);
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                cin>>board[i][j];
            }
        }

        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                int cl=987654321, cr=-987654321;
                for(int k=j; k<C; ++k){
                    cl=max(cl, board[i][k]);
                    cr=max(cr, board[i][k]);
                    if(cr-cl<=K){

                    }
                    else {

                    }
                }
            }
        }

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}